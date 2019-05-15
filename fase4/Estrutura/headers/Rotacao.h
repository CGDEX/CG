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
        void insereTempo(float t);
        void insereAngulo(float angulo);
        void insereX(float x);
        void insereY(float y);
        void insereZ(float z);

        float getTempo();
        float getXR();
        float getYR();
        float getZR();
        bool vazioR();

};


#endif //GENERATOR_ROTACAO_H
