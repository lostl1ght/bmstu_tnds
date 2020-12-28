cmake_minimum_required(VERSION 3.16)
project(tads_lab_06)

set(LIBS "-lm")

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS_RELEASE   "-std=c99 -Wall -Wextra -Wpedantic -Werror -g0")
set(CMAKE_C_FLAGS_DEBUG  "-std=c99 -Wall -Wextra -Wpedantic -Werror -ggdb")

set(CMAKE_VERBOSE_MAKEFILE on)

include_directories(inc)
aux_source_directory(src SRC)
add_executable(lab_06 ${SRC})

target_link_libraries(lab_06 "-lm")
