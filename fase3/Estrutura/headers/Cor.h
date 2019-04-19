#ifndef GENERATOR_COR_H
#define GENERATOR_COR_H


class Cor {
    float rr;
    float gg;
    float bb;

    public:
        Cor();
        Cor(float r1, float g1, float b1);
        void insereR1(float r1);
        void insereG1(float g1);
        void insereB1(float b1);
        float getR1();
        float getG1();
        float getB1();
        bool vazioC();

};


#endif //GENERATOR_COR_H
