#include "../Estrutura/estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>


// Função que cria um vector com as coordenadas de vários pontos para criar um plano
std::vector<vertices> plano (float lado) {

    std::vector<vertices> resultado;

    float tamanho = lado/2;
    vertices coordenadas;


    // TRIANGULO 1
    coordenadas.x = -tamanho;
    coordenadas.y = 0;
    coordenadas.z = -tamanho;
    resultado.push_back(coordenadas);

    coordenadas.x = -tamanho;
    coordenadas.y = 0;
    coordenadas.z = tamanho;
    resultado.push_back(coordenadas);

    coordenadas.x = tamanho;
    coordenadas.y = 0;
    coordenadas.z = tamanho;
    resultado.push_back(coordenadas);


    // TRIANGULO 2
    coordenadas.x = -tamanho;
    coordenadas.y = 0;
    coordenadas.z = -tamanho;
    resultado.push_back(coordenadas);

    coordenadas.x = tamanho;
    coordenadas.y = 0;
    coordenadas.z = tamanho;
    resultado.push_back(coordenadas);

    coordenadas.x = tamanho;
    coordenadas.y = 0;
    coordenadas.z = -tamanho;
    resultado.push_back(coordenadas);


    return resultado;
}

