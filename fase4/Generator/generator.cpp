#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdlib.h>
#include <algorithm>
#include "./cone.cpp"
#include "./box.cpp"
#include "./plano.cpp"
#include "./sphere.cpp"
#include "./cilindro.cpp"
#include "./torus.cpp"
#include "./bezier.cpp"
#include "../Estrutura/headers/Forma.h"
#include "../Estrutura/headers/Vertices.h"
std::vector<vertices> dados;
Forma* form;


// FUNÇÕES
void escreverFicheiro(std::string, std::vector<vertices> dados);
void escreverFicheiro2(std::string path, Forma* resultado);
void imprimeMenuHelp();

int main(int argc, char** argv) {

    // Para receber um Plane é preciso: tamanho e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Cone é preciso: radius, height, slices, stacks e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Sphere é preciso: radius, slices, stacks e caminho do ficheiro para gerar o ficheiro .3d
    // Para receber um Box é preciso: X, Y, Z, nº de divisões e caminho do ficheiro para gerar o ficheiro .3d <---- é preciso ver melhor este

    if (!(strcmp(argv[1],"plane"))) {
        form = plano(atof(argv[2]));
        escreverFicheiro2("../Files3D/plano.3d",form);
        std::cout << "Ficheiro plano.3d escrito com sucesso"<< std::endl;
    }
    else if (!(strcmp(argv[1],"cone"))) {
        dados = cone(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
        escreverFicheiro("../Files3D/cone.3d",dados);
        std::cout << "Ficheiro cone.3d escrito com sucesso"<< std::endl;
    }
    else if (!(strcmp(argv[1],"sphere"))) {
        form = esfera(atof(argv[2]),atoi(argv[3]),atoi(argv[4]));
        escreverFicheiro2("../Files3D/sphere.3d",form);
        std::cout << "Ficheiro sphere.3d escrito com sucesso"<< std::endl;
    }
    else if (!(strcmp(argv[1],"box"))) {
        dados = box (atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]));
        escreverFicheiro("../Files3D/box.3d",dados);
        std::cout << "Ficheiro box.3d escrito com sucesso"<< std::endl;
    }
    else if (!(strcmp(argv[1],"-help"))){
        imprimeMenuHelp();
    }
    else if (!(strcmp(argv[1],"cylinder"))){
        dados = cilindro (atof(argv[2]),atof(argv[3]),atof(argv[4]));
        escreverFicheiro("../Files3D/cilindro.3d",dados);
        std::cout << "Ficheiro cilindro.3d escrito com sucesso"<< std::endl;
    }
    else if(!(strcmp(argv[1],"torus"))) {
        dados = createTorus(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
        escreverFicheiro("../Files3D/torus.3d",dados);
        std::cout <<"Ficheiro torus.3d escrito com sucesso" << std::endl;
    }
    else if(!(strcmp(argv[1],"orbit"))) {
        std::cout << "dsadsad" << std::endl;
        dados = createTorus(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
        escreverFicheiro("../Files3D/orbita.3d",dados);
        std::cout<<"Ficheiro orbita.3d escrito com sucesso" <<std::endl;
    }
    else if(!(strcmp(argv[1],"patch"))){
        patch(argv[2],atoi(argv[3]));
    }
    else {
            std::cout << "Bip bip! Erro 404!"<< std::endl;
            imprimeMenuHelp();
        }
}



void imprimeMenuHelp() {

    std::cout << "|-----------------------------------------> FIGURA <---------------------------------------------|" << std::endl;
    std::cout << "|																  								   |" << std::endl;
    std::cout << "|						Figuras possíveis: sphere												   |" << std::endl;
    std::cout << "|								   		   cone													   |" << std::endl;
    std::cout << "|					    	               box													   |" << std::endl;
    std::cout << "|						                   plane												   |" << std::endl;
    std::cout << "|						                   cylinder												   |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                      Como gerar:                                                               |" << std::endl;
    std::cout << "|							-> box: ./generator box <largura> <altura> <comprimento> <camadas>     |" << std::endl;
    std::cout << "|								(Atenção, se não quiser camadas utilize 0)                         |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                          -> sphere: ./generator sphere <raio> <slices> <stacks>                |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                          -> cone: ./generator cone <raio> <altura> <slices> <stacks>           |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                          -> plane: ./generator plane <lado>                                    |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                          -> cylinder: ./generator cylinder <raio> <altura> <slices>            |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|----------------------------------------> Controlos 3D <----------------------------------------|" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                      * TRANSLAÇÃO: w, a, s, d  | W, A, S, D                                    |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                      * ROTAÇÃO: Seta cima, baixo, esquerda, direita                            |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                      * ZOOM: + | -                                                             |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|                      * REPRESENTAÇÃO DO SÓLIDO:                                                |" << std::endl;
    std::cout << "|                          -> por linhas: l | L                                                  |" << std::endl;
    std::cout << "|                          -> por pontos: p | P                                                  |" << std::endl;
    std::cout << "|                          -> preenchido: o | O                                                  |" << std::endl;
    std::cout << "|                                                                                                |" << std::endl;
    std::cout << "|---------------------------------------------><-------------------------------------------------|" << std::endl;

}



void escreverFicheiro(std::string path, std::vector<vertices> coordenadas) {


    std::ofstream file(path);

    std::vector<vertices>::iterator it;
    for (it=coordenadas.begin();it!=coordenadas.end();it++) {

        file << it->x << "," << it->y << "," << it->z << std::endl;
    }

    file.close();
}

void escreverFicheiro2(std::string path, Forma* resultado) {


    std::ofstream file(path);

    std::vector<Vertices*> coords = resultado->getVerts();
    for (int i=0; i < coords.size();i++) {
        file << coords[i]->getX1() << "," << coords[i]->getY1() << "," << coords[i]->getZ1() << std::endl;
    //std::cout << "X: " << resultado->getVerts()[i]->getX1() << " Y: " << coords[i]->getY1() << std::endl;
    }

    file <<">>normais<<"<< std::endl;
    std::vector<Vertices*> norms = resultado->getNorms();
    for (int i=0; i < norms.size();i++) {
        file << norms[i]->getX1() << "," << norms[i]->getY1() << "," << norms[i]->getZ1() << std::endl;
        //std::cout << "X: " << resultado->getVerts()[i]->getX1() << " Y: " << coords[i]->getY1() << std::endl;
    }

    file <<">>texturas<<"<< std::endl;
    std::vector<Vertices*> texts= resultado->getTexts();
    for (int i=0; i < texts.size();i++) {
        file << texts[i]->getX1() << "," << texts[i]->getY1() << "," << texts[i]->getZ1() << std::endl;
        //std::cout << "X: " << resultado->getVerts()[i]->getX1() << " Y: " << coords[i]->getY1() << std::endl;
    }




    file.close();
}


