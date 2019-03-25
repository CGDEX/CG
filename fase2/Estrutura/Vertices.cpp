//
// Created by carlos on 24-03-2019.
//

#include "Vertices.h"



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