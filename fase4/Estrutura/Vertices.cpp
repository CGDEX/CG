
#include "headers/Vertices.h"



Vertices::Vertices() {

}
Vertices::Vertices(float xx, float yy, float zz){
    vertice_x=xx;
    vertice_y=yy;
    vertice_z=zz;
}


float Vertices::getX1() {
    return vertice_x;
}
float Vertices::getY1() {
    return vertice_y;
}
float Vertices::getZ1() {
    return vertice_z;
}


void Vertices::insereX1(float xx) {
    vertice_x=xx;
}

void Vertices::insereY1(float yy) {
    vertice_y=yy;
}

void Vertices::insereZ1(float zz) {
    vertice_z=zz;
}


Vertices* Vertices::normalCalc(Vertices* v) {
    float l, coordX, coordY, coordZ;

    l = sqrt(v->vertice_x * v->vertice_x + v->vertice_y * v->vertice_y + v->vertice_z * v->vertice_z);
    coordX = v->vertice_x / l;
    coordY = v->vertice_y / l;
    coordZ = v->vertice_z / l;

    return new Vertices(coordX, coordY, coordZ);
}

