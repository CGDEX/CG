//
// Created by carlos on 24-03-2019.
//

#ifndef GENERATOR_ROTACAO_H
#define GENERATOR_ROTACAO_H


class Rotacao {
    float angle;
    float xr;
    float yr;
    float zr;

    public:
        Rotacao();
        Rotacao(float angulo, float x, float y, float z);
        void insereAngulo(float angulo);
        void insereX(float x);
        void insereY(float y);
        void insereZ(float z);
        float getAngulo();
        float getXR();
        float getYR();
        float getZR();

};


#endif //GENERATOR_ROTACAO_H
