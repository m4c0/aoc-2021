cmake_minimum_required(VERSION 3.18)
project(aoc-2021 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(exe NAME)
  add_executable(${NAME} ${NAME}.cpp)
  target_compile_features(${NAME} PRIVATE cxx_std_20)
endfunction()

exe(day1a)
exe(day1b)
