#ifndef GENERATOR_FORMA_H
#define GENERATOR_FORMA_H


#include "Vertices.h"
#include <iostream>
#include <vector>



class Forma {

    std::vector<Vertices*> verts;
    std::vector<Vertices*> normais;
    std::vector<Vertices*> texturas;

    public:
        void insereVerts(Vertices* vv);
        void insereNorms(Vertices* nm);
        void insereTexts(Vertices* tt);
        std::vector<Vertices*> getVerts();
        std::vector<Vertices*> getNorms();
        std::vector<Vertices*> getTexts();

};


#endif //GENERATOR_FORMA_H
