#include "Forma.h"



void Forma::insereNorms(Vertices *nm) {
    normais.push_back(nm);
}

void Forma::insereTexts(Vertices *tt) {
    texturas.push_back(tt);
}

void Forma::insereVerts(Vertices *vv) {
    verts.push_back(vv);
}

std::vector<Vertices*> Forma::getNorms() {
    return normais;
}

std::vector<Vertices*> Forma::getTexts() {
    return texturas;
}

std::vector<Vertices*> Forma::getVerts() {
    return verts;
}