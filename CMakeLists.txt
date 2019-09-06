cmake_minimum_required(VERSION 3.12)
project(STLTest)

set(CMAKE_CXX_STANDARD 14)
add_executable(STLTest1 main.cpp)
add_executable(STLTest2 effective.cpp)
add_executable(STLTest3 functor.cpp)
add_executable(STLTest4 Modifying_Algorithms.cpp)
add_executable(STLTest5 Non_modifying_Algorithms.cpp)
add_executable(STLTest6 nowcoder.cpp)
add_executable(STLTest7 stream1.cpp)


