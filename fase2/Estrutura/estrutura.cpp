#include "estrutura.h"


Estrutura::Estrutura(){
}

std::vector<vertices*> Estrutura::getVertices(){
    return coordenadas;
}

std::vector<vertices*> Estrutura::insertVertices(vertices* verts){
    coordenadas.push_back(verts);
}

void Estrutura::setCoordenadas(std::vector<vertices*> coords) {
    coordenadas.insert(coordenadas.end(),coords.begin(),coords.end());
}


std::vector<vertices*> Estrutura::getCoordenadas() {
    return coordenadas;
}