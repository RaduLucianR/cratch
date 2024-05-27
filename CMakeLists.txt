cmake_minimum_required(VERSION 3.28)

project(cratch
  VERSION
    1.0
  DESCRIPTION
    "Very nice project"
  LANGUAGES
    C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main
               src/main.c
               src/stack.c
               )
