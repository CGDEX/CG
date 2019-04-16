#include "Vertices.h"
#include <iostream>
#include <vector>

#ifndef GENERATOR_TRANSLACAO_H
#define GENERATOR_TRANSLACAO_H


class Translacao {
    //float x;
    //float y;
    //float z;
    float tempo;
    std::vector<Vertices*> pontosT;
    std::vector<Vertices*> pontosC;




    public:
        Translacao();
        //Translacao(float x, float y, float z);
        //void insereX(float x);
        //void insereY(float y);
        //void insereZ(float z);
        void insereTempo(float t);
        void inserePonto(Vertices* ponto);
        void inserePontosT(std::vector<Vertices*> pontos);
        void inserePontosC(std::vector<Vertices*> pontos);
        std::vector<Vertices*> getPontos();
        float getTempo();
        std::vector<Vertices*> curva();
        void getGlobalCatmullRomPoint(float gt, float *resultado, std::vector<Vertices*> verts);
        void getCatmullRomPoint(float t, int* indices, float* resultado, std::vector<Vertices*> pontosT);
        bool vazioT();
        std::vector<Vertices*> getCurva();

    //float getX();
        //  float getY();
        //  float getZ();
};


#endif //GENERATOR_TRANSLACAO_H
