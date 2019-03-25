#ifndef GENERATOR_TRANSLACAO_H
#define GENERATOR_TRANSLACAO_H


class Translacao {
    float xx;
    float yy;
    float zz;


    public:
        Translacao();
        Translacao(float x, float y, float z);
        void insereX(float x);
        void insereY(float y);
        void insereZ(float z);
        float getX();
        float getY();
        float getZ();
};


#endif //GENERATOR_TRANSLACAO_H
