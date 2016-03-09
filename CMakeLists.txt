cmake_minimum_required(VERSION 3.3)
project(getMP3)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcurl -lpthread")

set(SOURCE_FILES main.c)
add_executable(getMP3 ${SOURCE_FILES} main.c)