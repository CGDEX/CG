#include "../Estrutura/headers/estrutura.h"

#include <stdio.h>
#include <stdlib.h>
#include <vector>


// Função que cria um vector com as coordenadas de vários pontos para criar um plano
void plano(int lado) {

    std::ofstream file("../Files3D/plano.3d");
    float tamanho = lado/2;


    // TRIANGULO 2
    file << -tamanho << "," << 0 << "," << -tamanho << std::endl;
    file << -tamanho << "," << 0 << "," << tamanho << std::endl;
    file << tamanho << "," << 0 << "," << tamanho << std::endl;

    // TRIANGULO 2
    file << -tamanho << "," << 0 << "," << -tamanho << std::endl;
    file << tamanho << "," << 0 << "," << tamanho << std::endl;
    file << tamanho << "," << 0 << "," << -tamanho << std::endl;


    // NORMAIS
    file << ">>normais<<" << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;
    file << 0 << "," << 1 << "," << 0 << std::endl;

    // TEXTURAS
    file << ">>texturas<<" << std::endl;
    file << 1 << "," << 1 << ","<< 0 << std::endl;
    file << 1 << "," << 0<< ","<< 0 << std::endl;
    file << 0 << "," << 1 << ","<< 0 << std::endl;
    file << 0 << "," << 1 << ","<< 0 << std::endl;
    file << 1 << "," << 0 << ","<< 0 << std::endl;
    file << 0 << "," << 0 << ","<< 0 << std::endl;
}