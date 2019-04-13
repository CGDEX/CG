#include "Rotacao.h"



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
