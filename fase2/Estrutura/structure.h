#ifndef GENERATOR_ESTRUTURA_H
#define GENERATOR_ESTRUTURA_H
#include <vector>
#include "vertice.h"
#include "rotation.h"
#include "translate.h"
#include "Transformacoes.h"
#include "scale.h"

class Structure {

    std::vector<Transformacoes*> transformacoes;
    std::vector<Structure*> proximo;
    std::vector<vertices*> coords;


public:
    Structure();
    void insereNext(Structure* next);
    void insereTranslacao(Transformacoes* transl);
    void insereRotacao(Transformacoes* rot);
    void insereEscala(Transformacoes* escala);
    void insereCoords(std::vector<vertices*> coordenadas);
    std::vector<Transformacoes*> getTransforms() ;
    std::vector<Structure*> getNext();
    std::vector<vertices*> getCoords();

};


#endif //GENERATOR_ESTRUTURA_H