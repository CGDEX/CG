#ifndef GENERATOR_TRANSFORMACOES_H
#define GENERATOR_TRANSFORMACOES_H


class Transformacoes {

    float xx;
    float yy;
    float zz;

    public:
        Transformacoes();
        Transformacoes(float x, float y, float z);
        void insereTransf(float x, float y, float z);
        float getX();
        float getY();
        float getZ();
        virtual void aplicaEfeito2() { };
};



class Translacao : public Transformacoes{

    public:
        Translacao();
        Translacao(float x, float y, float z);
        void aplicaEfeito(float x, float y, float z);
        void aplicaEfeito2 ();

};


class Rotacao : public Transformacoes{
    float angle;

    public:
        Rotacao();
        Rotacao(float x, float y, float z, float angulo);
        void insereRotacao(float x, float y, float z, float angulo);
        void aplicaEfeito(float x, float y, float z, float angulo);
        void aplicaEfeito2 ();
};


class Escala : public Transformacoes {
    public:
        Escala();
        Escala(float x, float y, float z);
        void aplicaEfeito (float x, float y, float z);
        void aplicaEfeito2 ();
};

#endif //GENERATOR_TRANSFORMACOES_H
