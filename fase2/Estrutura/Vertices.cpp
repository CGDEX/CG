//
// Created by carlos on 24-03-2019.
//

#include "Vertices.h"



Vertices::Vertices() {

}
Vertices::Vertices(float xx, float yy, float zz){
    x=xx;
    x=yy;
    z=zz;
}


float Vertices::getX() {
    return x;
}
float Vertices::getY() {
    return y;
}
float Vertices::getZ() {
    return z;
}


void Vertices::insereX(float xx) {
    x=xx;
}

void Vertices::insereY(float yy) {
    y=yy;
}

void Vertices::insereZ(float zz) {
    z=zz;
}