cmake_minimum_required(VERSION 3.13)
project(fase1)

project(engine)
set(ENGINE_FILES ./engine/engine.cpp ./engine/tinyxml2.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(engine ${ENGINE_FILES})
target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp)
add_executable(generator ${GENERATOR_FILES})
