#include "structure.h"


Structure::Structure(){
}


void Structure::insertRotacao(rotations* coords) {
    rotacoes.push_back(coords);
}

void Structure::insertTranslate(translations *coords){
    translacoes.push_back(coords);
}

void Structure::insertScale(scales* coords){
    escalas.push_back(coords);
}


void Structure::setCoordenadas(std::vector<vertices*> coords) {
    coordenadas.insert(coordenadas.end(),coords.begin(),coords.end());
}


std::vector<vertices*> Structure::getCoordenadas() {
    return coordenadas;
}

std::vector<rotations*> Structure::getRotacoes() {
    return rotacoes;
}

std::vector<scales*> Structure::getEscalas() {
    return escalas;
}

std::vector<translations*> Structure::getTranslacoes(){
    return translacoes;
}