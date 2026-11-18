cmake_minimum_required(VERSION 3.16)
project(doom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main
main.cpp
src/draw.cpp
src/funcHelp.cpp
src/globals.cpp
src/player.cpp
src/headers/draw.h
src/headers/funcHelp.h
src/headers/globals.h
src/headers/player.h
src/headers/vector2.hpp
)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

target_include_directories(main
  PRIVATE src/
src/headers)

target_link_libraries(
  main
  SDL3::SDL3
  SDL3_image::SDL3_image
)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "doom Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for doom
set(doom_Version_Major 0)
set(doom_Version_Minor 1)
set(doom_Version_Patch 1)
set(doom_Version_Status "-dev")
set(PROJECT_VERSION
  "${doom_Version_Major}.${doom_Version_Minor}.${doom_Version_Patch}${doom_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")
