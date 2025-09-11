cmake_minimum_required(VERSION 3.10)
project(task_C_1 C)

add_executable(task_C_solution_1
    solution.c
)

target_compile_options(task_C_solution_1 PUBLIC -O3 -g -Wall -Werror -Wextra -Wpedantic -fno-omit-frame-pointer
        -fsanitize=address,object-size,alignment,pointer-compare,bool,pointer-overflow,bounds,pointer-subtract,bounds-strict,return,builtin,returns-nonnull-attribute,enum,float-cast-overflow,shift,float-divide-by-zero,shift-base,shift-exponent,integer-divide-by-zero,signed-integer-overflow,undefined,leak,unreachable,nonnull-attribute,vla-bound,null,vptr)

target_link_options(task_C_solution_1 PUBLIC
        -O3 -g -Wall -Werror -Wextra -Wpedantic -fno-omit-frame-pointer
        -fsanitize=address,object-size,alignment,pointer-compare,bool,pointer-overflow,bounds,pointer-subtract,bounds-strict,return,builtin,returns-nonnull-attribute,enum,float-cast-overflow,shift,float-divide-by-zero,shift-base,shift-exponent,integer-divide-by-zero,signed-integer-overflow,undefined,leak,unreachable,nonnull-attribute,vla-bound,null,vptr
)