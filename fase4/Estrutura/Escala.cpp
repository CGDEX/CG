
#include "headers/Escala.h"


Escala::Escala() {
    xe = 1;
    ye = 1;
    ze = 1;
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

bool Escala::vazioE() {
    return (xe==0 && ye==0 && ze==0);
}
