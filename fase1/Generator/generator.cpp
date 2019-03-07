#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdlib.h>
#include <algorithm>
#include "../Estrutura/estrutura.h"
#include "./cone.cpp"
#include "./box.cpp"
#include "./plano.cpp"
#include "./sphere.cpp"

std::vector<vertices> dados;


// FUNÇÕES
void escreverFicheiro(std::string, std::vector<vertices> dados);
void imprimeMenuHelp();

int main(int argc, char** argv) {

    // Para receber um Plane é preciso: tamanho e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Cone é preciso: radius, height, slices, stacks e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Sphere é preciso: radius, slices, stacks e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Box é preciso: X, Y, Z, nº de divisões e caminho do ficheiro para gerar o ficheiro .3d <---- é preciso ver melhor este

    if (!(strcmp(argv[1],"plane"))) {
       dados = plano(atof(argv[2]));
       escreverFicheiro("../Files3D/plano.3d",dados);
       std::cout << "Ficheiro plano.3d escrito com sucesso"<< std::endl;
    }
    else if (!(strcmp(argv[1],"cone"))) {
            dados = cone(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
            escreverFicheiro("../Files3D/cone.3d",dados);
            std::cout << "Ficheiro cone.3d escrito com sucesso"<< std::endl;
        } else if (!(strcmp(argv[1],"sphere"))) {
                   dados = esfera(atof(argv[2]),atof(argv[3]),atof(argv[4]));
                   escreverFicheiro("../Files3D/sphere.3d",dados);
                   std::cout << "Ficheiro sphere.3d escrito com sucesso"<< std::endl;
                } else if (!(strcmp(argv[1],"box"))) {
                           dados = box (atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
                           escreverFicheiro("../Files3D/box.3d",dados);
                           std::cout << "Ficheiro box.3d escrito com sucesso"<< std::endl;
                        } else if (!(strcmp(argv[1],"help"))){
                                imprimeMenuHelp();
                            }
                            else {
                                std::cout << "Bip bip! Erro 404!"<< std::endl;
                                imprimeMenuHelp();
                            }
}



void imprimeMenuHelp() {
    std::cout << "CG-BOT is here to help you!" << std::endl;
    std::cout << "Figuras possiveis: sphere, cone, box, plane." << std::endl;
    std::cout << "Como gerar box: ./generator box largura altura comprimento camadas (Atenção, se não quiser camadas utilize 0)" << std::endl;
    std::cout << "Como gerar sphere: ./generator sphere raio slices stacks" << std::endl;
    std::cout << "Como gerar cone: ./generator cone raio altura slices stacks" << std::endl;
    std::cout << "Como gerar plane: ./generator plane lado" << std::endl;

}




void escreverFicheiro(std::string path, std::vector<vertices> coordenadas) {


    std::ofstream file(path);

    std::vector<vertices>::iterator it;
    for (it=coordenadas.begin();it!=coordenadas.end();it++) {

        file << it->x << "," << it->y << "," << it->z << std::endl;
    }

    file.close();
}

// Verificar depois se funciona
vertices criaVertice(float x, float y, float z) {
    vertices coordenada;
    coordenada.x = x;
    coordenada.y = y;
    coordenada.z = z;

    return coordenada;
}





