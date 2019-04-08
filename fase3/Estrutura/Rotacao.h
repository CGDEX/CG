//
// Created by carlos on 24-03-2019.
//

#ifndef GENERATOR_ROTACAO_H
#define GENERATOR_ROTACAO_H


class Rotacao {
    float timeR;
    float angleR;
    float xR;
    float yR;
    float zR;

    public:
        Rotacao();
        Rotacao(float angulo, float x, float y, float z);
        void insereAngulo(float angulo);
        void insereX(float x);
        void insereY(float y);
        void insereZ(float z);
        void insereTempo(float tempo);
        float getAngulo();
        float getXR();
        float getYR();
        float getZR();

};


#endif //GENERATOR_ROTACAO_H
