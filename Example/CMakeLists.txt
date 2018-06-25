cmake_minimum_required(VERSION 2.6)

project(FormatExample)

set (CMAKE_CXX_STANDARD 11)

include_directories(../PublicHeaders)
include_directories(../PrivateHeaders)

add_executable(FormatExample
	main.cpp
)