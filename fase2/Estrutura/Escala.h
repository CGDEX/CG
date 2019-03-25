
#ifndef GENERATOR_ESCALA_H
#define GENERATOR_ESCALA_H


class Escala {
    float xe;
    float ye;
    float ze;

    public:
        Escala();
        Escala(float x, float y, float z);
        float getXE();
        float getYE();
        float getZE();
        void insereXE(float x);
        void insereYE(float y);
        void insereZE(float z);
};


#endif //GENERATOR_ESCALA_H
