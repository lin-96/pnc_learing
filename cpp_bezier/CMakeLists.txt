cmake_minimum_required(VERSION 3.5.1)

project(cpp_bezier)

find_package(PythonLibs 2.7)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}
        ./include/matplotlib-cpp/
)

add_executable(cpp_bezier src/cpp_bezier.cpp)

target_link_libraries(cpp_bezier ${PYTHON_LIBRARIES})
