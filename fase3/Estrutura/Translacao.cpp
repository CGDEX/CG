#include "Translacao.h"
#include <iostream>

Translacao::Translacao() {
    xx = 0.0;
    yy = 0.0;
    zz = 0.0;
};

Translacao::Translacao(float x, float y , float z){
    xx = x;
    yy = y;
    zz = z;
};


void Translacao::insereX(float x) {

    xx = x;
}
void Translacao::insereY(float y) {
    yy = y;
}
void Translacao::insereZ(float z) {
    zz = z;
}

float Translacao::getX() {
    return xx;
}
float Translacao::getY() {
    return yy;
}
float Translacao::getZ() {
    return zz;
}

