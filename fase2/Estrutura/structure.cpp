#include "structure.h"


Structure::Structure(){
}


void Structure::insereNext(Structure* next) {
    proximo.push_back(next);
}

void Structure::insereTranslacao(Transformacoes* transl) {
    transformacoes.push_back(transl);
}

void Structure::insereRotacao(Transformacoes* rot) {
    transformacoes.push_back(rot);
}

void Structure::insereEscala(Transformacoes* escala) {
    transformacoes.push_back(escala);
}

void Structure::insereCoords(std::vector<vertices*> coordenadas) {
    coords = coordenadas;
}

std::vector<Transformacoes*> Structure::getTransforms() {
    return transformacoes;
}


std::vector<vertices*> Structure::getCoords() {
    return coords;
}

std::vector<Structure*> Structure::getNext() {
    return proximo;
}