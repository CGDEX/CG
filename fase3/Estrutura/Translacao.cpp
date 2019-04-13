#include "Translacao.h"
#include <iostream>
#include <math.h>
Translacao::Translacao() {
    //xT = 0.0;
    //yT = 0.0;
    //zT = 0.0;
};

/*
Translacao::Translacao(float x, float y , float z){
    xT = x;
    yT = y;
    zT = z;
};


void Translacao::insereX(float x) {

    xT = x;
}
void Translacao::insereY(float y) {
    yT = y;
}
void Translacao::insereZ(float z) {
    zT = z;
}


float Translacao::getX() {
    return xT;
}
float Translacao::getY() {
    return yT;
}
float Translacao::getZ() {
    return zT;
}

*/
void Translacao::inserePonto(Vertices* ponto) {
    pontosT.push_back(ponto);
}

void Translacao::insereTempo(float t) {
    tempo = t;
}

std::vector<Vertices*> Translacao::getPontos() {
    return pontosT;
}

std::vector<Vertices*> Translacao::getCurva() {
    return pontosC;
}

float Translacao::getTempo() {
    return tempo;
}

void Translacao::inserePontosT(std::vector<Vertices*> pontos) {
    pontosT = pontos;
}

void Translacao::inserePontosC(std::vector<Vertices*> pontos) {
    pontosC = pontos;
}

void Translacao::getCatmullRomPoint(float t, int* indices, float* resultado, std::vector<Vertices*> pontosT) {

    float m[4][4] = {{-0.5f, 1.5f,  -1.5f, 0.5f},
                     {1.0f,  -2.5f, 2.0f,    -0.5f},
                     {-0.5f, 0.0f,    0.5f,  0.0f},
                     {0.0f,    1.0f,    0.0f,    0.0f}};

    float quad = t*t;
    float cubo = t*t*t;
    float aux[4];

    resultado[0] = 0;
    resultado[1] = 0;
    resultado[2] = 0;

    aux[0] = (cubo * m[0][0]) + (quad * m[1][0]) + (t * m[2][0]) + (m[3][0]);
    aux[1] = (cubo * m[0][1]) + (quad * m[1][1]) + (t * m[2][1]) + (m[3][1]);
    aux[2] = (cubo * m[0][2]) + (quad * m[1][2]) + (t * m[2][2]) + (m[3][2]);
    aux[3] = (cubo * m[0][3]) + (quad * m[1][3]) + (t * m[2][3]) + (m[3][3]);

    int i1 = indices[0];
    int i2 = indices[1];
    int i3 = indices[2];
    int i4 = indices[3];


    Vertices* p1 = pontosT[i1];
    Vertices* p2 = pontosT[i2];
    Vertices* p3 = pontosT[i3];
    Vertices* p4 = pontosT[i4];

    resultado[0] = (aux[0]* p1->getX1()) + (aux[1]*p2->getX1()) + (aux[2]*p3->getX1()) + (aux[3]*p4->getX1());
    resultado[1] = (aux[0]* p1->getY1()) + (aux[1]*p2->getY1()) + (aux[2]*p3->getY1()) + (aux[3]*p4->getY1());
    resultado[2] = (aux[0]* p1->getZ1()) + (aux[1]*p2->getZ1()) + (aux[2]*p3->getZ1()) + (aux[3]*p4->getZ1());


}


void Translacao::getGlobalCatmullRomPoint(float gt, float *resultado, std::vector<Vertices *> verts) {
    int tamanho = pontosT.size();
    int* ind = new int[4];
    int i = 0;
    float t;

    t = tamanho * gt;
    i = floor(t); // Serve para truncar
    t = t-i;

    ind[0] = (i+tamanho-1)%tamanho;
    ind[1] = (ind[0]+1)%tamanho;
    ind[2] = (ind[1]+1)%tamanho;
    ind[3] = (ind[2]+1)%tamanho;

    getCatmullRomPoint(t, ind, resultado, verts);

}

std::vector<Vertices*> Translacao::curva() {
    float res[3];
    float t;
    for (t = 0; t < 1; t += 0.01) {
        getGlobalCatmullRomPoint(t, res, pontosT);
        //    std::cout << res[0] << " " << res[1] << " " << res[2] << std::endl;
        Vertices* v = new Vertices(res[0], res[1], res[2]);
        pontosC.push_back(v);
    }
    return pontosC;
}