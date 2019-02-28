cmake_minimum_required(VERSION 3.13)
project(fase1)

set(CMAKE_CXX_STANDARD 14)




project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp Estrutura/estrutura.cpp Estrutura/estrutura.h)
add_executable(generator ${GENERATOR_FILES})