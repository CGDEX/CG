cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "-Wall -O3  -Iinclude -DGLEW_BUILD -g -lGLEW " )
include_directories(${GLUT_INCLUDE_DIR})


project(engine)
set(ENGINE_FILES ./engine/engine.cpp ./engine/tinyxml2.cpp Estrutura/Rotacao.cpp Estrutura/Rotacao.h Estrutura/Cor.cpp Estrutura/Cor.h Estrutura/Escala.cpp Estrutura/Escala.h Estrutura/Translacao.cpp Estrutura/Translacao.h Estrutura/Transformacao.cpp Estrutura/Transformacao.h Estrutura/Group.cpp Estrutura/Group.h Estrutura/Vertices.cpp Estrutura/Vertices.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_executable(engine ${ENGINE_FILES})
target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp Estrutura/Vertices.h Estrutura/Vertices.cpp)

add_executable(generator ${GENERATOR_FILES})