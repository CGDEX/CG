
#include "Escala.h"


Escala::Escala() {
    xe = 1;
    ye = 1;
    ze = 1;
};

Escala::Escala(float x, float y, float z){
    x = x;
    y = y;
    z = z;
};


void Escala::insereXE(float x) {
    xe = x;
}
void Escala::insereYE(float y) {
    ye = y;
}
void Escala::insereZE(float z) {
    ze = z;
}

float Escala::getXE() {
    return xe;
}
float Escala::getYE() {
    return ye;
}
float Escala::getZE() {
    return ze;
}
