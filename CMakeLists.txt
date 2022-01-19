cmake_minimum_required(VERSION 3.21)
project(sorts)

set(CMAKE_CXX_STANDARD 20)

add_executable(sorts main.cpp insertionSortWithBinarySearch.hpp directionUtility.hpp heapSort.hpp countingSort.hpp directionUtility.cpp timer.cpp)
