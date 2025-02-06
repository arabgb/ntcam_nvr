cmake_minimum_required(VERSION 3.15.0)

project(ntcam_nvr VERSION 0.0.1)

# custom variables
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# for nvim to work with cmake include directory we should 
# tell cmake to generate compile_command.json, then ln it to root source 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# required packages
find_package(OpenCV REQUIRED)
find_package(SQLite3 REQUIRED)

#  adding my subdirectory and its include path
add_subdirectory(${PROJECT_SOURCE_DIR}/database)
include_directories(${PROJECT_SOURCE_DIR}/database)

add_executable(ntcam_nvr ${PROJECT_SOURCE_DIR}/main.cpp)


target_link_libraries(ntcam_nvr PUBLIC database PRIVATE ${OpenCV_LIBS})
