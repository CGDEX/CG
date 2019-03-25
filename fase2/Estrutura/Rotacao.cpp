#include "Rotacao.h"



Rotacao::Rotacao() {

}

Rotacao::Rotacao(float angulo, float x, float y, float z) {
    angle = angulo;
    xr = x;
    yr = y;
    zr = z;
}

void Rotacao::insereAngulo(float angulo) {
    angle = angulo;
}
void Rotacao::insereX(float x) {
    xr = x;
}
void Rotacao::insereY(float y) {
    yr = y;
}
void Rotacao::insereZ(float z) {
    zr = z;
}

float Rotacao::getAngulo() {
    return angle;
}
float Rotacao::getXR() {
    return xr;
}
float Rotacao::getYR() {
    return yr;
}
float Rotacao::getZR() {
    return zr;
}
