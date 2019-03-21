#include "structure.h"


Structure::Structure(){
}


void Structure::insertRotacao(rotations* coords) {
    rotacao=coords;
}

void Structure::insertTranslate(translations *coords){
    translacao=coords;
}

void Structure::insertScale(scales* coords){
    escala=coords;
}

void Structure::insertCoords(std::vector<vertices*> coords){
    coordenadas=coords;
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