cmake_minimum_required(VERSION 3.10)
project(abstract-vm)

set (CMAKE_CXX_STANDARD 17)

set (CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -fsanitize=address")
include_directories(
			${CMAKE_CURRENT_SOURCE_DIR}/include
			${CMAKE_CURRENT_SOURCE_DIR}/Operand
			${CMAKE_CURRENT_SOURCE_DIR}/Vm)

add_executable(${PROJECT_NAME}
					Operand/IOperand.h
					Operand/Operand.c
					Operand/Operand.h
					src/main.cpp)

target_link_libraries(${PROJECT_NAME} -lasan)
