#include "../Estrutura/Vertices.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>



std::vector<Vertices*> plano (float lado) {

    std::vector<Vertices*> resultado;

    float tamanho = lado/2;
    Vertices* coordenadas = new Vertices();


    // TRIANGULO 1
    coordenadas->insereX(-tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(-tamanho);
    resultado.push_back(coordenadas);

    coordenadas->insereX(-tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(tamanho);
    resultado.push_back(coordenadas);

    coordenadas->insereX(tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(tamanho);
    resultado.push_back(coordenadas);



    //TRIANGULO 2
    coordenadas->insereX(-tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(-tamanho);
    resultado.push_back(coordenadas);

    coordenadas->insereX(tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(tamanho);
    resultado.push_back(coordenadas);

    coordenadas->insereX(tamanho);
    coordenadas->insereY(0);
    coordenadas->insereZ(-tamanho);
    resultado.push_back(coordenadas);


    return resultado;
}

