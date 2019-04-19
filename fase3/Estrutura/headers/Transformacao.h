#include "Translacao.h"
#include "Rotacao.h"
#include "Escala.h"
#include "Cor.h"


#ifndef GENERATOR_TRANSFORMACAO_H
#define GENERATOR_TRANSFORMACAO_H


class Transformacao {

    Translacao* transl;
    Rotacao* rotacao;
    Escala* escala;
    Cor* cor;

    public:
        Transformacao();
        Transformacao(Translacao* t, Rotacao* r, Escala* e, Cor* c);
        Translacao* getTranslacao() {
            return transl;
        };
        Rotacao* getRotacao(){
            return rotacao;
        };
        Escala* getEscala() {
            return escala;
        };
        Cor* getCor() {
            return cor;
        };
        bool verificaVazio();
        void insereTranslacao(Translacao* t);
        void insereRotacao(Rotacao* r);
        void insereEscala (Escala* e);
        void insereCor (Cor* c);
};


#endif //GENERATOR_TRANSFORMACAO_H
