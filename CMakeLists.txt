cmake_minimum_required(VERSION 3.17)
project(3_sem_lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(3_sem_lab_1 main.cpp LinkList.h ListElem.h Sequence.h ArraySequence.h ListSequence.h dynamicArray.hpp Sorters/ISorter.h Sorters/MergeSorter.h Sorters/Comparator.h Sorters/QuickSorter.h Sorters/ShellSorter.h Sorters/HeapSorter.h)

add_subdirectory(Google_tests)