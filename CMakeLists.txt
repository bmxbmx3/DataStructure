cmake_minimum_required(VERSION 3.15)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure main.c linear_list.c linear_list.h stack_and_queue.c stack_and_queue.h tree.c tree.h sort.c sort.h graph.c graph.h)