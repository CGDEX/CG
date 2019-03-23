cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "-Wall -O3 -g" )

project(engine)
set(ENGINE_FILES ./engine/engine.cpp ./engine/tinyxml2.cpp Estrutura/structure.cpp Estrutura/structure.h Estrutura/rotation.h Estrutura/translate.h Estrutura/scale.h Estrutura/Transformacoes.cpp Estrutura/Transformacoes.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(engine ${ENGINE_FILES})
target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp)

add_executable(generator ${GENERATOR_FILES})