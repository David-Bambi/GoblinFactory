cmake_minimum_required (VERSION 3.10)

# Project informations
set(APP_NAME GF)
set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)

# Add the project
project(${APP_NAME} VERSION ${MAJOR_VERSION}.${MINOR_VERSION})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configure header file
configure_file(Config.h.in Config.h)

# Add files for the project
add_executable(${APP_NAME} src/gf.cpp src/glad.c)

target_link_libraries(${APP_NAME} D:/Developpement/GoblinFactory/libs/glfw3.dll)

# Add source directory
add_subdirectory(src)

# Add the include directory
target_include_directories( ${APP_NAME} PUBLIC
  "include"
  "${PROJECT_BINARY_DIR}")



