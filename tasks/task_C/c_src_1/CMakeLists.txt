cmake_minimum_required(VERSION 3.10)
project(task_C_1 C)

add_executable(task_C_solution_1
    solution.c
)
target_compile_options(task_C_solution_1 PUBLIC -O3 -g -Wall -Werror -Wextra -Wpedantic)