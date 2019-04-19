#include "headers/Rotacao.h"



Rotacao::Rotacao() {

}


void Rotacao::insereAngulo(float angulo) {
    angleR = angulo;
}
void Rotacao::insereX(float x) {
    xR = x;
}
void Rotacao::insereY(float y) {
    yR = y;
}
void Rotacao::insereZ(float z) {
    zR = z;
}
void Rotacao::insereTempo(float t) {
    timeR = t;
}


float Rotacao::getAngulo() {
    return angleR;
}

float Rotacao::getTempo(){
    return timeR;
}
float Rotacao::getXR() {
    return xR;
}
float Rotacao::getYR() {
    return yR;
}
float Rotacao::getZR() {
    return zR;
}

bool Rotacao::vazioR() {
    return (timeR==0 && angleR==0 && xR==0 && yR==0 && zR==0);
}