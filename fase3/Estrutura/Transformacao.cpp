#include "Transformacao.h"



Transformacao::Transformacao() {
}


Transformacao::Transformacao(Translacao* t, Rotacao* r, Escala* e, Cor* c) {
    transl = t;
    rotacao = r;
    escala = e;
    cor = c;
}


void Transformacao::insereTranslacao(Translacao* t) {
    transl = t;
}
void Transformacao::insereRotacao(Rotacao* r) {
    rotacao = r;
}
void Transformacao::insereEscala (Escala* e) {
    escala = e;
}
void Transformacao::insereCor (Cor* c) {
    cor = c;
}