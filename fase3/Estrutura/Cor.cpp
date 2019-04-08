#include "Cor.h"

Cor::Cor() {

}

Cor::Cor(float r1, float g1, float b1) {
    rr = r1;
    gg = g1;
    bb = b1;
}


void Cor::insereR1(float r1) {
    rr = r1;
}
void Cor::insereG1(float g1) {
    gg = g1 ;
}
void Cor::insereB1(float b1) {
    bb = b1;
}



float Cor::getR1() {
    return rr;
}
float Cor::getG1() {
    return gg;
}
float Cor::getB1() {
    return bb;
}
