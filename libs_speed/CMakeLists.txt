cmake_minimum_required(VERSION 3.30.4)

project(libs_speed CXX)

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(newton_method_src newton_method.h newton_method.cpp)

add_library(newton_method_shared SHARED ${newton_method_src})
add_library(newton_method_static STATIC ${newton_method_src})
add_library(newton_method_interface INTERFACE ${newton_method_src})

add_executable(libs_speed_shared main.cpp)
target_link_libraries(libs_speed_shared PRIVATE newton_method_shared)

add_executable(libs_speed_static main.cpp)
target_link_libraries(libs_speed_static PRIVATE newton_method_static)