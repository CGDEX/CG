//
// Created by carlos on 16-03-2019.
//

#ifndef GENERATOR_ESTRUTURA_H
#define GENERATOR_ESTRUTURA_H
#include <vector>
#include "vertice.h"

class Estrutura {
    std::vector<vertices*> coordenadas;
    public:
        Estrutura();
        std::vector<vertices*> getVertices();
        std::vector<vertices*> insertVertices(vertices* verts);
        void setCoordenadas(std::vector<vertices*> coords);
        std::vector<vertices*> getCoordenadas();
};


#endif //GENERATOR_ESTRUTURA_H
