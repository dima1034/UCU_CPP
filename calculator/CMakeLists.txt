cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Action.cpp Action.h ActionExecution.cpp ActionExecution.h Rune.cpp Rune.h RuneStream.cpp RuneStream.h)