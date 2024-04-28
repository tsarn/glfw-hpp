cmake_minimum_required(VERSION 3.28)
project(glfw-hpp VERSION 3.4 LANGUAGES C CXX)

if (NOT TARGET glfw)
    find_package(glfw3 3.4 REQUIRED)
endif()

add_library(glfw-hpp INTERFACE)
target_include_directories(glfw-hpp INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
target_link_libraries(glfw-hpp INTERFACE glfw)
target_compile_features(glfw-hpp INTERFACE cxx_std_17)
target_sources(glfw-hpp INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
        "./include/glfw-hpp/glfw.hpp"
)

add_library(glfw-hpp-module STATIC)
target_sources(glfw-hpp-module PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    BASE_DIRS include
    FILES
        "./include/glfw-hpp/glfw.cppm"
)
target_link_libraries(glfw-hpp-module PUBLIC glfw-hpp)
target_compile_features(glfw-hpp-module PUBLIC cxx_std_20)

add_library(glfw-hpp-c-module STATIC)
target_sources(glfw-hpp-c-module PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    BASE_DIRS include
    FILES
        "./include/glfw-hpp/glfw_c.cppm"
)
target_link_libraries(glfw-hpp-c-module PUBLIC glfw-hpp)
target_compile_features(glfw-hpp-c-module PUBLIC cxx_std_20)


include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    glfw-hpp-config-version.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    TARGETS
        glfw-hpp
        glfw-hpp-module
        glfw-hpp-c-module
    EXPORT
        glfw-hpp-targets
    FILE_SET HEADERS DESTINATION include
    FILE_SET CXX_MODULES DESTINATION include
)

install(
    EXPORT
        glfw-hpp-targets
    FILE
        glfw-hpp-targets.cmake
    NAMESPACE
        glfw-hpp::
    DESTINATION
        lib/cmake/glfw-hpp
)

configure_file(cmake/glfw-hpp-config.cmake.in glfw-hpp-config.cmake @ONLY)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/glfw-hpp-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/glfw-hpp-config-version.cmake"
    DESTINATION
        lib/cmake/glfw-hpp
)