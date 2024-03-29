cmake_minimum_required(VERSION 3.15)

project(Golem LANGUAGES CXX)

find_package(SDL2 REQUIRED CONFIG)
find_package(bgfx REQUIRED CONFIG)
find_package(imgui REQUIRED CONFIG)

add_executable(${PROJECT_NAME})
file(GLOB CPP_FILES src/*.cpp)
target_sources(
    ${PROJECT_NAME} PRIVATE
    ${CPP_FILES}
    sdl-imgui/imgui_impl_sdl.cpp
    bgfx-imgui/imgui_impl_bgfx.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    bgfx::bgfx
    imgui::imgui
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

# required for project when using visual studio generator
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

if (WIN32)
# copy the SDL2.dll to the same folder as the executable
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
    VERBATIM)
endif()
