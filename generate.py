#!/usr/bin/env python3

# Copyright (c) 2024 Nikita Tsarev
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


import yaml
import contextlib
import sys
import re
import io
import copy


def define_to_enumerator_name(name):
    return "e" + "".join([i.title() for i in name.split("_")])


def to_title_case(name):
    return "".join([i.title() for i in name.split("_")])


def to_camel_case(name):
    name = to_title_case(name)
    name = name[0].lower() + name[1:]
    return name


def cpp_type_forward(type, enum, counted_by=None):
    if counted_by:
        type = type.removesuffix("*")

    if type.startswith("GLFW") and type.endswith("*"):
        cpp_type = type.removeprefix("GLFW").removesuffix("*").strip().title()
        forward = f"{cpp_type}{{NAME}}"
        backward = f"NAME.handle()"
    elif enum == "bool":
        cpp_type = "bool"
        forward = "NAME == GLFW_TRUE"
        backward = "NAME ? GLFW_TRUE : GLFW_FALSE"
    elif enum is not None:
        cpp_type = to_title_case(enum)
        forward = f"static_cast<{cpp_type}>(NAME)"
        backward = f"static_cast<int>(NAME)"
    elif type == "const char*":
        cpp_type = "std::string_view"
        forward = f"std::string_view{{NAME}}"
        backward = f"std::string{{NAME}}.c_str()"
    else:
        cpp_type = type
        forward = "NAME"
        backward = "NAME"

    if counted_by:
        if not cpp_type.startswith("const"):
            cpp_type = f"const {cpp_type}"
        cpp_type = f"std::span<{cpp_type}>"
        forward = f"{cpp_type}{{ {forward}, static_cast<std::size_t>({counted_by}) }}"
        backward = "NAME.data()"

    return cpp_type, forward, backward


def cpp_params(parameters):
    result = []
    count_for = None
    counted_by = None
    for i in parameters:
        name = i["name"]
        type = i["type"]
        enum = i.get("enum")
        out = i.get("out", False)
        if i.get("count_for") is not None:
            count_for = i.get("count_for")
            counted_by = name
            result.append({
                "name": name,
                "cpp_type": None,
                "c_type": type,
                "forward": None,
                "backward": f"{count_for}.size()",
                "out": out,
                "count_for": count_for,
            })
            continue

        cpp_type, forward, backward = cpp_type_forward(type, enum, counted_by if count_for == name else None)

        result.append({
            "name": name,
            "cpp_type": cpp_type,
            "c_type": type,
            "forward": forward,
            "backward": backward,
            "out": out,
            "counted_by": counted_by,
        })

    return result


class Generator:
    def __init__(self, api, template):
        self.api = api
        self.template = template
        self.indent = 0
        self.output = io.StringIO()

    def line(self, *args, **kwargs):
        print("    " * self.indent, end="", file=self.output)
        print(*args, **kwargs, file=self.output)

    def skip(self):
        print(file=self.output)

    @contextlib.contextmanager
    def block(self, begin = "{", end = "}"):
        self.line(begin)
        self.indent += 1
        try:
            yield
        finally:
            self.indent -= 1
            self.line(end)

    def generate_enum(self, name):
        data = self.api["enums"][name]
        prefix = data.get("prefix", "")
        suffix = data.get("suffix", "")
        enum_name = to_title_case(name)
        with self.block(f"GLFW_HPP_EXPORT enum class {enum_name} {{", "};"):
            for value in data["values"]:
                enumerator_name = define_to_enumerator_name(value.removeprefix(prefix).removesuffix(suffix))
                self.line(f"{enumerator_name} = {value},")

    def generate_enums(self):
        for name in self.api["enums"]:
            if name not in ("const", "joystick"):
                self.generate_enum(name)

    def generate_c_api(self):
        for type_str in self.api["types"]:
            self.line(f"export using ::{type_str};")
        for function in self.api["functions"]:
            name = function["name"]
            if function.get("features") == "vulkan":
                self.line("#ifdef VK_VERSION_1_0")
            self.line(f"export using ::{name};")
            if function.get("features") == "vulkan":
                self.line("#endif // VK_VERSION_1_0")
        for define_str, value in self.api["defines"].items():
            self.line(f"#undef {define_str}")
            self.line(f"export constexpr int {define_str} = {value};")

    def generate_hint_defs(self, kind):
        self.indent += 1
        for raw_name, raw_type in self.api["hints"][f"{kind}_hint"].items():
            if raw_type in ("bool", "int"):
                type = raw_type
            elif raw_type == "string":
                type = "std::string"
            else:
                type = to_title_case(raw_type)
            name = to_camel_case(raw_name.removeprefix("GLFW_"))
            self.line(f"std::optional<{type}> {name};")
        self.indent -= 1

    def generate_hints_apply(self, kind):
        self.indent += 1
        for raw_name, raw_type in self.api["hints"][f"{kind}_hint"].items():
            name = to_camel_case(raw_name.removeprefix("GLFW_"))
            with self.block(f"if (info.{name}) {{"):
                if raw_type == "string":
                    self.line(f"::glfw{kind.title()}HintString({raw_name}, info.{name}.value().c_str());")
                else:
                    self.line(f"::glfw{kind.title()}Hint({raw_name}, static_cast<int>(info.{name}.value()));")
                self.line("checkError();")
            self.skip()
        self.indent -= 1

    def generate_window_attributes(self):
        self.indent += 1
        for attrib, props in self.api["window_attribs"].items():
            readonly = props.get("readonly", False)
            name = to_title_case(attrib.removeprefix("GLFW_"))
            with self.block(f"GLFW_HPP_NODISCARD bool is{name}() const {{"):
                self.line(f"return getAttrib(WindowAttrib::e{name});")
            self.skip()
            if not readonly:
                with self.block(f"void set{name}(bool value) const {{"):
                    self.line(f"setAttrib(WindowAttrib::e{name}, value);")
                self.skip()
        self.indent -= 1

    def get_window_event_lambda_type(self, event):
        params = cpp_params(self.api["window_events"][event]["parameters"])
        param_types = [i for i in [i["cpp_type"] for i in params] if i is not None]
        return f"std::function<void({', '.join(param_types)})>"

    def generate_window_peer(self):
        self.indent += 2
        for event in self.api["window_events"]:
            type = self.get_window_event_lambda_type(event)
            self.line(f"{type} handle{event};")
        self.indent -= 2

    def generate_window_callback_setup(self):
        self.indent += 2
        for event, info in self.api["window_events"].items():
            if event == "Drop":
                continue
            type_name = f"GLFW{event.lower()}fun"
            params = cpp_params(info["parameters"])
            c_types = ["GLFWwindow* window"] + [i["c_type"] + " " + i["name"] for i in params]
            lambda_params = ", ".join(c_types)
            with self.block(f"::glfwSet{event}Callback(m_window, []({lambda_params}) {{", "});"):
                self.line("auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));")
                with self.block(f"if (peer && peer->handle{event}) {{"):
                    forward = [i["forward"].replace("NAME", i["name"]) for i in params if i["forward"] is not None]
                    self.line(f"peer->handle{event}({', '.join(forward)});")
            self.skip()
        self.indent -= 2

    def generate_window_handler_setters(self):
        self.indent += 1
        for event in self.api["window_events"]:
            type = self.get_window_event_lambda_type(event)
            with self.block(f"void set{event}Handler({type} handler) const {{"):
                self.line(f"getPeer()->handle{event} = std::move(handler);")
            self.skip()
        self.indent -= 1

    def generate_methods(self, kind):
        self.indent += 1
        for function in self.api["functions"]:
            receiver = function.get("receiver")
            if receiver != kind:
                continue
            name = function["name"]
            if name in ("glfwDestroyWindow", "glfwSetGammaRamp", "glfwGetGammaRamp", "glfwSetCursor"):
                continue
            return_type = function["return"]["type"]
            return_enum = function["return"].get("enum")
            params = cpp_params(function["parameters"][1:])
            in_params = [i for i in params if not i["out"]]
            out_params = [i for i in params if i["out"]]
            method_name = name.removeprefix("glfw").replace(kind.title(), "")
            if "Callback" in method_name or "UserPointer" in method_name:
                continue
            if not in_params:
                method_name = method_name.removeprefix("Get")
            if method_name.endswith("Pos"):
                method_name += "ition"
            method_name = method_name[0].lower() + method_name[1:]

            return_counted_by = None
            for i in out_params:
                if i.get("count_for") == "return":
                    return_counted_by = i.get("name")
                    break
            return_cpp_type, return_forward, return_backward = cpp_type_forward(return_type, return_enum, return_counted_by)

            nodiscard = ""
            if return_type != "void":
                nodiscard = "GLFW_HPP_NODISCARD "

            if out_params:
                return_cpp_type = "auto"

            params_str = ", ".join([i["cpp_type"] + " " + i["name"] for i in params if i["cpp_type"] is not None and not i["out"]])
            # self.line("// " + str(params))
            with self.block(f"{nodiscard}{return_cpp_type} {method_name}({params_str}) const {{"):
                if out_params:
                    out_struct = "; ".join([i["c_type"].removesuffix("*") + " " + i["name"] for i in out_params if not i.get("count_for")])
                    if out_struct:
                        self.line(f"struct {{ {out_struct}; }} result{{}};")
                    for i in out_params:
                        count_for = i.get("count_for")
                        if count_for:
                            self.line(f"{i['c_type'].removesuffix('*')} {i['name']};")
                args = ["m_" + kind]
                for i in params:
                    if i["out"]:
                        count_for = i.get("count_for")
                        if count_for:
                            args.append(f"&{i['name']}")
                        else:
                            args.append(i["backward"].replace("NAME", f"&result.{i['name']}"))
                    else:
                        args.append(i["backward"].replace("NAME", i["name"]))
                args_str = ", ".join(args)
                if return_type == "void":
                    self.line(f"::{name}({args_str});")
                else:
                    self.line(f"auto returnValue = ::{name}({args_str});")
                self.line("checkError();")
                if return_type != "void":
                    self.line(f"return {return_forward.replace('NAME', 'returnValue')};")
                elif out_params:
                    self.line("return result;")
            self.skip()
        self.indent -= 1

    def generate(self):
        in_generated = False
        for line in map(str.rstrip, self.template.split("\n")[:-1]):
            if line.startswith("// !"):
                cmd = line.removeprefix("// !")
                if cmd == "begin_generated":
                    in_generated = True
                    continue
                elif cmd == "end_generated":
                    in_generated = False
                    continue

                print(f"// !begin_generated", file=self.output)
                print(line, file=self.output)

                if cmd == "generate_enums":
                    self.generate_enums()
                elif cmd == "generate_c_api":
                    self.generate_c_api()
                elif cmd == "generate_init_hint_defs":
                    self.generate_hint_defs("init")
                elif cmd == "generate_window_hint_defs":
                    self.generate_hint_defs("window")
                elif cmd == "generate_apply_init_hints":
                    self.generate_hints_apply("init")
                elif cmd == "generate_apply_window_hints":
                    self.generate_hints_apply("window")
                elif cmd == "generate_window_peer":
                    self.generate_window_peer()
                elif cmd == "generate_window_callback_setup":
                    self.generate_window_callback_setup()
                elif cmd == "generate_window_methods":
                    self.generate_methods("window")
                    self.generate_window_handler_setters()
                    self.generate_window_attributes()
                elif cmd == "generate_monitor_methods":
                    self.generate_methods("monitor")

                print(f"// !end_generated", file=self.output)
            elif not in_generated:
                print(line, file=self.output)

def main():
    with open("api.yaml") as api_file:
        api = yaml.load(api_file, yaml.Loader)
    with open("./include/glfw-hpp/glfw.hpp", "r") as template_file:
        template = template_file.read()
    gen = Generator(api, template)
    gen.generate()
    with open("./include/glfw-hpp/glfw.hpp", "w") as output_file:
        output_file.write(gen.output.getvalue())



if __name__ == "__main__":
    main()