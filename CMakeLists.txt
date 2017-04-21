cmake_minimum_required(VERSION 3.7)
project(Image_Editor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Editor.cpp Editor.h)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARIES})
add_executable(Image_Editor ${SOURCE_FILES})
target_link_libraries(Image_Editor ${OpenCV_LIBRARIES})