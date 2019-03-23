#include <GL/gl.h>
#include "Transformacoes.h"
#include <iostream>
Transformacoes::Transformacoes() {

}



Transformacoes::Transformacoes(float x, float y, float z) {
    xx = x;
    yy = y;
    zz = z;
}

void Transformacoes::insereTransf(float x, float y, float z) {
    x = x;
    y = y;
    z = z;
}


float Transformacoes::getX() {
    return xx;
}

float Transformacoes::getY() {
    return yy;
}

float Transformacoes::getZ() {
    return zz;
}




// TRANSLACAO

Translacao::Translacao() {

}

Translacao::Translacao(float x, float y, float z): Transformacoes(x,y,z) {

}

void Translacao::aplicaEfeito(float x, float y, float z) {
    glTranslatef(x,y,z);
}


void Translacao::aplicaEfeito2() {
    glTranslatef(getX(),getY(),getZ());
    std::cout << getX() << " " << getY() << " " << getZ() << " " << std::endl;
}

// ROTACAO

Rotacao::Rotacao() {

}
Rotacao::Rotacao(float x, float y, float z, float angulo) : Transformacoes(x,y,z) {
   angle = angulo;
}

void Rotacao::insereRotacao(float x, float y, float z, float angulo)  {
    x = x;
    y = y;
    z = z;
    angulo = angulo;
}


void Rotacao::aplicaEfeito(float x, float y, float z, float angulo) {
    glRotatef(angulo,x,y,z);
}


void Rotacao::aplicaEfeito2() {
    glRotatef(angle,getX(),getY(),getZ());


}



// ESCALA
Escala::Escala() {

}

Escala::Escala(float x, float y, float z) : Transformacoes(x,y,z) {

}

void Escala::aplicaEfeito (float x, float y, float z) {
    glScalef(x,y,z);
}

void Escala::aplicaEfeito2() {
    glScalef(getX(),getY(),getZ());
}