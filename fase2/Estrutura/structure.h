#ifndef GENERATOR_ESTRUTURA_H
#define GENERATOR_ESTRUTURA_H
#include <vector>
#include "vertice.h"
#include "rotation.h"
#include "translate.h"
#include "scale.h"

class Structure {

    std::vector<rotations*> rotacoes;
    std::vector<translations*> translacoes;
    std::vector<scales*> escalas;

    // TUDO MAL EM CIMA
    std::vector<vertices*> coordenadas;
    translations* translacao;
    scales* escala;
    rotations* rotacao;





public:
    Structure();
    void insertRotacao(rotations* coords);
    void insertCoords(std::vector<vertices*> coords);
    void insertScale(scales* escala);
    void insertTranslate(translations* coords);
    void setCoordenadas(std::vector<vertices*> coords);
    std::vector<vertices*> getCoordenadas();
    std::vector<rotations*> getRotacoes();
    std::vector<translations*> getTranslacoes();
    std::vector<scales*> getEscalas();
};


#endif //GENERATOR_ESTRUTURA_H