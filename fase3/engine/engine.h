#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>

#ifndef GENERATOR_ENGINE_H
#define GENERATOR_ENGINE_H

int centerX, centerY;
int window;

float pos_x = 30;
float pos_y = 5;
float pos_z = 10;

float dir_x = 0;
float dir_y = 0;
float dir_z = 0;

float h_angle;
float v_angle;
float speed = 0.2;

bool frente = false;
bool tras = false;
bool esquerda = false;
bool direita = false;
bool mexe_esquerda = false;
bool mexe_direita = false;

bool fps_cam = false;

int frame = 0;
int tempo2 = 0;

int modo_desenho = GL_FILL;

#endif //GENERATOR_ENGINE_H
