/*
Copyright (c) 2024 Nikita Tsarev

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef GLFW_HPP_INCLUDED
#define GLFW_HPP_INCLUDED

#define GLFW_HPP_NODISCARD [[nodiscard]]

#ifndef GLFW_HPP_NO_INCLUDE
#include <GLFW/glfw3.h>
#endif

#include <exception>
#include <optional>
#include <vector>
#include <string>
#include <string_view>
#include <functional>
#include <span>
#include <cstdint>

#ifndef GLFW_HPP_NAMESPACE
#define GLFW_HPP_NAMESPACE glfw
#endif

#ifdef GLFW_HPP_MODULE
#define GLFW_HPP_EXPORT export
#define GLFW_HPP_API export
#define GLFW_HPP_API_NODISCARD export [[nodiscard]]
#else
#define GLFW_HPP_EXPORT
#define GLFW_HPP_API inline
#define GLFW_HPP_API_NODISCARD [[nodiscard]] inline
#endif

#ifndef GLFW_RELEASE_BEHAVIOR_ANY
#define GLFW_RELEASE_BEHAVIOR_ANY GLFW_ANY_RELEASE_BEHAVIOR
#endif

#ifndef GLFW_PLATFORM_ANY
#define GLFW_PLATFORM_ANY GLFW_ANY_PLATFORM
#endif

#ifdef GLFW_HPP_MODULE
#ifndef GLFW_HPP_MODULE_NAME
#define GLFW_HPP_MODULE_NAME glfw;
#endif

export module GLFW_HPP_MODULE_NAME;
#endif

#ifndef GLFW_HPP_DISABLE_HPP

namespace GLFW_HPP_NAMESPACE {
// !begin_generated
// !generate_enums
GLFW_HPP_EXPORT enum class VersionComponent {
    eMajor = GLFW_VERSION_MAJOR,
    eMinor = GLFW_VERSION_MINOR,
    eRevision = GLFW_VERSION_REVISION,
};
GLFW_HPP_EXPORT enum class Action {
    eRelease = GLFW_RELEASE,
    ePress = GLFW_PRESS,
    eRepeat = GLFW_REPEAT,
};
GLFW_HPP_EXPORT enum class HatState {
    eCentered = GLFW_HAT_CENTERED,
    eUp = GLFW_HAT_UP,
    eRight = GLFW_HAT_RIGHT,
    eDown = GLFW_HAT_DOWN,
    eLeft = GLFW_HAT_LEFT,
    eRightUp = GLFW_HAT_RIGHT_UP,
    eRightDown = GLFW_HAT_RIGHT_DOWN,
    eLeftUp = GLFW_HAT_LEFT_UP,
    eLeftDown = GLFW_HAT_LEFT_DOWN,
};
GLFW_HPP_EXPORT enum class Key {
    eUnknown = GLFW_KEY_UNKNOWN,
    eSpace = GLFW_KEY_SPACE,
    eApostrophe = GLFW_KEY_APOSTROPHE,
    eComma = GLFW_KEY_COMMA,
    eMinus = GLFW_KEY_MINUS,
    ePeriod = GLFW_KEY_PERIOD,
    eSlash = GLFW_KEY_SLASH,
    e0 = GLFW_KEY_0,
    e1 = GLFW_KEY_1,
    e2 = GLFW_KEY_2,
    e3 = GLFW_KEY_3,
    e4 = GLFW_KEY_4,
    e5 = GLFW_KEY_5,
    e6 = GLFW_KEY_6,
    e7 = GLFW_KEY_7,
    e8 = GLFW_KEY_8,
    e9 = GLFW_KEY_9,
    eSemicolon = GLFW_KEY_SEMICOLON,
    eEqual = GLFW_KEY_EQUAL,
    eA = GLFW_KEY_A,
    eB = GLFW_KEY_B,
    eC = GLFW_KEY_C,
    eD = GLFW_KEY_D,
    eE = GLFW_KEY_E,
    eF = GLFW_KEY_F,
    eG = GLFW_KEY_G,
    eH = GLFW_KEY_H,
    eI = GLFW_KEY_I,
    eJ = GLFW_KEY_J,
    eK = GLFW_KEY_K,
    eL = GLFW_KEY_L,
    eM = GLFW_KEY_M,
    eN = GLFW_KEY_N,
    eO = GLFW_KEY_O,
    eP = GLFW_KEY_P,
    eQ = GLFW_KEY_Q,
    eR = GLFW_KEY_R,
    eS = GLFW_KEY_S,
    eT = GLFW_KEY_T,
    eU = GLFW_KEY_U,
    eV = GLFW_KEY_V,
    eW = GLFW_KEY_W,
    eX = GLFW_KEY_X,
    eY = GLFW_KEY_Y,
    eZ = GLFW_KEY_Z,
    eLeftBracket = GLFW_KEY_LEFT_BRACKET,
    eBackslash = GLFW_KEY_BACKSLASH,
    eRightBracket = GLFW_KEY_RIGHT_BRACKET,
    eGraveAccent = GLFW_KEY_GRAVE_ACCENT,
    eWorld1 = GLFW_KEY_WORLD_1,
    eWorld2 = GLFW_KEY_WORLD_2,
    eEscape = GLFW_KEY_ESCAPE,
    eEnter = GLFW_KEY_ENTER,
    eTab = GLFW_KEY_TAB,
    eBackspace = GLFW_KEY_BACKSPACE,
    eInsert = GLFW_KEY_INSERT,
    eDelete = GLFW_KEY_DELETE,
    eRight = GLFW_KEY_RIGHT,
    eLeft = GLFW_KEY_LEFT,
    eDown = GLFW_KEY_DOWN,
    eUp = GLFW_KEY_UP,
    ePageUp = GLFW_KEY_PAGE_UP,
    ePageDown = GLFW_KEY_PAGE_DOWN,
    eHome = GLFW_KEY_HOME,
    eEnd = GLFW_KEY_END,
    eCapsLock = GLFW_KEY_CAPS_LOCK,
    eScrollLock = GLFW_KEY_SCROLL_LOCK,
    eNumLock = GLFW_KEY_NUM_LOCK,
    ePrintScreen = GLFW_KEY_PRINT_SCREEN,
    ePause = GLFW_KEY_PAUSE,
    eF1 = GLFW_KEY_F1,
    eF2 = GLFW_KEY_F2,
    eF3 = GLFW_KEY_F3,
    eF4 = GLFW_KEY_F4,
    eF5 = GLFW_KEY_F5,
    eF6 = GLFW_KEY_F6,
    eF7 = GLFW_KEY_F7,
    eF8 = GLFW_KEY_F8,
    eF9 = GLFW_KEY_F9,
    eF10 = GLFW_KEY_F10,
    eF11 = GLFW_KEY_F11,
    eF12 = GLFW_KEY_F12,
    eF13 = GLFW_KEY_F13,
    eF14 = GLFW_KEY_F14,
    eF15 = GLFW_KEY_F15,
    eF16 = GLFW_KEY_F16,
    eF17 = GLFW_KEY_F17,
    eF18 = GLFW_KEY_F18,
    eF19 = GLFW_KEY_F19,
    eF20 = GLFW_KEY_F20,
    eF21 = GLFW_KEY_F21,
    eF22 = GLFW_KEY_F22,
    eF23 = GLFW_KEY_F23,
    eF24 = GLFW_KEY_F24,
    eF25 = GLFW_KEY_F25,
    eKp0 = GLFW_KEY_KP_0,
    eKp1 = GLFW_KEY_KP_1,
    eKp2 = GLFW_KEY_KP_2,
    eKp3 = GLFW_KEY_KP_3,
    eKp4 = GLFW_KEY_KP_4,
    eKp5 = GLFW_KEY_KP_5,
    eKp6 = GLFW_KEY_KP_6,
    eKp7 = GLFW_KEY_KP_7,
    eKp8 = GLFW_KEY_KP_8,
    eKp9 = GLFW_KEY_KP_9,
    eKpDecimal = GLFW_KEY_KP_DECIMAL,
    eKpDivide = GLFW_KEY_KP_DIVIDE,
    eKpMultiply = GLFW_KEY_KP_MULTIPLY,
    eKpSubtract = GLFW_KEY_KP_SUBTRACT,
    eKpAdd = GLFW_KEY_KP_ADD,
    eKpEnter = GLFW_KEY_KP_ENTER,
    eKpEqual = GLFW_KEY_KP_EQUAL,
    eLeftShift = GLFW_KEY_LEFT_SHIFT,
    eLeftControl = GLFW_KEY_LEFT_CONTROL,
    eLeftAlt = GLFW_KEY_LEFT_ALT,
    eLeftSuper = GLFW_KEY_LEFT_SUPER,
    eRightShift = GLFW_KEY_RIGHT_SHIFT,
    eRightControl = GLFW_KEY_RIGHT_CONTROL,
    eRightAlt = GLFW_KEY_RIGHT_ALT,
    eRightSuper = GLFW_KEY_RIGHT_SUPER,
    eMenu = GLFW_KEY_MENU,
    eLast = GLFW_KEY_LAST,
};
GLFW_HPP_EXPORT enum class Mods {
    eShift = GLFW_MOD_SHIFT,
    eControl = GLFW_MOD_CONTROL,
    eAlt = GLFW_MOD_ALT,
    eSuper = GLFW_MOD_SUPER,
    eCapsLock = GLFW_MOD_CAPS_LOCK,
    eNumLock = GLFW_MOD_NUM_LOCK,
};
GLFW_HPP_EXPORT enum class Button {
    e1 = GLFW_MOUSE_BUTTON_1,
    e2 = GLFW_MOUSE_BUTTON_2,
    e3 = GLFW_MOUSE_BUTTON_3,
    e4 = GLFW_MOUSE_BUTTON_4,
    e5 = GLFW_MOUSE_BUTTON_5,
    e6 = GLFW_MOUSE_BUTTON_6,
    e7 = GLFW_MOUSE_BUTTON_7,
    e8 = GLFW_MOUSE_BUTTON_8,
    eLast = GLFW_MOUSE_BUTTON_LAST,
    eLeft = GLFW_MOUSE_BUTTON_LEFT,
    eRight = GLFW_MOUSE_BUTTON_RIGHT,
    eMiddle = GLFW_MOUSE_BUTTON_MIDDLE,
};
GLFW_HPP_EXPORT enum class GamepadButton {
    eA = GLFW_GAMEPAD_BUTTON_A,
    eB = GLFW_GAMEPAD_BUTTON_B,
    eX = GLFW_GAMEPAD_BUTTON_X,
    eY = GLFW_GAMEPAD_BUTTON_Y,
    eLeftBumper = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
    eRightBumper = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
    eBack = GLFW_GAMEPAD_BUTTON_BACK,
    eStart = GLFW_GAMEPAD_BUTTON_START,
    eGuide = GLFW_GAMEPAD_BUTTON_GUIDE,
    eLeftThumb = GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
    eRightThumb = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
    eDpadUp = GLFW_GAMEPAD_BUTTON_DPAD_UP,
    eDpadRight = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
    eDpadDown = GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
    eDpadLeft = GLFW_GAMEPAD_BUTTON_DPAD_LEFT,
    eLast = GLFW_GAMEPAD_BUTTON_LAST,
    eCross = GLFW_GAMEPAD_BUTTON_CROSS,
    eCircle = GLFW_GAMEPAD_BUTTON_CIRCLE,
    eSquare = GLFW_GAMEPAD_BUTTON_SQUARE,
    eTriangle = GLFW_GAMEPAD_BUTTON_TRIANGLE,
};
GLFW_HPP_EXPORT enum class GamepadAxis {
    eLeftX = GLFW_GAMEPAD_AXIS_LEFT_X,
    eLeftY = GLFW_GAMEPAD_AXIS_LEFT_Y,
    eRightX = GLFW_GAMEPAD_AXIS_RIGHT_X,
    eRightY = GLFW_GAMEPAD_AXIS_RIGHT_Y,
    eLeftTrigger = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
    eRightTrigger = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER,
    eLast = GLFW_GAMEPAD_AXIS_LAST,
};
GLFW_HPP_EXPORT enum class Error {
    eNoError = GLFW_NO_ERROR,
    eNotInitialized = GLFW_NOT_INITIALIZED,
    eNoCurrentContext = GLFW_NO_CURRENT_CONTEXT,
    eInvalidEnum = GLFW_INVALID_ENUM,
    eInvalidValue = GLFW_INVALID_VALUE,
    eOutOfMemory = GLFW_OUT_OF_MEMORY,
    eApiUnavailable = GLFW_API_UNAVAILABLE,
    eVersionUnavailable = GLFW_VERSION_UNAVAILABLE,
    ePlatformError = GLFW_PLATFORM_ERROR,
    eFormatUnavailable = GLFW_FORMAT_UNAVAILABLE,
    eNoWindowContext = GLFW_NO_WINDOW_CONTEXT,
    eCursorUnavailable = GLFW_CURSOR_UNAVAILABLE,
    eFeatureUnavailable = GLFW_FEATURE_UNAVAILABLE,
    eFeatureUnimplemented = GLFW_FEATURE_UNIMPLEMENTED,
    ePlatformUnavailable = GLFW_PLATFORM_UNAVAILABLE,
};
GLFW_HPP_EXPORT enum class WindowAttrib {
    eFocused = GLFW_FOCUSED,
    eIconified = GLFW_ICONIFIED,
    eResizable = GLFW_RESIZABLE,
    eVisible = GLFW_VISIBLE,
    eDecorated = GLFW_DECORATED,
    eAutoIconify = GLFW_AUTO_ICONIFY,
    eFloating = GLFW_FLOATING,
    eMaximized = GLFW_MAXIMIZED,
    eTransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
    eHovered = GLFW_HOVERED,
    eFocusOnShow = GLFW_FOCUS_ON_SHOW,
    eMousePassthrough = GLFW_MOUSE_PASSTHROUGH,
};
GLFW_HPP_EXPORT enum class WindowHint {
    eFocused = GLFW_FOCUSED,
    eIconified = GLFW_ICONIFIED,
    eResizable = GLFW_RESIZABLE,
    eVisible = GLFW_VISIBLE,
    eDecorated = GLFW_DECORATED,
    eAutoIconify = GLFW_AUTO_ICONIFY,
    eFloating = GLFW_FLOATING,
    eMaximized = GLFW_MAXIMIZED,
    eCenterCursor = GLFW_CENTER_CURSOR,
    eTransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
    eFocusOnShow = GLFW_FOCUS_ON_SHOW,
    eMousePassthrough = GLFW_MOUSE_PASSTHROUGH,
    ePositionX = GLFW_POSITION_X,
    ePositionY = GLFW_POSITION_Y,
    eRedBits = GLFW_RED_BITS,
    eGreenBits = GLFW_GREEN_BITS,
    eBlueBits = GLFW_BLUE_BITS,
    eAlphaBits = GLFW_ALPHA_BITS,
    eDepthBits = GLFW_DEPTH_BITS,
    eStencilBits = GLFW_STENCIL_BITS,
    eAccumRedBits = GLFW_ACCUM_RED_BITS,
    eAccumGreenBits = GLFW_ACCUM_GREEN_BITS,
    eAccumBlueBits = GLFW_ACCUM_BLUE_BITS,
    eAccumAlphaBits = GLFW_ACCUM_ALPHA_BITS,
    eAuxBuffers = GLFW_AUX_BUFFERS,
    eStereo = GLFW_STEREO,
    eSamples = GLFW_SAMPLES,
    eSrgbCapable = GLFW_SRGB_CAPABLE,
    eRefreshRate = GLFW_REFRESH_RATE,
    eDoublebuffer = GLFW_DOUBLEBUFFER,
    eClientApi = GLFW_CLIENT_API,
    eContextVersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
    eContextVersionMinor = GLFW_CONTEXT_VERSION_MINOR,
    eContextRevision = GLFW_CONTEXT_REVISION,
    eContextRobustness = GLFW_CONTEXT_ROBUSTNESS,
    eOpenglForwardCompat = GLFW_OPENGL_FORWARD_COMPAT,
    eContextDebug = GLFW_CONTEXT_DEBUG,
    eOpenglProfile = GLFW_OPENGL_PROFILE,
    eContextReleaseBehavior = GLFW_CONTEXT_RELEASE_BEHAVIOR,
    eContextNoError = GLFW_CONTEXT_NO_ERROR,
    eContextCreationApi = GLFW_CONTEXT_CREATION_API,
    eScaleToMonitor = GLFW_SCALE_TO_MONITOR,
    eScaleFramebuffer = GLFW_SCALE_FRAMEBUFFER,
    eCocoaRetinaFramebuffer = GLFW_COCOA_RETINA_FRAMEBUFFER,
    eCocoaFrameName = GLFW_COCOA_FRAME_NAME,
    eCocoaGraphicsSwitching = GLFW_COCOA_GRAPHICS_SWITCHING,
    eX11ClassName = GLFW_X11_CLASS_NAME,
    eX11InstanceName = GLFW_X11_INSTANCE_NAME,
    eWin32KeyboardMenu = GLFW_WIN32_KEYBOARD_MENU,
    eWin32Showdefault = GLFW_WIN32_SHOWDEFAULT,
    eWaylandAppId = GLFW_WAYLAND_APP_ID,
};
GLFW_HPP_EXPORT enum class WindowHintClientApi {
    eNoApi = GLFW_NO_API,
    eOpenglApi = GLFW_OPENGL_API,
    eOpenglEsApi = GLFW_OPENGL_ES_API,
};
GLFW_HPP_EXPORT enum class WindowHintContextRobustness {
    eNoRobustness = GLFW_NO_ROBUSTNESS,
    eNoResetNotification = GLFW_NO_RESET_NOTIFICATION,
    eLoseContextOnReset = GLFW_LOSE_CONTEXT_ON_RESET,
};
GLFW_HPP_EXPORT enum class WindowHintOpenglProfile {
    eAny = GLFW_OPENGL_ANY_PROFILE,
    eCore = GLFW_OPENGL_CORE_PROFILE,
    eCompat = GLFW_OPENGL_COMPAT_PROFILE,
};
GLFW_HPP_EXPORT enum class WindowHintContextReleaseBehavior {
    eAny = GLFW_RELEASE_BEHAVIOR_ANY,
    eFlush = GLFW_RELEASE_BEHAVIOR_FLUSH,
    eNone = GLFW_RELEASE_BEHAVIOR_NONE,
};
GLFW_HPP_EXPORT enum class WindowHintContextCreationApi {
    eNative = GLFW_NATIVE_CONTEXT_API,
    eEgl = GLFW_EGL_CONTEXT_API,
    eOsmesa = GLFW_OSMESA_CONTEXT_API,
};
GLFW_HPP_EXPORT enum class InputMode {
    eCursor = GLFW_CURSOR,
    eStickyKeys = GLFW_STICKY_KEYS,
    eStickyMouseButtons = GLFW_STICKY_MOUSE_BUTTONS,
    eLockKeyMods = GLFW_LOCK_KEY_MODS,
    eRawMouseMotion = GLFW_RAW_MOUSE_MOTION,
};
GLFW_HPP_EXPORT enum class InputModeCursor {
    eNormal = GLFW_CURSOR_NORMAL,
    eHidden = GLFW_CURSOR_HIDDEN,
    eDisabled = GLFW_CURSOR_DISABLED,
    eCaptured = GLFW_CURSOR_CAPTURED,
};
GLFW_HPP_EXPORT enum class InitHint {
    ePlatform = GLFW_PLATFORM,
    eJoystickHatButtons = GLFW_JOYSTICK_HAT_BUTTONS,
    eAnglePlatformType = GLFW_ANGLE_PLATFORM_TYPE,
    eCocoaChdirResources = GLFW_COCOA_CHDIR_RESOURCES,
    eCocoaMenubar = GLFW_COCOA_MENUBAR,
    eWaylandLibdecor = GLFW_WAYLAND_LIBDECOR,
    eX11XcbVulkanSurface = GLFW_X11_XCB_VULKAN_SURFACE,
};
GLFW_HPP_EXPORT enum class Platform {
    eWin32 = GLFW_PLATFORM_WIN32,
    eCocoa = GLFW_PLATFORM_COCOA,
    eWayland = GLFW_PLATFORM_WAYLAND,
    eX11 = GLFW_PLATFORM_X11,
    eNull = GLFW_PLATFORM_NULL,
};
GLFW_HPP_EXPORT enum class InitHintPlatform {
    eAny = GLFW_PLATFORM_ANY,
    eWin32 = GLFW_PLATFORM_WIN32,
    eCocoa = GLFW_PLATFORM_COCOA,
    eWayland = GLFW_PLATFORM_WAYLAND,
    eX11 = GLFW_PLATFORM_X11,
    eNull = GLFW_PLATFORM_NULL,
};
GLFW_HPP_EXPORT enum class InitHintAnglePlatformType {
    eNone = GLFW_ANGLE_PLATFORM_TYPE_NONE,
    eOpengl = GLFW_ANGLE_PLATFORM_TYPE_OPENGL,
    eOpengles = GLFW_ANGLE_PLATFORM_TYPE_OPENGLES,
    eD3D9 = GLFW_ANGLE_PLATFORM_TYPE_D3D9,
    eD3D11 = GLFW_ANGLE_PLATFORM_TYPE_D3D11,
    eVulkan = GLFW_ANGLE_PLATFORM_TYPE_VULKAN,
    eMetal = GLFW_ANGLE_PLATFORM_TYPE_METAL,
};
GLFW_HPP_EXPORT enum class InitHintWaylandLibdecor {
    ePrefer = GLFW_WAYLAND_PREFER_LIBDECOR,
    eDisable = GLFW_WAYLAND_DISABLE_LIBDECOR,
};
GLFW_HPP_EXPORT enum class CursorShape {
    eArrow = GLFW_ARROW_CURSOR,
    eIbeam = GLFW_IBEAM_CURSOR,
    eCrosshair = GLFW_CROSSHAIR_CURSOR,
    ePointingHand = GLFW_POINTING_HAND_CURSOR,
    eResizeEw = GLFW_RESIZE_EW_CURSOR,
    eResizeNs = GLFW_RESIZE_NS_CURSOR,
    eResizeNwse = GLFW_RESIZE_NWSE_CURSOR,
    eResizeNesw = GLFW_RESIZE_NESW_CURSOR,
    eResizeAll = GLFW_RESIZE_ALL_CURSOR,
    eNotAllowed = GLFW_NOT_ALLOWED_CURSOR,
    eHresize = GLFW_HRESIZE_CURSOR,
    eVresize = GLFW_VRESIZE_CURSOR,
    eHand = GLFW_HAND_CURSOR,
};
GLFW_HPP_EXPORT enum class JoystickEvent {
    eConnected = GLFW_CONNECTED,
    eDisconnected = GLFW_DISCONNECTED,
};
// !end_generated

GLFW_HPP_EXPORT Mods operator|(Mods lhs, Mods rhs) {
    return static_cast<Mods>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs));
}
GLFW_HPP_EXPORT Mods operator&(Mods lhs, Mods rhs) {
    return static_cast<Mods>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs));
}
GLFW_HPP_EXPORT Mods operator^(Mods lhs, Mods rhs) {
    return static_cast<Mods>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs));
}
GLFW_HPP_EXPORT Mods operator~(Mods mod) {
    return static_cast<Mods>(~static_cast<unsigned>(mod));
}

GLFW_HPP_EXPORT class GLFWException : public std::exception {
private:
    int m_errorCode;
    const char* m_message;

public:
    GLFWException(int errorCode, const char* message) noexcept {
        m_errorCode = errorCode;
        m_message = message;
    }

    virtual const char* what() const noexcept {
        return m_message;
    }

    int errorCode() const noexcept {
        return m_errorCode;
    }

    const char* message() const noexcept {
        return m_message;
    }

    virtual ~GLFWException() = default;
};

struct Version {
    int major = 0;
    int minor = 0;
    int rev = 0;
};

GLFW_HPP_EXPORT struct Color {
    unsigned short red = 0;
    unsigned short green = 0;
    unsigned short blue = 0;
};

GLFW_HPP_EXPORT using VideoMode = ::GLFWvidmode;
GLFW_HPP_EXPORT using GamepadState = ::GLFWgamepadstate;
GLFW_HPP_EXPORT using Image = ::GLFWimage;
GLFW_HPP_EXPORT using GammaRamp = std::vector<Color>;
GLFW_HPP_EXPORT using ProcAddress = void(*)();

inline void checkError() {
    const char* message = nullptr;
    int errorCode = ::glfwGetError(&message);
    if (errorCode != GLFW_NO_ERROR) {
        throw GLFWException{errorCode, message};
    }
}

GLFW_HPP_EXPORT class Monitor {
private:
    ::GLFWmonitor* m_monitor = nullptr;

public:
    Monitor() = default;

    explicit Monitor(::GLFWmonitor* monitor) noexcept : m_monitor(monitor) {}

    GLFW_HPP_NODISCARD explicit operator bool() const noexcept {
        return m_monitor != nullptr;
    }

    GLFW_HPP_NODISCARD bool operator==(Monitor that) const noexcept {
        return m_monitor == that.m_monitor;
    }

    GLFW_HPP_NODISCARD bool operator!=(Monitor that) const noexcept {
        return m_monitor != that.m_monitor;
    }

    GLFW_HPP_NODISCARD ::GLFWmonitor* handle() const noexcept {
        return m_monitor;
    }

// !begin_generated
// !generate_monitor_methods
    auto position() const {
        struct { int xpos; int ypos; } result{};
        ::glfwGetMonitorPos(m_monitor, &result.xpos, &result.ypos);
        checkError();
        return result;
    }

    auto workarea() const {
        struct { int xpos; int ypos; int width; int height; } result{};
        ::glfwGetMonitorWorkarea(m_monitor, &result.xpos, &result.ypos, &result.width, &result.height);
        checkError();
        return result;
    }

    auto physicalSize() const {
        struct { int widthMM; int heightMM; } result{};
        ::glfwGetMonitorPhysicalSize(m_monitor, &result.widthMM, &result.heightMM);
        checkError();
        return result;
    }

    auto contentScale() const {
        struct { float xscale; float yscale; } result{};
        ::glfwGetMonitorContentScale(m_monitor, &result.xscale, &result.yscale);
        checkError();
        return result;
    }

    GLFW_HPP_NODISCARD std::string_view name() const {
        auto returnValue = ::glfwGetMonitorName(m_monitor);
        checkError();
        return std::string_view{returnValue};
    }

    GLFW_HPP_NODISCARD auto videoModes() const {
        int count;
        auto returnValue = ::glfwGetVideoModes(m_monitor, &count);
        checkError();
        return std::span<const GLFWvidmode>{ returnValue, static_cast<std::size_t>(count) };
    }

    GLFW_HPP_NODISCARD const GLFWvidmode* videoMode() const {
        auto returnValue = ::glfwGetVideoMode(m_monitor);
        checkError();
        return returnValue;
    }

    void setGamma(float gamma) const {
        ::glfwSetGamma(m_monitor, gamma);
        checkError();
    }

// !end_generated

    GLFW_HPP_NODISCARD auto gammaRamp() const {
        auto glfwRamp = ::glfwGetGammaRamp(m_monitor);
        GammaRamp ramp(glfwRamp->size);
        for (int i = 0; i < glfwRamp->size; ++i) {
            ramp[i] = {
                .red = glfwRamp->red[i],
                .green = glfwRamp->green[i],
                .blue = glfwRamp->blue[i],
            };
        }
        return ramp;
    }

    void setGammaRamp(const GammaRamp& ramp) const {
        ::GLFWgammaramp glfwRamp;
        glfwRamp.size = static_cast<unsigned>(ramp.size());
        std::vector<unsigned short> red, green, blue;
        for (const auto& color : ramp) {
            red.push_back(color.red);
            green.push_back(color.green);
            blue.push_back(color.blue);
        }
        glfwRamp.red = red.data();
        glfwRamp.green = green.data();
        glfwRamp.blue = blue.data();
        ::glfwSetGammaRamp(m_monitor, &glfwRamp);
        checkError();
    }

// TODO: void glfwSetMonitorUserPointer(GLFWmonitor* monitor, void* pointer)
// TODO: void* glfwGetMonitorUserPointer(GLFWmonitor* monitor)
// TODO: GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun callback)
};

GLFW_HPP_EXPORT class Cursor {
private:
    ::GLFWcursor* m_cursor = nullptr;

public:
    Cursor() = default;

    explicit Cursor(GLFWcursor* cursor) noexcept : m_cursor(cursor) {}

    void destroy() noexcept {
        if (m_cursor != nullptr) {
            ::glfwDestroyCursor(m_cursor);
            m_cursor = nullptr;
        }
    }

    GLFWcursor* handle() const noexcept {
        return m_cursor;
    }
};

GLFW_HPP_EXPORT class Window {
private:
    ::GLFWwindow* m_window = nullptr;

    struct WindowPeer {
        Cursor standardCursor;
// !begin_generated
// !generate_window_peer
        std::function<void(int, int)> handleWindowPos;
        std::function<void(int, int)> handleWindowSize;
        std::function<void()> handleWindowClose;
        std::function<void()> handleWindowRefresh;
        std::function<void(bool)> handleWindowFocus;
        std::function<void(bool)> handleWindowIconify;
        std::function<void(bool)> handleWindowMaximize;
        std::function<void(int, int)> handleFramebufferSize;
        std::function<void(float, float)> handleWindowContentScale;
        std::function<void(Key, int, Action, Mods)> handleKey;
        std::function<void(unsigned)> handleChar;
        std::function<void(unsigned, Mods)> handleCharMods;
        std::function<void(Button, Action, Mods)> handleMouseButton;
        std::function<void(double, double)> handleCursorPos;
        std::function<void(bool)> handleCursorEnter;
        std::function<void(double, double)> handleScroll;
        std::function<void(std::span<const std::string_view>)> handleDrop;
// !end_generated
    };

    void initializeEventHandlers(WindowPeer* peer) const {
// !begin_generated
// !generate_window_callback_setup
        ::glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xpos, int ypos) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowPos) {
                peer->handleWindowPos(xpos, ypos);
            }
        });

        ::glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowSize) {
                peer->handleWindowSize(width, height);
            }
        });

        ::glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowClose) {
                peer->handleWindowClose();
            }
        });

        ::glfwSetWindowRefreshCallback(m_window, [](GLFWwindow* window) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowRefresh) {
                peer->handleWindowRefresh();
            }
        });

        ::glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowFocus) {
                peer->handleWindowFocus(focused == GLFW_TRUE);
            }
        });

        ::glfwSetWindowIconifyCallback(m_window, [](GLFWwindow* window, int iconified) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowIconify) {
                peer->handleWindowIconify(iconified == GLFW_TRUE);
            }
        });

        ::glfwSetWindowMaximizeCallback(m_window, [](GLFWwindow* window, int maximized) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowMaximize) {
                peer->handleWindowMaximize(maximized == GLFW_TRUE);
            }
        });

        ::glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleFramebufferSize) {
                peer->handleFramebufferSize(width, height);
            }
        });

        ::glfwSetWindowContentScaleCallback(m_window, [](GLFWwindow* window, float xscale, float yscale) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleWindowContentScale) {
                peer->handleWindowContentScale(xscale, yscale);
            }
        });

        ::glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleKey) {
                peer->handleKey(static_cast<Key>(key), scancode, static_cast<Action>(action), static_cast<Mods>(mods));
            }
        });

        ::glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned codepoint) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleChar) {
                peer->handleChar(codepoint);
            }
        });

        ::glfwSetCharModsCallback(m_window, [](GLFWwindow* window, unsigned codepoint, int mods) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleCharMods) {
                peer->handleCharMods(codepoint, static_cast<Mods>(mods));
            }
        });

        ::glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleMouseButton) {
                peer->handleMouseButton(static_cast<Button>(button), static_cast<Action>(action), static_cast<Mods>(mods));
            }
        });

        ::glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleCursorPos) {
                peer->handleCursorPos(xpos, ypos);
            }
        });

        ::glfwSetCursorEnterCallback(m_window, [](GLFWwindow* window, int entered) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleCursorEnter) {
                peer->handleCursorEnter(entered == GLFW_TRUE);
            }
        });

        ::glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleScroll) {
                peer->handleScroll(xoffset, yoffset);
            }
        });

// !end_generated
        ::glfwSetDropCallback(m_window, [](GLFWwindow* window, int count, const char* paths[]) {
            auto peer = reinterpret_cast<WindowPeer*>(::glfwGetWindowUserPointer(window));
            if (peer && peer->handleDrop) {
                std::vector<std::string_view> arg;
                for (int i = 0; i < count; ++i) {
                    arg.push_back(paths[i]);
                }
                peer->handleDrop(arg);
            }
        });
    }

    GLFW_HPP_NODISCARD WindowPeer* getPeer() const {
        void* ptr = ::glfwGetWindowUserPointer(m_window);
        checkError();
        if (ptr == nullptr) {
            WindowPeer* peer = new WindowPeer{};
            ::glfwSetWindowUserPointer(m_window, peer);
            initializeEventHandlers(peer);
            return peer;
        }
        return reinterpret_cast<WindowPeer*>(ptr);
    }

public:
    Window() = default;

    explicit Window(::GLFWwindow* window) noexcept : m_window(window) {}

    GLFW_HPP_NODISCARD explicit operator bool() const noexcept {
        return m_window != nullptr;
    }

    GLFW_HPP_NODISCARD bool operator==(Window that) const noexcept {
        return m_window == that.m_window;
    }

    GLFW_HPP_NODISCARD bool operator!=(Window that) const noexcept {
        return m_window != that.m_window;
    }

    GLFW_HPP_NODISCARD ::GLFWwindow* handle() const noexcept {
        return m_window;
    }

    void destroy() noexcept {
        if (m_window != nullptr) {
            auto peer = getPeer();
            peer->standardCursor.destroy();
            delete peer;
            ::glfwDestroyWindow(m_window);
            m_window = nullptr;
        }
    }

// !begin_generated
// !generate_window_methods
    GLFW_HPP_NODISCARD bool shouldClose() const {
        auto returnValue = ::glfwWindowShouldClose(m_window);
        checkError();
        return returnValue == GLFW_TRUE;
    }

    void setShouldClose(bool value) const {
        ::glfwSetWindowShouldClose(m_window, value ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    GLFW_HPP_NODISCARD std::string_view title() const {
        auto returnValue = ::glfwGetWindowTitle(m_window);
        checkError();
        return std::string_view{returnValue};
    }

    void setTitle(std::string_view title) const {
        ::glfwSetWindowTitle(m_window, std::string{title}.c_str());
        checkError();
    }

    void setIcon(std::span<const GLFWimage> images) const {
        ::glfwSetWindowIcon(m_window, images.size(), images.data());
        checkError();
    }

    auto position() const {
        struct { int xpos; int ypos; } result{};
        ::glfwGetWindowPos(m_window, &result.xpos, &result.ypos);
        checkError();
        return result;
    }

    void setPosition(int xpos, int ypos) const {
        ::glfwSetWindowPos(m_window, xpos, ypos);
        checkError();
    }

    auto size() const {
        struct { int width; int height; } result{};
        ::glfwGetWindowSize(m_window, &result.width, &result.height);
        checkError();
        return result;
    }

    void setSizeLimits(int minwidth, int minheight, int maxwidth, int maxheight) const {
        ::glfwSetWindowSizeLimits(m_window, minwidth, minheight, maxwidth, maxheight);
        checkError();
    }

    void setAspectRatio(int numer, int denom) const {
        ::glfwSetWindowAspectRatio(m_window, numer, denom);
        checkError();
    }

    void setSize(int width, int height) const {
        ::glfwSetWindowSize(m_window, width, height);
        checkError();
    }

    auto framebufferSize() const {
        struct { int width; int height; } result{};
        ::glfwGetFramebufferSize(m_window, &result.width, &result.height);
        checkError();
        return result;
    }

    auto frameSize() const {
        struct { int left; int top; int right; int bottom; } result{};
        ::glfwGetWindowFrameSize(m_window, &result.left, &result.top, &result.right, &result.bottom);
        checkError();
        return result;
    }

    auto contentScale() const {
        struct { float xscale; float yscale; } result{};
        ::glfwGetWindowContentScale(m_window, &result.xscale, &result.yscale);
        checkError();
        return result;
    }

    GLFW_HPP_NODISCARD float opacity() const {
        auto returnValue = ::glfwGetWindowOpacity(m_window);
        checkError();
        return returnValue;
    }

    void setOpacity(float opacity) const {
        ::glfwSetWindowOpacity(m_window, opacity);
        checkError();
    }

    void iconify() const {
        ::glfwIconifyWindow(m_window);
        checkError();
    }

    void restore() const {
        ::glfwRestoreWindow(m_window);
        checkError();
    }

    void maximize() const {
        ::glfwMaximizeWindow(m_window);
        checkError();
    }

    void show() const {
        ::glfwShowWindow(m_window);
        checkError();
    }

    void hide() const {
        ::glfwHideWindow(m_window);
        checkError();
    }

    void focus() const {
        ::glfwFocusWindow(m_window);
        checkError();
    }

    void requestAttention() const {
        ::glfwRequestWindowAttention(m_window);
        checkError();
    }

    GLFW_HPP_NODISCARD Monitor monitor() const {
        auto returnValue = ::glfwGetWindowMonitor(m_window);
        checkError();
        return Monitor{returnValue};
    }

    void setMonitor(Monitor monitor, int xpos, int ypos, int width, int height, int refreshRate) const {
        ::glfwSetWindowMonitor(m_window, monitor.handle(), xpos, ypos, width, height, refreshRate);
        checkError();
    }

    GLFW_HPP_NODISCARD bool getAttrib(WindowAttrib attrib) const {
        auto returnValue = ::glfwGetWindowAttrib(m_window, static_cast<int>(attrib));
        checkError();
        return returnValue;
    }

    void setAttrib(WindowAttrib attrib, bool value) const {
        ::glfwSetWindowAttrib(m_window, static_cast<int>(attrib), value ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    GLFW_HPP_NODISCARD int getInputMode(InputMode mode) const {
        auto returnValue = ::glfwGetInputMode(m_window, static_cast<int>(mode));
        checkError();
        return returnValue;
    }

    void setInputMode(InputMode mode, int value) const {
        ::glfwSetInputMode(m_window, static_cast<int>(mode), value);
        checkError();
    }

    GLFW_HPP_NODISCARD bool getKey(Key key) const {
        auto returnValue = ::glfwGetKey(m_window, static_cast<int>(key));
        checkError();
        return returnValue == GLFW_TRUE;
    }

    GLFW_HPP_NODISCARD bool getMouseButton(Button button) const {
        auto returnValue = ::glfwGetMouseButton(m_window, static_cast<int>(button));
        checkError();
        return returnValue == GLFW_TRUE;
    }

    auto cursorPosition() const {
        struct { double xpos; double ypos; } result{};
        ::glfwGetCursorPos(m_window, &result.xpos, &result.ypos);
        checkError();
        return result;
    }

    void setCursorPosition(double xpos, double ypos) const {
        ::glfwSetCursorPos(m_window, xpos, ypos);
        checkError();
    }

    void setClipboardString(std::string_view string) const {
        ::glfwSetClipboardString(m_window, std::string{string}.c_str());
        checkError();
    }

    GLFW_HPP_NODISCARD std::string_view clipboardString() const {
        auto returnValue = ::glfwGetClipboardString(m_window);
        checkError();
        return std::string_view{returnValue};
    }

    void makeContextCurrent() const {
        ::glfwMakeContextCurrent(m_window);
        checkError();
    }

    void swapBuffers() const {
        ::glfwSwapBuffers(m_window);
        checkError();
    }

    void setWindowPosHandler(std::function<void(int, int)> handler) const {
        getPeer()->handleWindowPos = std::move(handler);
    }

    void setWindowSizeHandler(std::function<void(int, int)> handler) const {
        getPeer()->handleWindowSize = std::move(handler);
    }

    void setWindowCloseHandler(std::function<void()> handler) const {
        getPeer()->handleWindowClose = std::move(handler);
    }

    void setWindowRefreshHandler(std::function<void()> handler) const {
        getPeer()->handleWindowRefresh = std::move(handler);
    }

    void setWindowFocusHandler(std::function<void(bool)> handler) const {
        getPeer()->handleWindowFocus = std::move(handler);
    }

    void setWindowIconifyHandler(std::function<void(bool)> handler) const {
        getPeer()->handleWindowIconify = std::move(handler);
    }

    void setWindowMaximizeHandler(std::function<void(bool)> handler) const {
        getPeer()->handleWindowMaximize = std::move(handler);
    }

    void setFramebufferSizeHandler(std::function<void(int, int)> handler) const {
        getPeer()->handleFramebufferSize = std::move(handler);
    }

    void setWindowContentScaleHandler(std::function<void(float, float)> handler) const {
        getPeer()->handleWindowContentScale = std::move(handler);
    }

    void setKeyHandler(std::function<void(Key, int, Action, Mods)> handler) const {
        getPeer()->handleKey = std::move(handler);
    }

    void setCharHandler(std::function<void(unsigned)> handler) const {
        getPeer()->handleChar = std::move(handler);
    }

    void setCharModsHandler(std::function<void(unsigned, Mods)> handler) const {
        getPeer()->handleCharMods = std::move(handler);
    }

    void setMouseButtonHandler(std::function<void(Button, Action, Mods)> handler) const {
        getPeer()->handleMouseButton = std::move(handler);
    }

    void setCursorPosHandler(std::function<void(double, double)> handler) const {
        getPeer()->handleCursorPos = std::move(handler);
    }

    void setCursorEnterHandler(std::function<void(bool)> handler) const {
        getPeer()->handleCursorEnter = std::move(handler);
    }

    void setScrollHandler(std::function<void(double, double)> handler) const {
        getPeer()->handleScroll = std::move(handler);
    }

    void setDropHandler(std::function<void(std::span<const std::string_view>)> handler) const {
        getPeer()->handleDrop = std::move(handler);
    }

    GLFW_HPP_NODISCARD bool isFocused() const {
        return getAttrib(WindowAttrib::eFocused);
    }

    GLFW_HPP_NODISCARD bool isIconified() const {
        return getAttrib(WindowAttrib::eIconified);
    }

    GLFW_HPP_NODISCARD bool isResizable() const {
        return getAttrib(WindowAttrib::eResizable);
    }

    void setResizable(bool value) const {
        setAttrib(WindowAttrib::eResizable, value);
    }

    GLFW_HPP_NODISCARD bool isVisible() const {
        return getAttrib(WindowAttrib::eVisible);
    }

    GLFW_HPP_NODISCARD bool isDecorated() const {
        return getAttrib(WindowAttrib::eDecorated);
    }

    void setDecorated(bool value) const {
        setAttrib(WindowAttrib::eDecorated, value);
    }

    GLFW_HPP_NODISCARD bool isAutoIconify() const {
        return getAttrib(WindowAttrib::eAutoIconify);
    }

    void setAutoIconify(bool value) const {
        setAttrib(WindowAttrib::eAutoIconify, value);
    }

    GLFW_HPP_NODISCARD bool isFloating() const {
        return getAttrib(WindowAttrib::eFloating);
    }

    void setFloating(bool value) const {
        setAttrib(WindowAttrib::eFloating, value);
    }

    GLFW_HPP_NODISCARD bool isMaximized() const {
        return getAttrib(WindowAttrib::eMaximized);
    }

    GLFW_HPP_NODISCARD bool isTransparentFramebuffer() const {
        return getAttrib(WindowAttrib::eTransparentFramebuffer);
    }

    GLFW_HPP_NODISCARD bool isHovered() const {
        return getAttrib(WindowAttrib::eHovered);
    }

    GLFW_HPP_NODISCARD bool isFocusOnShow() const {
        return getAttrib(WindowAttrib::eFocusOnShow);
    }

    void setFocusOnShow(bool value) const {
        setAttrib(WindowAttrib::eFocusOnShow, value);
    }

    GLFW_HPP_NODISCARD bool isMousePassthrough() const {
        return getAttrib(WindowAttrib::eMousePassthrough);
    }

// !end_generated

    GLFW_HPP_NODISCARD InputModeCursor cursorMode() const {
        auto mode = static_cast<InputModeCursor>(::glfwGetInputMode(m_window, GLFW_CURSOR));
        checkError();
        return mode;
    }

    void setCursorMode(InputModeCursor mode) const {
        ::glfwSetInputMode(m_window, GLFW_CURSOR, static_cast<int>(mode));
        checkError();
    }

    GLFW_HPP_NODISCARD bool stickyKeysEnabled() const {
        bool enabled = ::glfwGetInputMode(m_window, GLFW_STICKY_KEYS) == GLFW_TRUE;
        checkError();
        return enabled;
    }

    void setStickyKeysEnabled(bool enabled) const {
        ::glfwSetInputMode(m_window, GLFW_STICKY_KEYS, enabled ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    GLFW_HPP_NODISCARD bool stickyMouseButtonsEnabled() const {
        bool enabled = ::glfwGetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS) == GLFW_TRUE;
        checkError();
        return enabled;
    }

    void setStickyMouseButtonsEnabled(bool enabled) const {
        ::glfwSetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS, enabled ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    GLFW_HPP_NODISCARD bool lockKeyModsEnabled() const {
        bool enabled = ::glfwGetInputMode(m_window, GLFW_LOCK_KEY_MODS) == GLFW_TRUE;
        checkError();
        return enabled;
    }

    void setLockKeyModsEnabled(bool enabled) const {
        ::glfwSetInputMode(m_window, GLFW_LOCK_KEY_MODS, enabled ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    GLFW_HPP_NODISCARD bool rawMouseMotionEnabled() const {
        bool enabled = ::glfwGetInputMode(m_window, GLFW_RAW_MOUSE_MOTION) == GLFW_TRUE;
        checkError();
        return enabled;
    }

    void setRawMouseMotionEnabled(bool enabled) const {
        ::glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, enabled ? GLFW_TRUE : GLFW_FALSE);
        checkError();
    }

    void setCursor(CursorShape shape) const {
        auto peer = getPeer();
        auto cursor = Cursor{::glfwCreateStandardCursor(static_cast<int>(shape))};
        checkError();
        peer->standardCursor.destroy();
        peer->standardCursor = cursor;
        setCursor(cursor);
    }

    void setCursor(Cursor cursor) const {
        ::glfwSetCursor(m_window, cursor.handle());
        checkError();
    }

#if defined(VK_VERSION_1_0) && defined(VK_KHR_surface)
    GLFW_HPP_NODISCARD ::VkSurfaceKHR createSurface(
        ::VkInstance instance,
        const ::VkAllocationCallbacks* allocator = nullptr
    ) {
        ::VkSurfaceKHR surface;
        ::VkResult result = ::glfwCreateWindowSurface(instance, m_window, allocator, &surface);
        checkError();
        if (result != VK_SUCCESS) {
            throw GLFWException{GLFW_PLATFORM_ERROR, "Unexpected Vulkan error when creating surface"};
        }
        return surface;
    }

#ifdef VULKAN_HANDLES_HPP
    GLFW_HPP_NODISCARD VULKAN_HPP_NAMESPACE::SurfaceKHR createSurface(
        VULKAN_HPP_NAMESPACE::Instance instance,
        const VULKAN_HPP_NAMESPACE::AllocationCallbacks* allocator = nullptr
    ) {
        return createSurface(static_cast<::VkInstance>(instance), allocator ? &*allocator : nullptr);
    }

    GLFW_HPP_NODISCARD VULKAN_HPP_NAMESPACE::UniqueSurfaceKHR createSurfaceUnique(
        VULKAN_HPP_NAMESPACE::Instance instance,
        const VULKAN_HPP_NAMESPACE::AllocationCallbacks* allocator = nullptr
    ) {
        VULKAN_HPP_NAMESPACE::SurfaceKHR surface = createSurface(instance, allocator);
        return VULKAN_HPP_NAMESPACE::UniqueSurfaceKHR{surface, instance};
    }
#endif

#endif

#ifdef _glfw3_webgpu_h_

    GLFW_HPP_NODISCARD WGPUSurface getWGPUSurface(WGPUInstance instance) {
        return ::glfwGetWGPUSurface(instance, m_window);
    }

#endif // _glfw3_webgpu_h_
};

GLFW_HPP_EXPORT class Gamepad {
private:
    int m_gamepad = -1;

public:
    Gamepad() = default;

    explicit Gamepad(int gamepad) : m_gamepad(gamepad) {}

    GLFW_HPP_NODISCARD explicit operator bool() const noexcept {
        return m_gamepad >= GLFW_JOYSTICK_1 && m_gamepad <= GLFW_JOYSTICK_LAST;
    }

    GLFW_HPP_NODISCARD bool operator==(Gamepad that) const noexcept {
        return m_gamepad == that.m_gamepad;
    }

    GLFW_HPP_NODISCARD bool operator!=(Gamepad that) const noexcept {
        return m_gamepad != that.m_gamepad;
    }

    GLFW_HPP_NODISCARD int handle() const noexcept {
        return m_gamepad;
    }

    GLFW_HPP_NODISCARD std::string_view name() const {
        const char* name = ::glfwGetGamepadName(m_gamepad);
        checkError();
        return name;
    }

    GLFW_HPP_NODISCARD GamepadState state() const {
        GamepadState state{};
        ::glfwGetGamepadState(m_gamepad, &state);
        checkError();
        return state;
    }
};

GLFW_HPP_EXPORT class Joystick {
private:
    int m_joystick = -1;

public:
    Joystick() = default;

    explicit Joystick(int joystick) : m_joystick(joystick) {}

    explicit operator bool() const noexcept {
        return m_joystick >= GLFW_JOYSTICK_1 && m_joystick <= GLFW_JOYSTICK_LAST;
    }

    GLFW_HPP_NODISCARD bool operator==(Joystick that) const noexcept {
        return m_joystick == that.m_joystick;
    }

    GLFW_HPP_NODISCARD bool operator!=(Joystick that) const noexcept {
        return m_joystick != that.m_joystick;
    }

    GLFW_HPP_NODISCARD int id() const noexcept {
        return m_joystick;
    }

    GLFW_HPP_NODISCARD bool isPresent() const {
        bool present = ::glfwJoystickPresent(static_cast<int>(m_joystick));
        checkError();
        return present;
    }

    GLFW_HPP_NODISCARD std::span<const float> axes() const {
        int count;
        const float* axes = ::glfwGetJoystickAxes(static_cast<int>(m_joystick), &count);
        checkError();
        return {axes, axes + count};
    }

    GLFW_HPP_NODISCARD std::span<const unsigned char> buttons(Joystick joystickId) const {
        int count;
        const unsigned char* buttons = ::glfwGetJoystickButtons(static_cast<int>(m_joystick), &count);
        checkError();
        return {buttons, buttons + count};
    }

    GLFW_HPP_NODISCARD std::span<const unsigned char> hats() const {
        int count;
        const unsigned char* hats = ::glfwGetJoystickHats(static_cast<int>(m_joystick), &count);
        checkError();
        return {hats, hats + count};
    }

    GLFW_HPP_NODISCARD std::string_view name() const {
        const char* name = ::glfwGetJoystickName(m_joystick);
        checkError();
        return name;
    }

    GLFW_HPP_NODISCARD std::string_view guid() const {
        const char* guid = ::glfwGetJoystickGUID(m_joystick);
        checkError();
        return guid;
    }

    GLFW_HPP_NODISCARD Gamepad gamepad() const {
        bool isGamepad = ::glfwJoystickIsGamepad(m_joystick);
        checkError();
        if (isGamepad) {
            return Gamepad{m_joystick};
        } else {
            return Gamepad{};
        }
    }
};


GLFW_HPP_EXPORT struct InitInfo {
// !begin_generated
// !generate_init_hint_defs
    std::optional<InitHintPlatform> platform;
    std::optional<bool> joystickHatButtons;
    std::optional<InitHintAnglePlatformType> anglePlatformType;
    std::optional<bool> cocoaChdirResources;
    std::optional<bool> cocoaMenubar;
    std::optional<InitHintWaylandLibdecor> waylandLibdecor;
    std::optional<bool> x11XcbVulkanSurface;
// !end_generated
#ifdef VK_VERSION_1_0
    PFN_vkGetInstanceProcAddr vulkanLoader = nullptr;
#endif
};

GLFW_HPP_EXPORT struct WindowCreateInfo {
    int width;
    int height;
    std::string title;
    Monitor monitor;
    Window share;
// !begin_generated
// !generate_window_hint_defs
    std::optional<bool> focused;
    std::optional<bool> iconified;
    std::optional<bool> resizable;
    std::optional<bool> visible;
    std::optional<bool> decorated;
    std::optional<bool> autoIconify;
    std::optional<bool> floating;
    std::optional<bool> maximized;
    std::optional<bool> centerCursor;
    std::optional<bool> transparentFramebuffer;
    std::optional<bool> focusOnShow;
    std::optional<bool> mousePassthrough;
    std::optional<int> positionX;
    std::optional<int> positionY;
    std::optional<int> redBits;
    std::optional<int> greenBits;
    std::optional<int> blueBits;
    std::optional<int> alphaBits;
    std::optional<int> depthBits;
    std::optional<int> stencilBits;
    std::optional<int> accumRedBits;
    std::optional<int> accumGreenBits;
    std::optional<int> accumBlueBits;
    std::optional<int> accumAlphaBits;
    std::optional<int> auxBuffers;
    std::optional<int> samples;
    std::optional<int> refreshRate;
    std::optional<bool> stereo;
    std::optional<bool> srgbCapable;
    std::optional<bool> doublebuffer;
    std::optional<WindowHintClientApi> clientApi;
    std::optional<int> contextVersionMajor;
    std::optional<int> contextVersionMinor;
    std::optional<int> contextRevision;
    std::optional<WindowHintContextRobustness> contextRobustness;
    std::optional<bool> openglForwardCompat;
    std::optional<bool> contextDebug;
    std::optional<WindowHintOpenglProfile> openglProfile;
    std::optional<WindowHintContextReleaseBehavior> contextReleaseBehavior;
    std::optional<bool> contextNoError;
    std::optional<WindowHintContextCreationApi> contextCreationApi;
    std::optional<bool> scaleToMonitor;
    std::optional<bool> scaleFramebuffer;
    std::optional<std::string> cocoaFrameName;
    std::optional<bool> cocoaGraphicsSwitching;
    std::optional<std::string> x11ClassName;
    std::optional<std::string> x11InstanceName;
    std::optional<bool> win32KeyboardMenu;
    std::optional<bool> win32Showdefault;
    std::optional<std::string> waylandAppId;
// !end_generated
};

GLFW_HPP_API void init(const InitInfo& info = {}) {
// !begin_generated
// !generate_apply_init_hints
    if (info.platform) {
        ::glfwInitHint(GLFW_PLATFORM, static_cast<int>(info.platform.value()));
        checkError();
    }

    if (info.joystickHatButtons) {
        ::glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, static_cast<int>(info.joystickHatButtons.value()));
        checkError();
    }

    if (info.anglePlatformType) {
        ::glfwInitHint(GLFW_ANGLE_PLATFORM_TYPE, static_cast<int>(info.anglePlatformType.value()));
        checkError();
    }

    if (info.cocoaChdirResources) {
        ::glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, static_cast<int>(info.cocoaChdirResources.value()));
        checkError();
    }

    if (info.cocoaMenubar) {
        ::glfwInitHint(GLFW_COCOA_MENUBAR, static_cast<int>(info.cocoaMenubar.value()));
        checkError();
    }

    if (info.waylandLibdecor) {
        ::glfwInitHint(GLFW_WAYLAND_LIBDECOR, static_cast<int>(info.waylandLibdecor.value()));
        checkError();
    }

    if (info.x11XcbVulkanSurface) {
        ::glfwInitHint(GLFW_X11_XCB_VULKAN_SURFACE, static_cast<int>(info.x11XcbVulkanSurface.value()));
        checkError();
    }

// !end_generated
    ::glfwInit();
    checkError();
}

GLFW_HPP_API void terminate() {
    ::glfwTerminate();
    checkError();
}

GLFW_HPP_API_NODISCARD Version getVersion() {
    Version ver;
    ::glfwGetVersion(&ver.major, &ver.minor, &ver.rev);
    checkError();
    return ver;
}

GLFW_HPP_API_NODISCARD std::string_view getVersionString() {
    const char* ver = ::glfwGetVersionString();
    checkError();
    return ver;
}

GLFW_HPP_API_NODISCARD Platform getPlatform() {
    int platform = ::glfwGetPlatform();
    checkError();
    return static_cast<Platform>(platform);
}

GLFW_HPP_API_NODISCARD bool isPlatformSupported(Platform platform) {
    int supported = ::glfwPlatformSupported(static_cast<int>(platform));
    checkError();
    return supported == GLFW_TRUE;
}

GLFW_HPP_API_NODISCARD std::vector<Monitor> getMonitors() {
    int count = 0;
    GLFWmonitor** monitors = ::glfwGetMonitors(&count);
    checkError();
    std::vector<Monitor> result;
    if (monitors) {
        for (int i = 0; i < count; ++i) {
            result.emplace_back(monitors[i]);
        }
    }
    return result;
}

GLFW_HPP_API_NODISCARD Monitor getPrimaryMonitor() {
    GLFWmonitor* monitor = ::glfwGetPrimaryMonitor();
    checkError();
    return Monitor{monitor};
}

GLFW_HPP_API_NODISCARD Window createWindow(const WindowCreateInfo& info) {
// !begin_generated
// !generate_apply_window_hints
    if (info.focused) {
        ::glfwWindowHint(GLFW_FOCUSED, static_cast<int>(info.focused.value()));
        checkError();
    }

    if (info.iconified) {
        ::glfwWindowHint(GLFW_ICONIFIED, static_cast<int>(info.iconified.value()));
        checkError();
    }

    if (info.resizable) {
        ::glfwWindowHint(GLFW_RESIZABLE, static_cast<int>(info.resizable.value()));
        checkError();
    }

    if (info.visible) {
        ::glfwWindowHint(GLFW_VISIBLE, static_cast<int>(info.visible.value()));
        checkError();
    }

    if (info.decorated) {
        ::glfwWindowHint(GLFW_DECORATED, static_cast<int>(info.decorated.value()));
        checkError();
    }

    if (info.autoIconify) {
        ::glfwWindowHint(GLFW_AUTO_ICONIFY, static_cast<int>(info.autoIconify.value()));
        checkError();
    }

    if (info.floating) {
        ::glfwWindowHint(GLFW_FLOATING, static_cast<int>(info.floating.value()));
        checkError();
    }

    if (info.maximized) {
        ::glfwWindowHint(GLFW_MAXIMIZED, static_cast<int>(info.maximized.value()));
        checkError();
    }

    if (info.centerCursor) {
        ::glfwWindowHint(GLFW_CENTER_CURSOR, static_cast<int>(info.centerCursor.value()));
        checkError();
    }

    if (info.transparentFramebuffer) {
        ::glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, static_cast<int>(info.transparentFramebuffer.value()));
        checkError();
    }

    if (info.focusOnShow) {
        ::glfwWindowHint(GLFW_FOCUS_ON_SHOW, static_cast<int>(info.focusOnShow.value()));
        checkError();
    }

    if (info.mousePassthrough) {
        ::glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, static_cast<int>(info.mousePassthrough.value()));
        checkError();
    }

    if (info.positionX) {
        ::glfwWindowHint(GLFW_POSITION_X, static_cast<int>(info.positionX.value()));
        checkError();
    }

    if (info.positionY) {
        ::glfwWindowHint(GLFW_POSITION_Y, static_cast<int>(info.positionY.value()));
        checkError();
    }

    if (info.redBits) {
        ::glfwWindowHint(GLFW_RED_BITS, static_cast<int>(info.redBits.value()));
        checkError();
    }

    if (info.greenBits) {
        ::glfwWindowHint(GLFW_GREEN_BITS, static_cast<int>(info.greenBits.value()));
        checkError();
    }

    if (info.blueBits) {
        ::glfwWindowHint(GLFW_BLUE_BITS, static_cast<int>(info.blueBits.value()));
        checkError();
    }

    if (info.alphaBits) {
        ::glfwWindowHint(GLFW_ALPHA_BITS, static_cast<int>(info.alphaBits.value()));
        checkError();
    }

    if (info.depthBits) {
        ::glfwWindowHint(GLFW_DEPTH_BITS, static_cast<int>(info.depthBits.value()));
        checkError();
    }

    if (info.stencilBits) {
        ::glfwWindowHint(GLFW_STENCIL_BITS, static_cast<int>(info.stencilBits.value()));
        checkError();
    }

    if (info.accumRedBits) {
        ::glfwWindowHint(GLFW_ACCUM_RED_BITS, static_cast<int>(info.accumRedBits.value()));
        checkError();
    }

    if (info.accumGreenBits) {
        ::glfwWindowHint(GLFW_ACCUM_GREEN_BITS, static_cast<int>(info.accumGreenBits.value()));
        checkError();
    }

    if (info.accumBlueBits) {
        ::glfwWindowHint(GLFW_ACCUM_BLUE_BITS, static_cast<int>(info.accumBlueBits.value()));
        checkError();
    }

    if (info.accumAlphaBits) {
        ::glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, static_cast<int>(info.accumAlphaBits.value()));
        checkError();
    }

    if (info.auxBuffers) {
        ::glfwWindowHint(GLFW_AUX_BUFFERS, static_cast<int>(info.auxBuffers.value()));
        checkError();
    }

    if (info.samples) {
        ::glfwWindowHint(GLFW_SAMPLES, static_cast<int>(info.samples.value()));
        checkError();
    }

    if (info.refreshRate) {
        ::glfwWindowHint(GLFW_REFRESH_RATE, static_cast<int>(info.refreshRate.value()));
        checkError();
    }

    if (info.stereo) {
        ::glfwWindowHint(GLFW_STEREO, static_cast<int>(info.stereo.value()));
        checkError();
    }

    if (info.srgbCapable) {
        ::glfwWindowHint(GLFW_SRGB_CAPABLE, static_cast<int>(info.srgbCapable.value()));
        checkError();
    }

    if (info.doublebuffer) {
        ::glfwWindowHint(GLFW_DOUBLEBUFFER, static_cast<int>(info.doublebuffer.value()));
        checkError();
    }

    if (info.clientApi) {
        ::glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(info.clientApi.value()));
        checkError();
    }

    if (info.contextVersionMajor) {
        ::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(info.contextVersionMajor.value()));
        checkError();
    }

    if (info.contextVersionMinor) {
        ::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(info.contextVersionMinor.value()));
        checkError();
    }

    if (info.contextRevision) {
        ::glfwWindowHint(GLFW_CONTEXT_REVISION, static_cast<int>(info.contextRevision.value()));
        checkError();
    }

    if (info.contextRobustness) {
        ::glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(info.contextRobustness.value()));
        checkError();
    }

    if (info.openglForwardCompat) {
        ::glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, static_cast<int>(info.openglForwardCompat.value()));
        checkError();
    }

    if (info.contextDebug) {
        ::glfwWindowHint(GLFW_CONTEXT_DEBUG, static_cast<int>(info.contextDebug.value()));
        checkError();
    }

    if (info.openglProfile) {
        ::glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(info.openglProfile.value()));
        checkError();
    }

    if (info.contextReleaseBehavior) {
        ::glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(info.contextReleaseBehavior.value()));
        checkError();
    }

    if (info.contextNoError) {
        ::glfwWindowHint(GLFW_CONTEXT_NO_ERROR, static_cast<int>(info.contextNoError.value()));
        checkError();
    }

    if (info.contextCreationApi) {
        ::glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(info.contextCreationApi.value()));
        checkError();
    }

    if (info.scaleToMonitor) {
        ::glfwWindowHint(GLFW_SCALE_TO_MONITOR, static_cast<int>(info.scaleToMonitor.value()));
        checkError();
    }

    if (info.scaleFramebuffer) {
        ::glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, static_cast<int>(info.scaleFramebuffer.value()));
        checkError();
    }

    if (info.cocoaFrameName) {
        ::glfwWindowHintString(GLFW_COCOA_FRAME_NAME, info.cocoaFrameName.value().c_str());
        checkError();
    }

    if (info.cocoaGraphicsSwitching) {
        ::glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, static_cast<int>(info.cocoaGraphicsSwitching.value()));
        checkError();
    }

    if (info.x11ClassName) {
        ::glfwWindowHintString(GLFW_X11_CLASS_NAME, info.x11ClassName.value().c_str());
        checkError();
    }

    if (info.x11InstanceName) {
        ::glfwWindowHintString(GLFW_X11_INSTANCE_NAME, info.x11InstanceName.value().c_str());
        checkError();
    }

    if (info.win32KeyboardMenu) {
        ::glfwWindowHint(GLFW_WIN32_KEYBOARD_MENU, static_cast<int>(info.win32KeyboardMenu.value()));
        checkError();
    }

    if (info.win32Showdefault) {
        ::glfwWindowHint(GLFW_WIN32_SHOWDEFAULT, static_cast<int>(info.win32Showdefault.value()));
        checkError();
    }

    if (info.waylandAppId) {
        ::glfwWindowHintString(GLFW_WAYLAND_APP_ID, info.waylandAppId.value().c_str());
        checkError();
    }

// !end_generated

    ::GLFWwindow* window = ::glfwCreateWindow(
        info.width,
        info.height,
        info.title.c_str(),
        info.monitor.handle(),
        info.share.handle()
    );
    checkError();
    return Window{window};
}

GLFW_HPP_API void pollEvents() {
    ::glfwPollEvents();
    checkError();
}

GLFW_HPP_API void waitEvents() {
    ::glfwWaitEvents();
    checkError();
}

GLFW_HPP_API void waitEvents(double timeout) {
    ::glfwWaitEventsTimeout(timeout);
    checkError();
}

GLFW_HPP_API void postEmptyEvent() {
    ::glfwPostEmptyEvent();
    checkError();
}

GLFW_HPP_API_NODISCARD bool rawMouseMotionSupported() {
    bool result = ::glfwRawMouseMotionSupported() == GLFW_TRUE;
    checkError();
    return result;
}

GLFW_HPP_API_NODISCARD std::string_view keyName(Key key) {
    std::string_view name = ::glfwGetKeyName(static_cast<int>(key), 0);
    checkError();
    return name;
}

GLFW_HPP_API_NODISCARD std::string_view keyNameByScancode(int scancode) {
    std::string_view name = ::glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
    checkError();
    return name;
}

GLFW_HPP_API_NODISCARD int keyScancode(Key key) {
    int scancode = ::glfwGetKeyScancode(static_cast<int>(key));
    checkError();
    return scancode;
}

GLFW_HPP_API_NODISCARD bool updateGamepadMappings(const char* string) {
    bool success = ::glfwUpdateGamepadMappings(string) == GLFW_TRUE;
    const char* message = nullptr;
    int errorCode = ::glfwGetError(&message);
    if (errorCode != GLFW_NO_ERROR && errorCode != GLFW_INVALID_VALUE) {
        throw GLFWException{errorCode, message};
    }
    return success;
}

GLFW_HPP_API_NODISCARD bool updateGamepadMappings(const std::string& string) {
    return updateGamepadMappings(string.c_str());
}

GLFW_HPP_API_NODISCARD bool updateGamepadMappings(std::string_view string) {
    return updateGamepadMappings(std::string{string});
}

GLFW_HPP_API_NODISCARD double time() {
    double time = ::glfwGetTime();
    checkError();
    return time;
}

GLFW_HPP_API void setTime(double time) {
    ::glfwSetTime(time);
    checkError();
}

GLFW_HPP_API_NODISCARD std::uint64_t timerValue() {
    std::uint64_t value = ::glfwGetTimerValue();
    checkError();
    return value;
}

GLFW_HPP_API_NODISCARD std::uint64_t timerFrequency() {
    std::uint64_t frequency = ::glfwGetTimerFrequency();
    checkError();
    return frequency;
}

GLFW_HPP_API_NODISCARD Window currentContext() {
    GLFWwindow* window = ::glfwGetCurrentContext();
    checkError();
    return Window{window};
}

GLFW_HPP_API void swapInterval(int interval) {
    ::glfwSwapInterval(interval);
    checkError();
}

GLFW_HPP_API_NODISCARD bool extensionSupported(const char* extension) {
    bool supported = ::glfwExtensionSupported(extension) == GLFW_TRUE;
    checkError();
    return supported;
}

GLFW_HPP_API_NODISCARD bool extensionSupported(const std::string& extension) {
    return extensionSupported(extension.c_str());
}

GLFW_HPP_API_NODISCARD bool extensionSupported(std::string_view extension) {
    return extensionSupported(std::string{extension});
}

GLFW_HPP_EXPORT using ::glfwGetProcAddress;

GLFW_HPP_API_NODISCARD ProcAddress getProcAddress(const char* name) {
    ProcAddress address = ::glfwGetProcAddress(name);
    checkError();
    return address;
}

GLFW_HPP_API_NODISCARD ProcAddress getProcAddress(const std::string& name) {
    return getProcAddress(name.c_str());
}

GLFW_HPP_API_NODISCARD ProcAddress getProcAddress(std::string_view name) {
    return getProcAddress(std::string{name});
}

GLFW_HPP_API_NODISCARD bool vulkanSupported() {
    bool supported = ::glfwVulkanSupported() == GLFW_TRUE;
    checkError();
    return supported;
}

GLFW_HPP_API_NODISCARD std::span<const char*> requiredInstanceExtensions() {
    std::uint32_t count;
    const char** extensions = ::glfwGetRequiredInstanceExtensions(&count);
    checkError();
    return {extensions, extensions + count};
}

GLFW_HPP_API_NODISCARD Cursor createStandardCursor(CursorShape shape) {
    auto cursor = ::glfwCreateStandardCursor(static_cast<int>(shape));
    checkError();
    return Cursor{cursor};
}

GLFW_HPP_API_NODISCARD Cursor createCursor(const Image& image, int xhot, int yhot) {
    auto cursor = ::glfwCreateCursor(&image, xhot, yhot);
    checkError();
    return Cursor{cursor};
}

#ifdef VK_VERSION_1_0

GLFW_HPP_EXPORT using ::glfwGetInstanceProcAddress;

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(::VkInstance instance, const char* name) {
    ProcAddress address = ::glfwGetInstanceProcAddress(instance, name);
    checkError();
    return address;
}

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(::VkInstance instance, const std::string& name) {
    return getInstanceProcAddress(instance, name.c_str());
}

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(::VkInstance instance, std::string_view name) {
    return getInstanceProcAddress(instance, std::string{name});
}

GLFW_HPP_API_NODISCARD bool physicalDevicePresentationSupport(
    ::VkInstance instance,
    ::VkPhysicalDevice device,
    std::uint32_t queueFamily
) {
    bool support = ::glfwGetPhysicalDevicePresentationSupport(instance, device, queueFamily) == GLFW_TRUE;
    checkError();
    return support;
}

#ifdef VULKAN_HANDLES_HPP

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(
    VULKAN_HPP_NAMESPACE::Instance instance,
    const char* name
) {
    return getInstanceProcAddress(static_cast<::VkInstance>(instance), name);
}

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(
    VULKAN_HPP_NAMESPACE::Instance instance,
    const std::string& name
) {
    return getInstanceProcAddress(instance, name.c_str());
}

GLFW_HPP_API_NODISCARD ProcAddress getInstanceProcAddress(
    VULKAN_HPP_NAMESPACE::Instance instance,
    std::string_view name
) {
    return getInstanceProcAddress(instance, std::string{name});
}

GLFW_HPP_API_NODISCARD bool physicalDevicePresentationSupport(
    VULKAN_HPP_NAMESPACE::Instance instance,
    VULKAN_HPP_NAMESPACE::PhysicalDevice device,
    std::uint32_t queueFamily
) {
    return physicalDevicePresentationSupport(static_cast<::VkInstance>(instance), static_cast<::VkPhysicalDevice>(device), queueFamily);
}

#endif // VULKAN_HANDLES_HPP

#endif // VK_VERSION_1_0

// TODO: GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun callback)
}

#endif // GLFW_HPP_DISABLE_HPP


#if defined(GLFW_HPP_MODULE) && defined(GLFW_HPP_MODULE_EXPORT_C_API)

#ifdef GLFW_HPP_C_API_NAMESPACE
namespace GLFW_HPP_C_API_NAMESPACE {
#endif

// !begin_generated
// !generate_c_api
export using ::GLFWmonitor;
export using ::GLFWwindow;
export using ::GLFWcursor;
export using ::GLFWvidmode;
export using ::GLFWgammaramp;
export using ::GLFWimage;
export using ::GLFWgamepadstate;
export using ::GLFWallocator;
export using ::GLFWglproc;
export using ::GLFWvkproc;
export using ::GLFWallocatefun;
export using ::GLFWreallocatefun;
export using ::GLFWdeallocatefun;
export using ::GLFWerrorfun;
export using ::GLFWwindowposfun;
export using ::GLFWwindowsizefun;
export using ::GLFWwindowclosefun;
export using ::GLFWwindowrefreshfun;
export using ::GLFWwindowfocusfun;
export using ::GLFWwindowiconifyfun;
export using ::GLFWwindowmaximizefun;
export using ::GLFWframebuffersizefun;
export using ::GLFWwindowcontentscalefun;
export using ::GLFWmousebuttonfun;
export using ::GLFWcursorposfun;
export using ::GLFWcursorenterfun;
export using ::GLFWscrollfun;
export using ::GLFWkeyfun;
export using ::GLFWcharfun;
export using ::GLFWcharmodsfun;
export using ::GLFWdropfun;
export using ::GLFWmonitorfun;
export using ::GLFWjoystickfun;
export using ::glfwInit;
export using ::glfwTerminate;
export using ::glfwInitHint;
export using ::glfwInitAllocator;
#ifdef VK_VERSION_1_0
export using ::glfwInitVulkanLoader;
#endif // VK_VERSION_1_0
export using ::glfwGetVersion;
export using ::glfwGetVersionString;
export using ::glfwGetError;
export using ::glfwSetErrorCallback;
export using ::glfwGetPlatform;
export using ::glfwPlatformSupported;
export using ::glfwGetMonitors;
export using ::glfwGetPrimaryMonitor;
export using ::glfwGetMonitorPos;
export using ::glfwGetMonitorWorkarea;
export using ::glfwGetMonitorPhysicalSize;
export using ::glfwGetMonitorContentScale;
export using ::glfwGetMonitorName;
export using ::glfwSetMonitorUserPointer;
export using ::glfwGetMonitorUserPointer;
export using ::glfwSetMonitorCallback;
export using ::glfwGetVideoModes;
export using ::glfwGetVideoMode;
export using ::glfwSetGamma;
export using ::glfwGetGammaRamp;
export using ::glfwSetGammaRamp;
export using ::glfwDefaultWindowHints;
export using ::glfwWindowHint;
export using ::glfwWindowHintString;
export using ::glfwCreateWindow;
export using ::glfwDestroyWindow;
export using ::glfwWindowShouldClose;
export using ::glfwSetWindowShouldClose;
export using ::glfwGetWindowTitle;
export using ::glfwSetWindowTitle;
export using ::glfwSetWindowIcon;
export using ::glfwGetWindowPos;
export using ::glfwSetWindowPos;
export using ::glfwGetWindowSize;
export using ::glfwSetWindowSizeLimits;
export using ::glfwSetWindowAspectRatio;
export using ::glfwSetWindowSize;
export using ::glfwGetFramebufferSize;
export using ::glfwGetWindowFrameSize;
export using ::glfwGetWindowContentScale;
export using ::glfwGetWindowOpacity;
export using ::glfwSetWindowOpacity;
export using ::glfwIconifyWindow;
export using ::glfwRestoreWindow;
export using ::glfwMaximizeWindow;
export using ::glfwShowWindow;
export using ::glfwHideWindow;
export using ::glfwFocusWindow;
export using ::glfwRequestWindowAttention;
export using ::glfwGetWindowMonitor;
export using ::glfwSetWindowMonitor;
export using ::glfwGetWindowAttrib;
export using ::glfwSetWindowAttrib;
export using ::glfwSetWindowUserPointer;
export using ::glfwGetWindowUserPointer;
export using ::glfwSetWindowPosCallback;
export using ::glfwSetWindowSizeCallback;
export using ::glfwSetWindowCloseCallback;
export using ::glfwSetWindowRefreshCallback;
export using ::glfwSetWindowFocusCallback;
export using ::glfwSetWindowIconifyCallback;
export using ::glfwSetWindowMaximizeCallback;
export using ::glfwSetFramebufferSizeCallback;
export using ::glfwSetWindowContentScaleCallback;
export using ::glfwPollEvents;
export using ::glfwWaitEvents;
export using ::glfwWaitEventsTimeout;
export using ::glfwPostEmptyEvent;
export using ::glfwGetInputMode;
export using ::glfwSetInputMode;
export using ::glfwRawMouseMotionSupported;
export using ::glfwGetKeyName;
export using ::glfwGetKeyScancode;
export using ::glfwGetKey;
export using ::glfwGetMouseButton;
export using ::glfwGetCursorPos;
export using ::glfwSetCursorPos;
export using ::glfwCreateCursor;
export using ::glfwCreateStandardCursor;
export using ::glfwDestroyCursor;
export using ::glfwSetCursor;
export using ::glfwSetKeyCallback;
export using ::glfwSetCharCallback;
export using ::glfwSetCharModsCallback;
export using ::glfwSetMouseButtonCallback;
export using ::glfwSetCursorPosCallback;
export using ::glfwSetCursorEnterCallback;
export using ::glfwSetScrollCallback;
export using ::glfwSetDropCallback;
export using ::glfwJoystickPresent;
export using ::glfwGetJoystickAxes;
export using ::glfwGetJoystickButtons;
export using ::glfwGetJoystickHats;
export using ::glfwGetJoystickName;
export using ::glfwGetJoystickGUID;
export using ::glfwSetJoystickUserPointer;
export using ::glfwGetJoystickUserPointer;
export using ::glfwJoystickIsGamepad;
export using ::glfwSetJoystickCallback;
export using ::glfwUpdateGamepadMappings;
export using ::glfwGetGamepadName;
export using ::glfwGetGamepadState;
export using ::glfwSetClipboardString;
export using ::glfwGetClipboardString;
export using ::glfwGetTime;
export using ::glfwSetTime;
export using ::glfwGetTimerValue;
export using ::glfwGetTimerFrequency;
export using ::glfwMakeContextCurrent;
export using ::glfwGetCurrentContext;
export using ::glfwSwapBuffers;
export using ::glfwSwapInterval;
export using ::glfwExtensionSupported;
export using ::glfwGetProcAddress;
export using ::glfwVulkanSupported;
export using ::glfwGetRequiredInstanceExtensions;
#ifdef VK_VERSION_1_0
export using ::glfwGetInstanceProcAddress;
#endif // VK_VERSION_1_0
#ifdef VK_VERSION_1_0
export using ::glfwGetPhysicalDevicePresentationSupport;
#endif // VK_VERSION_1_0
#ifdef VK_VERSION_1_0
export using ::glfwCreateWindowSurface;
#endif // VK_VERSION_1_0
#ifdef _glfw3_webgpu_h_
export using ::glfwGetWGPUSurface;
#endif // _glfw3_webgpu_h_
#undef GLFW_VERSION_MAJOR
export constexpr int GLFW_VERSION_MAJOR = 3;
#undef GLFW_VERSION_MINOR
export constexpr int GLFW_VERSION_MINOR = 4;
#undef GLFW_VERSION_REVISION
export constexpr int GLFW_VERSION_REVISION = 0;
#undef GLFW_TRUE
export constexpr int GLFW_TRUE = 1;
#undef GLFW_FALSE
export constexpr int GLFW_FALSE = 0;
#undef GLFW_RELEASE
export constexpr int GLFW_RELEASE = 0;
#undef GLFW_PRESS
export constexpr int GLFW_PRESS = 1;
#undef GLFW_REPEAT
export constexpr int GLFW_REPEAT = 2;
#undef GLFW_HAT_CENTERED
export constexpr int GLFW_HAT_CENTERED = 0;
#undef GLFW_HAT_UP
export constexpr int GLFW_HAT_UP = 1;
#undef GLFW_HAT_RIGHT
export constexpr int GLFW_HAT_RIGHT = 2;
#undef GLFW_HAT_DOWN
export constexpr int GLFW_HAT_DOWN = 4;
#undef GLFW_HAT_LEFT
export constexpr int GLFW_HAT_LEFT = 8;
#undef GLFW_HAT_RIGHT_UP
export constexpr int GLFW_HAT_RIGHT_UP = 3;
#undef GLFW_HAT_RIGHT_DOWN
export constexpr int GLFW_HAT_RIGHT_DOWN = 6;
#undef GLFW_HAT_LEFT_UP
export constexpr int GLFW_HAT_LEFT_UP = 9;
#undef GLFW_HAT_LEFT_DOWN
export constexpr int GLFW_HAT_LEFT_DOWN = 12;
#undef GLFW_KEY_UNKNOWN
export constexpr int GLFW_KEY_UNKNOWN = -1;
#undef GLFW_KEY_SPACE
export constexpr int GLFW_KEY_SPACE = 32;
#undef GLFW_KEY_APOSTROPHE
export constexpr int GLFW_KEY_APOSTROPHE = 39;
#undef GLFW_KEY_COMMA
export constexpr int GLFW_KEY_COMMA = 44;
#undef GLFW_KEY_MINUS
export constexpr int GLFW_KEY_MINUS = 45;
#undef GLFW_KEY_PERIOD
export constexpr int GLFW_KEY_PERIOD = 46;
#undef GLFW_KEY_SLASH
export constexpr int GLFW_KEY_SLASH = 47;
#undef GLFW_KEY_0
export constexpr int GLFW_KEY_0 = 48;
#undef GLFW_KEY_1
export constexpr int GLFW_KEY_1 = 49;
#undef GLFW_KEY_2
export constexpr int GLFW_KEY_2 = 50;
#undef GLFW_KEY_3
export constexpr int GLFW_KEY_3 = 51;
#undef GLFW_KEY_4
export constexpr int GLFW_KEY_4 = 52;
#undef GLFW_KEY_5
export constexpr int GLFW_KEY_5 = 53;
#undef GLFW_KEY_6
export constexpr int GLFW_KEY_6 = 54;
#undef GLFW_KEY_7
export constexpr int GLFW_KEY_7 = 55;
#undef GLFW_KEY_8
export constexpr int GLFW_KEY_8 = 56;
#undef GLFW_KEY_9
export constexpr int GLFW_KEY_9 = 57;
#undef GLFW_KEY_SEMICOLON
export constexpr int GLFW_KEY_SEMICOLON = 59;
#undef GLFW_KEY_EQUAL
export constexpr int GLFW_KEY_EQUAL = 61;
#undef GLFW_KEY_A
export constexpr int GLFW_KEY_A = 65;
#undef GLFW_KEY_B
export constexpr int GLFW_KEY_B = 66;
#undef GLFW_KEY_C
export constexpr int GLFW_KEY_C = 67;
#undef GLFW_KEY_D
export constexpr int GLFW_KEY_D = 68;
#undef GLFW_KEY_E
export constexpr int GLFW_KEY_E = 69;
#undef GLFW_KEY_F
export constexpr int GLFW_KEY_F = 70;
#undef GLFW_KEY_G
export constexpr int GLFW_KEY_G = 71;
#undef GLFW_KEY_H
export constexpr int GLFW_KEY_H = 72;
#undef GLFW_KEY_I
export constexpr int GLFW_KEY_I = 73;
#undef GLFW_KEY_J
export constexpr int GLFW_KEY_J = 74;
#undef GLFW_KEY_K
export constexpr int GLFW_KEY_K = 75;
#undef GLFW_KEY_L
export constexpr int GLFW_KEY_L = 76;
#undef GLFW_KEY_M
export constexpr int GLFW_KEY_M = 77;
#undef GLFW_KEY_N
export constexpr int GLFW_KEY_N = 78;
#undef GLFW_KEY_O
export constexpr int GLFW_KEY_O = 79;
#undef GLFW_KEY_P
export constexpr int GLFW_KEY_P = 80;
#undef GLFW_KEY_Q
export constexpr int GLFW_KEY_Q = 81;
#undef GLFW_KEY_R
export constexpr int GLFW_KEY_R = 82;
#undef GLFW_KEY_S
export constexpr int GLFW_KEY_S = 83;
#undef GLFW_KEY_T
export constexpr int GLFW_KEY_T = 84;
#undef GLFW_KEY_U
export constexpr int GLFW_KEY_U = 85;
#undef GLFW_KEY_V
export constexpr int GLFW_KEY_V = 86;
#undef GLFW_KEY_W
export constexpr int GLFW_KEY_W = 87;
#undef GLFW_KEY_X
export constexpr int GLFW_KEY_X = 88;
#undef GLFW_KEY_Y
export constexpr int GLFW_KEY_Y = 89;
#undef GLFW_KEY_Z
export constexpr int GLFW_KEY_Z = 90;
#undef GLFW_KEY_LEFT_BRACKET
export constexpr int GLFW_KEY_LEFT_BRACKET = 91;
#undef GLFW_KEY_BACKSLASH
export constexpr int GLFW_KEY_BACKSLASH = 92;
#undef GLFW_KEY_RIGHT_BRACKET
export constexpr int GLFW_KEY_RIGHT_BRACKET = 93;
#undef GLFW_KEY_GRAVE_ACCENT
export constexpr int GLFW_KEY_GRAVE_ACCENT = 96;
#undef GLFW_KEY_WORLD_1
export constexpr int GLFW_KEY_WORLD_1 = 161;
#undef GLFW_KEY_WORLD_2
export constexpr int GLFW_KEY_WORLD_2 = 162;
#undef GLFW_KEY_ESCAPE
export constexpr int GLFW_KEY_ESCAPE = 256;
#undef GLFW_KEY_ENTER
export constexpr int GLFW_KEY_ENTER = 257;
#undef GLFW_KEY_TAB
export constexpr int GLFW_KEY_TAB = 258;
#undef GLFW_KEY_BACKSPACE
export constexpr int GLFW_KEY_BACKSPACE = 259;
#undef GLFW_KEY_INSERT
export constexpr int GLFW_KEY_INSERT = 260;
#undef GLFW_KEY_DELETE
export constexpr int GLFW_KEY_DELETE = 261;
#undef GLFW_KEY_RIGHT
export constexpr int GLFW_KEY_RIGHT = 262;
#undef GLFW_KEY_LEFT
export constexpr int GLFW_KEY_LEFT = 263;
#undef GLFW_KEY_DOWN
export constexpr int GLFW_KEY_DOWN = 264;
#undef GLFW_KEY_UP
export constexpr int GLFW_KEY_UP = 265;
#undef GLFW_KEY_PAGE_UP
export constexpr int GLFW_KEY_PAGE_UP = 266;
#undef GLFW_KEY_PAGE_DOWN
export constexpr int GLFW_KEY_PAGE_DOWN = 267;
#undef GLFW_KEY_HOME
export constexpr int GLFW_KEY_HOME = 268;
#undef GLFW_KEY_END
export constexpr int GLFW_KEY_END = 269;
#undef GLFW_KEY_CAPS_LOCK
export constexpr int GLFW_KEY_CAPS_LOCK = 280;
#undef GLFW_KEY_SCROLL_LOCK
export constexpr int GLFW_KEY_SCROLL_LOCK = 281;
#undef GLFW_KEY_NUM_LOCK
export constexpr int GLFW_KEY_NUM_LOCK = 282;
#undef GLFW_KEY_PRINT_SCREEN
export constexpr int GLFW_KEY_PRINT_SCREEN = 283;
#undef GLFW_KEY_PAUSE
export constexpr int GLFW_KEY_PAUSE = 284;
#undef GLFW_KEY_F1
export constexpr int GLFW_KEY_F1 = 290;
#undef GLFW_KEY_F2
export constexpr int GLFW_KEY_F2 = 291;
#undef GLFW_KEY_F3
export constexpr int GLFW_KEY_F3 = 292;
#undef GLFW_KEY_F4
export constexpr int GLFW_KEY_F4 = 293;
#undef GLFW_KEY_F5
export constexpr int GLFW_KEY_F5 = 294;
#undef GLFW_KEY_F6
export constexpr int GLFW_KEY_F6 = 295;
#undef GLFW_KEY_F7
export constexpr int GLFW_KEY_F7 = 296;
#undef GLFW_KEY_F8
export constexpr int GLFW_KEY_F8 = 297;
#undef GLFW_KEY_F9
export constexpr int GLFW_KEY_F9 = 298;
#undef GLFW_KEY_F10
export constexpr int GLFW_KEY_F10 = 299;
#undef GLFW_KEY_F11
export constexpr int GLFW_KEY_F11 = 300;
#undef GLFW_KEY_F12
export constexpr int GLFW_KEY_F12 = 301;
#undef GLFW_KEY_F13
export constexpr int GLFW_KEY_F13 = 302;
#undef GLFW_KEY_F14
export constexpr int GLFW_KEY_F14 = 303;
#undef GLFW_KEY_F15
export constexpr int GLFW_KEY_F15 = 304;
#undef GLFW_KEY_F16
export constexpr int GLFW_KEY_F16 = 305;
#undef GLFW_KEY_F17
export constexpr int GLFW_KEY_F17 = 306;
#undef GLFW_KEY_F18
export constexpr int GLFW_KEY_F18 = 307;
#undef GLFW_KEY_F19
export constexpr int GLFW_KEY_F19 = 308;
#undef GLFW_KEY_F20
export constexpr int GLFW_KEY_F20 = 309;
#undef GLFW_KEY_F21
export constexpr int GLFW_KEY_F21 = 310;
#undef GLFW_KEY_F22
export constexpr int GLFW_KEY_F22 = 311;
#undef GLFW_KEY_F23
export constexpr int GLFW_KEY_F23 = 312;
#undef GLFW_KEY_F24
export constexpr int GLFW_KEY_F24 = 313;
#undef GLFW_KEY_F25
export constexpr int GLFW_KEY_F25 = 314;
#undef GLFW_KEY_KP_0
export constexpr int GLFW_KEY_KP_0 = 320;
#undef GLFW_KEY_KP_1
export constexpr int GLFW_KEY_KP_1 = 321;
#undef GLFW_KEY_KP_2
export constexpr int GLFW_KEY_KP_2 = 322;
#undef GLFW_KEY_KP_3
export constexpr int GLFW_KEY_KP_3 = 323;
#undef GLFW_KEY_KP_4
export constexpr int GLFW_KEY_KP_4 = 324;
#undef GLFW_KEY_KP_5
export constexpr int GLFW_KEY_KP_5 = 325;
#undef GLFW_KEY_KP_6
export constexpr int GLFW_KEY_KP_6 = 326;
#undef GLFW_KEY_KP_7
export constexpr int GLFW_KEY_KP_7 = 327;
#undef GLFW_KEY_KP_8
export constexpr int GLFW_KEY_KP_8 = 328;
#undef GLFW_KEY_KP_9
export constexpr int GLFW_KEY_KP_9 = 329;
#undef GLFW_KEY_KP_DECIMAL
export constexpr int GLFW_KEY_KP_DECIMAL = 330;
#undef GLFW_KEY_KP_DIVIDE
export constexpr int GLFW_KEY_KP_DIVIDE = 331;
#undef GLFW_KEY_KP_MULTIPLY
export constexpr int GLFW_KEY_KP_MULTIPLY = 332;
#undef GLFW_KEY_KP_SUBTRACT
export constexpr int GLFW_KEY_KP_SUBTRACT = 333;
#undef GLFW_KEY_KP_ADD
export constexpr int GLFW_KEY_KP_ADD = 334;
#undef GLFW_KEY_KP_ENTER
export constexpr int GLFW_KEY_KP_ENTER = 335;
#undef GLFW_KEY_KP_EQUAL
export constexpr int GLFW_KEY_KP_EQUAL = 336;
#undef GLFW_KEY_LEFT_SHIFT
export constexpr int GLFW_KEY_LEFT_SHIFT = 340;
#undef GLFW_KEY_LEFT_CONTROL
export constexpr int GLFW_KEY_LEFT_CONTROL = 341;
#undef GLFW_KEY_LEFT_ALT
export constexpr int GLFW_KEY_LEFT_ALT = 342;
#undef GLFW_KEY_LEFT_SUPER
export constexpr int GLFW_KEY_LEFT_SUPER = 343;
#undef GLFW_KEY_RIGHT_SHIFT
export constexpr int GLFW_KEY_RIGHT_SHIFT = 344;
#undef GLFW_KEY_RIGHT_CONTROL
export constexpr int GLFW_KEY_RIGHT_CONTROL = 345;
#undef GLFW_KEY_RIGHT_ALT
export constexpr int GLFW_KEY_RIGHT_ALT = 346;
#undef GLFW_KEY_RIGHT_SUPER
export constexpr int GLFW_KEY_RIGHT_SUPER = 347;
#undef GLFW_KEY_MENU
export constexpr int GLFW_KEY_MENU = 348;
#undef GLFW_KEY_LAST
export constexpr int GLFW_KEY_LAST = 348;
#undef GLFW_MOD_SHIFT
export constexpr int GLFW_MOD_SHIFT = 1;
#undef GLFW_MOD_CONTROL
export constexpr int GLFW_MOD_CONTROL = 2;
#undef GLFW_MOD_ALT
export constexpr int GLFW_MOD_ALT = 4;
#undef GLFW_MOD_SUPER
export constexpr int GLFW_MOD_SUPER = 8;
#undef GLFW_MOD_CAPS_LOCK
export constexpr int GLFW_MOD_CAPS_LOCK = 16;
#undef GLFW_MOD_NUM_LOCK
export constexpr int GLFW_MOD_NUM_LOCK = 32;
#undef GLFW_MOUSE_BUTTON_1
export constexpr int GLFW_MOUSE_BUTTON_1 = 0;
#undef GLFW_MOUSE_BUTTON_2
export constexpr int GLFW_MOUSE_BUTTON_2 = 1;
#undef GLFW_MOUSE_BUTTON_3
export constexpr int GLFW_MOUSE_BUTTON_3 = 2;
#undef GLFW_MOUSE_BUTTON_4
export constexpr int GLFW_MOUSE_BUTTON_4 = 3;
#undef GLFW_MOUSE_BUTTON_5
export constexpr int GLFW_MOUSE_BUTTON_5 = 4;
#undef GLFW_MOUSE_BUTTON_6
export constexpr int GLFW_MOUSE_BUTTON_6 = 5;
#undef GLFW_MOUSE_BUTTON_7
export constexpr int GLFW_MOUSE_BUTTON_7 = 6;
#undef GLFW_MOUSE_BUTTON_8
export constexpr int GLFW_MOUSE_BUTTON_8 = 7;
#undef GLFW_MOUSE_BUTTON_LAST
export constexpr int GLFW_MOUSE_BUTTON_LAST = 7;
#undef GLFW_MOUSE_BUTTON_LEFT
export constexpr int GLFW_MOUSE_BUTTON_LEFT = 0;
#undef GLFW_MOUSE_BUTTON_RIGHT
export constexpr int GLFW_MOUSE_BUTTON_RIGHT = 1;
#undef GLFW_MOUSE_BUTTON_MIDDLE
export constexpr int GLFW_MOUSE_BUTTON_MIDDLE = 2;
#undef GLFW_JOYSTICK_1
export constexpr int GLFW_JOYSTICK_1 = 0;
#undef GLFW_JOYSTICK_2
export constexpr int GLFW_JOYSTICK_2 = 1;
#undef GLFW_JOYSTICK_3
export constexpr int GLFW_JOYSTICK_3 = 2;
#undef GLFW_JOYSTICK_4
export constexpr int GLFW_JOYSTICK_4 = 3;
#undef GLFW_JOYSTICK_5
export constexpr int GLFW_JOYSTICK_5 = 4;
#undef GLFW_JOYSTICK_6
export constexpr int GLFW_JOYSTICK_6 = 5;
#undef GLFW_JOYSTICK_7
export constexpr int GLFW_JOYSTICK_7 = 6;
#undef GLFW_JOYSTICK_8
export constexpr int GLFW_JOYSTICK_8 = 7;
#undef GLFW_JOYSTICK_9
export constexpr int GLFW_JOYSTICK_9 = 8;
#undef GLFW_JOYSTICK_10
export constexpr int GLFW_JOYSTICK_10 = 9;
#undef GLFW_JOYSTICK_11
export constexpr int GLFW_JOYSTICK_11 = 10;
#undef GLFW_JOYSTICK_12
export constexpr int GLFW_JOYSTICK_12 = 11;
#undef GLFW_JOYSTICK_13
export constexpr int GLFW_JOYSTICK_13 = 12;
#undef GLFW_JOYSTICK_14
export constexpr int GLFW_JOYSTICK_14 = 13;
#undef GLFW_JOYSTICK_15
export constexpr int GLFW_JOYSTICK_15 = 14;
#undef GLFW_JOYSTICK_16
export constexpr int GLFW_JOYSTICK_16 = 15;
#undef GLFW_JOYSTICK_LAST
export constexpr int GLFW_JOYSTICK_LAST = 15;
#undef GLFW_GAMEPAD_BUTTON_A
export constexpr int GLFW_GAMEPAD_BUTTON_A = 0;
#undef GLFW_GAMEPAD_BUTTON_B
export constexpr int GLFW_GAMEPAD_BUTTON_B = 1;
#undef GLFW_GAMEPAD_BUTTON_X
export constexpr int GLFW_GAMEPAD_BUTTON_X = 2;
#undef GLFW_GAMEPAD_BUTTON_Y
export constexpr int GLFW_GAMEPAD_BUTTON_Y = 3;
#undef GLFW_GAMEPAD_BUTTON_LEFT_BUMPER
export constexpr int GLFW_GAMEPAD_BUTTON_LEFT_BUMPER = 4;
#undef GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER
export constexpr int GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER = 5;
#undef GLFW_GAMEPAD_BUTTON_BACK
export constexpr int GLFW_GAMEPAD_BUTTON_BACK = 6;
#undef GLFW_GAMEPAD_BUTTON_START
export constexpr int GLFW_GAMEPAD_BUTTON_START = 7;
#undef GLFW_GAMEPAD_BUTTON_GUIDE
export constexpr int GLFW_GAMEPAD_BUTTON_GUIDE = 8;
#undef GLFW_GAMEPAD_BUTTON_LEFT_THUMB
export constexpr int GLFW_GAMEPAD_BUTTON_LEFT_THUMB = 9;
#undef GLFW_GAMEPAD_BUTTON_RIGHT_THUMB
export constexpr int GLFW_GAMEPAD_BUTTON_RIGHT_THUMB = 10;
#undef GLFW_GAMEPAD_BUTTON_DPAD_UP
export constexpr int GLFW_GAMEPAD_BUTTON_DPAD_UP = 11;
#undef GLFW_GAMEPAD_BUTTON_DPAD_RIGHT
export constexpr int GLFW_GAMEPAD_BUTTON_DPAD_RIGHT = 12;
#undef GLFW_GAMEPAD_BUTTON_DPAD_DOWN
export constexpr int GLFW_GAMEPAD_BUTTON_DPAD_DOWN = 13;
#undef GLFW_GAMEPAD_BUTTON_DPAD_LEFT
export constexpr int GLFW_GAMEPAD_BUTTON_DPAD_LEFT = 14;
#undef GLFW_GAMEPAD_BUTTON_LAST
export constexpr int GLFW_GAMEPAD_BUTTON_LAST = 14;
#undef GLFW_GAMEPAD_BUTTON_CROSS
export constexpr int GLFW_GAMEPAD_BUTTON_CROSS = 0;
#undef GLFW_GAMEPAD_BUTTON_CIRCLE
export constexpr int GLFW_GAMEPAD_BUTTON_CIRCLE = 1;
#undef GLFW_GAMEPAD_BUTTON_SQUARE
export constexpr int GLFW_GAMEPAD_BUTTON_SQUARE = 2;
#undef GLFW_GAMEPAD_BUTTON_TRIANGLE
export constexpr int GLFW_GAMEPAD_BUTTON_TRIANGLE = 3;
#undef GLFW_GAMEPAD_AXIS_LEFT_X
export constexpr int GLFW_GAMEPAD_AXIS_LEFT_X = 0;
#undef GLFW_GAMEPAD_AXIS_LEFT_Y
export constexpr int GLFW_GAMEPAD_AXIS_LEFT_Y = 1;
#undef GLFW_GAMEPAD_AXIS_RIGHT_X
export constexpr int GLFW_GAMEPAD_AXIS_RIGHT_X = 2;
#undef GLFW_GAMEPAD_AXIS_RIGHT_Y
export constexpr int GLFW_GAMEPAD_AXIS_RIGHT_Y = 3;
#undef GLFW_GAMEPAD_AXIS_LEFT_TRIGGER
export constexpr int GLFW_GAMEPAD_AXIS_LEFT_TRIGGER = 4;
#undef GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER
export constexpr int GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER = 5;
#undef GLFW_GAMEPAD_AXIS_LAST
export constexpr int GLFW_GAMEPAD_AXIS_LAST = 5;
#undef GLFW_NO_ERROR
export constexpr int GLFW_NO_ERROR = 0;
#undef GLFW_NOT_INITIALIZED
export constexpr int GLFW_NOT_INITIALIZED = 65537;
#undef GLFW_NO_CURRENT_CONTEXT
export constexpr int GLFW_NO_CURRENT_CONTEXT = 65538;
#undef GLFW_INVALID_ENUM
export constexpr int GLFW_INVALID_ENUM = 65539;
#undef GLFW_INVALID_VALUE
export constexpr int GLFW_INVALID_VALUE = 65540;
#undef GLFW_OUT_OF_MEMORY
export constexpr int GLFW_OUT_OF_MEMORY = 65541;
#undef GLFW_API_UNAVAILABLE
export constexpr int GLFW_API_UNAVAILABLE = 65542;
#undef GLFW_VERSION_UNAVAILABLE
export constexpr int GLFW_VERSION_UNAVAILABLE = 65543;
#undef GLFW_PLATFORM_ERROR
export constexpr int GLFW_PLATFORM_ERROR = 65544;
#undef GLFW_FORMAT_UNAVAILABLE
export constexpr int GLFW_FORMAT_UNAVAILABLE = 65545;
#undef GLFW_NO_WINDOW_CONTEXT
export constexpr int GLFW_NO_WINDOW_CONTEXT = 65546;
#undef GLFW_CURSOR_UNAVAILABLE
export constexpr int GLFW_CURSOR_UNAVAILABLE = 65547;
#undef GLFW_FEATURE_UNAVAILABLE
export constexpr int GLFW_FEATURE_UNAVAILABLE = 65548;
#undef GLFW_FEATURE_UNIMPLEMENTED
export constexpr int GLFW_FEATURE_UNIMPLEMENTED = 65549;
#undef GLFW_PLATFORM_UNAVAILABLE
export constexpr int GLFW_PLATFORM_UNAVAILABLE = 65550;
#undef GLFW_FOCUSED
export constexpr int GLFW_FOCUSED = 131073;
#undef GLFW_ICONIFIED
export constexpr int GLFW_ICONIFIED = 131074;
#undef GLFW_RESIZABLE
export constexpr int GLFW_RESIZABLE = 131075;
#undef GLFW_VISIBLE
export constexpr int GLFW_VISIBLE = 131076;
#undef GLFW_DECORATED
export constexpr int GLFW_DECORATED = 131077;
#undef GLFW_AUTO_ICONIFY
export constexpr int GLFW_AUTO_ICONIFY = 131078;
#undef GLFW_FLOATING
export constexpr int GLFW_FLOATING = 131079;
#undef GLFW_MAXIMIZED
export constexpr int GLFW_MAXIMIZED = 131080;
#undef GLFW_CENTER_CURSOR
export constexpr int GLFW_CENTER_CURSOR = 131081;
#undef GLFW_TRANSPARENT_FRAMEBUFFER
export constexpr int GLFW_TRANSPARENT_FRAMEBUFFER = 131082;
#undef GLFW_HOVERED
export constexpr int GLFW_HOVERED = 131083;
#undef GLFW_FOCUS_ON_SHOW
export constexpr int GLFW_FOCUS_ON_SHOW = 131084;
#undef GLFW_MOUSE_PASSTHROUGH
export constexpr int GLFW_MOUSE_PASSTHROUGH = 131085;
#undef GLFW_POSITION_X
export constexpr int GLFW_POSITION_X = 131086;
#undef GLFW_POSITION_Y
export constexpr int GLFW_POSITION_Y = 131087;
#undef GLFW_RED_BITS
export constexpr int GLFW_RED_BITS = 135169;
#undef GLFW_GREEN_BITS
export constexpr int GLFW_GREEN_BITS = 135170;
#undef GLFW_BLUE_BITS
export constexpr int GLFW_BLUE_BITS = 135171;
#undef GLFW_ALPHA_BITS
export constexpr int GLFW_ALPHA_BITS = 135172;
#undef GLFW_DEPTH_BITS
export constexpr int GLFW_DEPTH_BITS = 135173;
#undef GLFW_STENCIL_BITS
export constexpr int GLFW_STENCIL_BITS = 135174;
#undef GLFW_ACCUM_RED_BITS
export constexpr int GLFW_ACCUM_RED_BITS = 135175;
#undef GLFW_ACCUM_GREEN_BITS
export constexpr int GLFW_ACCUM_GREEN_BITS = 135176;
#undef GLFW_ACCUM_BLUE_BITS
export constexpr int GLFW_ACCUM_BLUE_BITS = 135177;
#undef GLFW_ACCUM_ALPHA_BITS
export constexpr int GLFW_ACCUM_ALPHA_BITS = 135178;
#undef GLFW_AUX_BUFFERS
export constexpr int GLFW_AUX_BUFFERS = 135179;
#undef GLFW_STEREO
export constexpr int GLFW_STEREO = 135180;
#undef GLFW_SAMPLES
export constexpr int GLFW_SAMPLES = 135181;
#undef GLFW_SRGB_CAPABLE
export constexpr int GLFW_SRGB_CAPABLE = 135182;
#undef GLFW_REFRESH_RATE
export constexpr int GLFW_REFRESH_RATE = 135183;
#undef GLFW_DOUBLEBUFFER
export constexpr int GLFW_DOUBLEBUFFER = 135184;
#undef GLFW_CLIENT_API
export constexpr int GLFW_CLIENT_API = 139265;
#undef GLFW_CONTEXT_VERSION_MAJOR
export constexpr int GLFW_CONTEXT_VERSION_MAJOR = 139266;
#undef GLFW_CONTEXT_VERSION_MINOR
export constexpr int GLFW_CONTEXT_VERSION_MINOR = 139267;
#undef GLFW_CONTEXT_REVISION
export constexpr int GLFW_CONTEXT_REVISION = 139268;
#undef GLFW_CONTEXT_ROBUSTNESS
export constexpr int GLFW_CONTEXT_ROBUSTNESS = 139269;
#undef GLFW_OPENGL_FORWARD_COMPAT
export constexpr int GLFW_OPENGL_FORWARD_COMPAT = 139270;
#undef GLFW_CONTEXT_DEBUG
export constexpr int GLFW_CONTEXT_DEBUG = 139271;
#undef GLFW_OPENGL_DEBUG_CONTEXT
export constexpr int GLFW_OPENGL_DEBUG_CONTEXT = 139271;
#undef GLFW_OPENGL_PROFILE
export constexpr int GLFW_OPENGL_PROFILE = 139272;
#undef GLFW_CONTEXT_RELEASE_BEHAVIOR
export constexpr int GLFW_CONTEXT_RELEASE_BEHAVIOR = 139273;
#undef GLFW_CONTEXT_NO_ERROR
export constexpr int GLFW_CONTEXT_NO_ERROR = 139274;
#undef GLFW_CONTEXT_CREATION_API
export constexpr int GLFW_CONTEXT_CREATION_API = 139275;
#undef GLFW_SCALE_TO_MONITOR
export constexpr int GLFW_SCALE_TO_MONITOR = 139276;
#undef GLFW_SCALE_FRAMEBUFFER
export constexpr int GLFW_SCALE_FRAMEBUFFER = 139277;
#undef GLFW_COCOA_RETINA_FRAMEBUFFER
export constexpr int GLFW_COCOA_RETINA_FRAMEBUFFER = 143361;
#undef GLFW_COCOA_FRAME_NAME
export constexpr int GLFW_COCOA_FRAME_NAME = 143362;
#undef GLFW_COCOA_GRAPHICS_SWITCHING
export constexpr int GLFW_COCOA_GRAPHICS_SWITCHING = 143363;
#undef GLFW_X11_CLASS_NAME
export constexpr int GLFW_X11_CLASS_NAME = 147457;
#undef GLFW_X11_INSTANCE_NAME
export constexpr int GLFW_X11_INSTANCE_NAME = 147458;
#undef GLFW_WIN32_KEYBOARD_MENU
export constexpr int GLFW_WIN32_KEYBOARD_MENU = 151553;
#undef GLFW_WIN32_SHOWDEFAULT
export constexpr int GLFW_WIN32_SHOWDEFAULT = 151554;
#undef GLFW_WAYLAND_APP_ID
export constexpr int GLFW_WAYLAND_APP_ID = 155649;
#undef GLFW_NO_API
export constexpr int GLFW_NO_API = 0;
#undef GLFW_OPENGL_API
export constexpr int GLFW_OPENGL_API = 196609;
#undef GLFW_OPENGL_ES_API
export constexpr int GLFW_OPENGL_ES_API = 196610;
#undef GLFW_NO_ROBUSTNESS
export constexpr int GLFW_NO_ROBUSTNESS = 0;
#undef GLFW_NO_RESET_NOTIFICATION
export constexpr int GLFW_NO_RESET_NOTIFICATION = 200705;
#undef GLFW_LOSE_CONTEXT_ON_RESET
export constexpr int GLFW_LOSE_CONTEXT_ON_RESET = 200706;
#undef GLFW_OPENGL_ANY_PROFILE
export constexpr int GLFW_OPENGL_ANY_PROFILE = 0;
#undef GLFW_OPENGL_CORE_PROFILE
export constexpr int GLFW_OPENGL_CORE_PROFILE = 204801;
#undef GLFW_OPENGL_COMPAT_PROFILE
export constexpr int GLFW_OPENGL_COMPAT_PROFILE = 204802;
#undef GLFW_CURSOR
export constexpr int GLFW_CURSOR = 208897;
#undef GLFW_STICKY_KEYS
export constexpr int GLFW_STICKY_KEYS = 208898;
#undef GLFW_STICKY_MOUSE_BUTTONS
export constexpr int GLFW_STICKY_MOUSE_BUTTONS = 208899;
#undef GLFW_LOCK_KEY_MODS
export constexpr int GLFW_LOCK_KEY_MODS = 208900;
#undef GLFW_RAW_MOUSE_MOTION
export constexpr int GLFW_RAW_MOUSE_MOTION = 208901;
#undef GLFW_CURSOR_NORMAL
export constexpr int GLFW_CURSOR_NORMAL = 212993;
#undef GLFW_CURSOR_HIDDEN
export constexpr int GLFW_CURSOR_HIDDEN = 212994;
#undef GLFW_CURSOR_DISABLED
export constexpr int GLFW_CURSOR_DISABLED = 212995;
#undef GLFW_CURSOR_CAPTURED
export constexpr int GLFW_CURSOR_CAPTURED = 212996;
#undef GLFW_ANY_RELEASE_BEHAVIOR
export constexpr int GLFW_ANY_RELEASE_BEHAVIOR = 0;
#undef GLFW_RELEASE_BEHAVIOR_FLUSH
export constexpr int GLFW_RELEASE_BEHAVIOR_FLUSH = 217089;
#undef GLFW_RELEASE_BEHAVIOR_NONE
export constexpr int GLFW_RELEASE_BEHAVIOR_NONE = 217090;
#undef GLFW_NATIVE_CONTEXT_API
export constexpr int GLFW_NATIVE_CONTEXT_API = 221185;
#undef GLFW_EGL_CONTEXT_API
export constexpr int GLFW_EGL_CONTEXT_API = 221186;
#undef GLFW_OSMESA_CONTEXT_API
export constexpr int GLFW_OSMESA_CONTEXT_API = 221187;
#undef GLFW_ANGLE_PLATFORM_TYPE_NONE
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_NONE = 225281;
#undef GLFW_ANGLE_PLATFORM_TYPE_OPENGL
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_OPENGL = 225282;
#undef GLFW_ANGLE_PLATFORM_TYPE_OPENGLES
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_OPENGLES = 225283;
#undef GLFW_ANGLE_PLATFORM_TYPE_D3D9
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_D3D9 = 225284;
#undef GLFW_ANGLE_PLATFORM_TYPE_D3D11
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_D3D11 = 225285;
#undef GLFW_ANGLE_PLATFORM_TYPE_VULKAN
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_VULKAN = 225287;
#undef GLFW_ANGLE_PLATFORM_TYPE_METAL
export constexpr int GLFW_ANGLE_PLATFORM_TYPE_METAL = 225288;
#undef GLFW_WAYLAND_PREFER_LIBDECOR
export constexpr int GLFW_WAYLAND_PREFER_LIBDECOR = 229377;
#undef GLFW_WAYLAND_DISABLE_LIBDECOR
export constexpr int GLFW_WAYLAND_DISABLE_LIBDECOR = 229378;
#undef GLFW_ANY_POSITION
export constexpr int GLFW_ANY_POSITION = -2147483648;
#undef GLFW_ARROW_CURSOR
export constexpr int GLFW_ARROW_CURSOR = 221185;
#undef GLFW_IBEAM_CURSOR
export constexpr int GLFW_IBEAM_CURSOR = 221186;
#undef GLFW_CROSSHAIR_CURSOR
export constexpr int GLFW_CROSSHAIR_CURSOR = 221187;
#undef GLFW_POINTING_HAND_CURSOR
export constexpr int GLFW_POINTING_HAND_CURSOR = 221188;
#undef GLFW_RESIZE_EW_CURSOR
export constexpr int GLFW_RESIZE_EW_CURSOR = 221189;
#undef GLFW_RESIZE_NS_CURSOR
export constexpr int GLFW_RESIZE_NS_CURSOR = 221190;
#undef GLFW_RESIZE_NWSE_CURSOR
export constexpr int GLFW_RESIZE_NWSE_CURSOR = 221191;
#undef GLFW_RESIZE_NESW_CURSOR
export constexpr int GLFW_RESIZE_NESW_CURSOR = 221192;
#undef GLFW_RESIZE_ALL_CURSOR
export constexpr int GLFW_RESIZE_ALL_CURSOR = 221193;
#undef GLFW_NOT_ALLOWED_CURSOR
export constexpr int GLFW_NOT_ALLOWED_CURSOR = 221194;
#undef GLFW_HRESIZE_CURSOR
export constexpr int GLFW_HRESIZE_CURSOR = 221189;
#undef GLFW_VRESIZE_CURSOR
export constexpr int GLFW_VRESIZE_CURSOR = 221190;
#undef GLFW_HAND_CURSOR
export constexpr int GLFW_HAND_CURSOR = 221188;
#undef GLFW_CONNECTED
export constexpr int GLFW_CONNECTED = 262145;
#undef GLFW_DISCONNECTED
export constexpr int GLFW_DISCONNECTED = 262146;
#undef GLFW_JOYSTICK_HAT_BUTTONS
export constexpr int GLFW_JOYSTICK_HAT_BUTTONS = 327681;
#undef GLFW_ANGLE_PLATFORM_TYPE
export constexpr int GLFW_ANGLE_PLATFORM_TYPE = 327682;
#undef GLFW_PLATFORM
export constexpr int GLFW_PLATFORM = 327683;
#undef GLFW_COCOA_CHDIR_RESOURCES
export constexpr int GLFW_COCOA_CHDIR_RESOURCES = 331777;
#undef GLFW_COCOA_MENUBAR
export constexpr int GLFW_COCOA_MENUBAR = 331778;
#undef GLFW_X11_XCB_VULKAN_SURFACE
export constexpr int GLFW_X11_XCB_VULKAN_SURFACE = 335873;
#undef GLFW_WAYLAND_LIBDECOR
export constexpr int GLFW_WAYLAND_LIBDECOR = 339969;
#undef GLFW_ANY_PLATFORM
export constexpr int GLFW_ANY_PLATFORM = 393216;
#undef GLFW_PLATFORM_WIN32
export constexpr int GLFW_PLATFORM_WIN32 = 393217;
#undef GLFW_PLATFORM_COCOA
export constexpr int GLFW_PLATFORM_COCOA = 393218;
#undef GLFW_PLATFORM_WAYLAND
export constexpr int GLFW_PLATFORM_WAYLAND = 393219;
#undef GLFW_PLATFORM_X11
export constexpr int GLFW_PLATFORM_X11 = 393220;
#undef GLFW_PLATFORM_NULL
export constexpr int GLFW_PLATFORM_NULL = 393221;
#undef GLFW_DONT_CARE
export constexpr int GLFW_DONT_CARE = -1;
// !end_generated

#ifdef GLFW_HPP_C_API_NAMESPACE
}
#endif

#endif

#endif // GLFW_HPP_INCLUDED
