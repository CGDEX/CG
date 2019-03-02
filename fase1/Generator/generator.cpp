
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdlib.h>
#include "../Estrutura/estrutura.h"
#include "./sphere.cpp"
#include <algorithm>

std::vector<vertices> dados;


// FUNÇÕES
void escreverFicheiro(std::string, std::vector<vertices> dados);
std::vector<vertices> cone (float raio, float altura,  int camadasX, int camadasY);
std::vector<vertices> box(float largura, float altura, float profundidade, int camadas);
std::vector<vertices> cria_plano_frente_tras(float largura, float altura, float z, int camadas);

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
                           dados = box(10,15,15,10);
                           escreverFicheiro("../Files3D/box.3d",dados);
                           std::cout << "Ficheiro box.3d escrito com sucesso"<< std::endl;
                        } else {
                           std::cout << "Doh! Erro 404!"<< std::endl;
                          }
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



std::vector<vertices> cone (float raio, float altura,  int slices, int stacks) {

    std::vector<vertices> resultado;

    float desl1 = (2*M_PI)/slices; // Horizontal
    float desl2 = altura/stacks; // Vertical
    float alt = -(altura/2);
    float desl_r = raio/stacks;


    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float a,novo_raio= 0;

    std::cout << (raio*sin(0)) << std::endl;
    for (a=0;a<2*M_PI;a+=desl1) {

        coordenadas1.x = raio*sin(a);
        coordenadas1.y = (-altura)/2;
        coordenadas1.z = raio*cos(a);
        resultado.push_back(coordenadas1);


        coordenadas2.x = 0;
        coordenadas2.y = (-altura)/2;
        coordenadas2.z = 0;
        resultado.push_back(coordenadas2);

        coordenadas3.x = raio*sin(a+desl1);
        coordenadas3.y = (-altura)/2;
        coordenadas3.z = raio*cos(a+desl1);
        resultado.push_back(coordenadas3);
    }

    for (int i=0;i<stacks;i++) {
        for (int j=0;j<slices;j++) {
            a += desl1;
            novo_raio = raio-desl_r;

            coordenadas1.x = raio*sin(a);
            coordenadas1.y = alt;
            coordenadas1.z = raio*cos(a);
            resultado.push_back(coordenadas1);

            coordenadas2.x = raio*sin(a+desl1);
            coordenadas2.y = alt;
            coordenadas2.z = raio*cos(a+desl1);
            resultado.push_back(coordenadas2);

            coordenadas3.x = novo_raio*sin(a);
            coordenadas3.y = alt+desl2;
            coordenadas3.z = novo_raio*cos(a);
            resultado.push_back(coordenadas3);

            coordenadas4.x = raio*sin(a+desl1);
            coordenadas4.y = alt;
            coordenadas4.z = raio*cos(a+desl1);
            resultado.push_back(coordenadas4);

            coordenadas5.x = novo_raio*sin(a+desl1);
            coordenadas5.y = alt+desl2;
            coordenadas5.z = novo_raio*cos(a+desl1);
            resultado.push_back(coordenadas5);

            coordenadas6.x = novo_raio*sin(a);
            coordenadas6.y = alt+desl2;
            coordenadas6.z = novo_raio*cos(a);
            resultado.push_back(coordenadas6);
        }
        raio -= desl_r;
        alt +=  desl2;
    }

    return resultado;
}


std::vector<vertices> cria_plano_frente_tras(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float desl_y, desl_x;
    float x,y;

    x = largura/2;
    y = altura/2;


    if (camadas==0) {
        desl_x = largura;
        desl_y = altura;
        camadas = 1;
    }
    else {
        desl_y = altura/camadas;
        desl_x = largura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {

        for(j=0;j<camadas;j++) {
            coordenadas1.x = -x+(j*desl_x);
            coordenadas1.y = -y+(i*desl_y);
            coordenadas1.z = comprimento;
            resultado.push_back(coordenadas1);

            coordenadas2.x = (-x+desl_x)+(j*desl_x);
            coordenadas2.y = -y+(i*desl_y);
            coordenadas2.z = comprimento;
            resultado.push_back(coordenadas2);

            coordenadas3.x = (-x+desl_x)+(j*desl_x);
            coordenadas3.y = (-y+desl_y)+(i*desl_y);
            coordenadas3.z = comprimento;
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = -x+(j*desl_x);
            coordenadas6.y = (-y+desl_y)+(i*desl_y);
            coordenadas6.z = comprimento;
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}

std::vector<vertices> cria_plano_cima_baixo(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float desl_z, desl_x;
    float x,z;

    x = largura/2;
    z = comprimento/2;


    if (camadas==0) {
        desl_x = largura;
        desl_z = comprimento;
        camadas = 1;
    }
    else {
        desl_z = comprimento/camadas;
        desl_x = largura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {
        for(j=0;j<camadas;j++) {

            coordenadas1.x = -x+(i*desl_x);
            coordenadas1.y = altura;
            coordenadas1.z = -z+(j*desl_z);
            resultado.push_back(coordenadas1);

            coordenadas2.x = -x+(i*desl_x);
            coordenadas2.y = altura;
            coordenadas2.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas2);

            coordenadas3.x = (-x+desl_x)+(i*desl_x);
            coordenadas3.y = altura;
            coordenadas3.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = (-x+desl_x)+(i*desl_x);
            coordenadas6.y = altura;
            coordenadas6.z = -z+(j*desl_z);
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}



std::vector<vertices> cria_plano_esquerda_direita(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float desl_z, desl_y;
    float y,z;

    y = altura/2;
    z = comprimento/2;


    if (camadas==0) {
        desl_y = largura;
        desl_z = comprimento;
        camadas = 1;
    }
    else {
        desl_z = comprimento/camadas;
        desl_y = altura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {
        for(j=0;j<camadas;j++) {

            coordenadas1.x = largura;
            coordenadas1.y = -y+(i*desl_y);
            coordenadas1.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas1);

            coordenadas2.x = largura;
            coordenadas2.y = -y+(i*desl_y);
            coordenadas2.z = -z+(j*desl_z);
            resultado.push_back(coordenadas2);

            coordenadas3.x = largura;
            coordenadas3.y = (-y+desl_y)+(i*desl_y);
            coordenadas3.z = -z+(j*desl_z);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = largura;
            coordenadas6.y = (-y+desl_y)+(i*desl_y);
            coordenadas6.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas6);

        }
    }

    return resultado;

}



std::vector<vertices> box(float largura, float altura, float comprimento, int camadas) {
    // Face da frente
    std::vector<vertices> resultado = cria_plano_frente_tras(largura,altura,(comprimento/2),camadas);

    //face de trás
    std::vector<vertices> resultado2 = cria_plano_frente_tras(largura,altura,(-comprimento/2),camadas);
    std::reverse(resultado2.begin(),resultado2.end());

    // Face de cima
    std::vector<vertices> resultado3 = cria_plano_cima_baixo(largura,(altura/2),comprimento,camadas);

    // Face de baixo
    std::vector<vertices> resultado4 = cria_plano_cima_baixo(largura,(-altura/2),comprimento,camadas);
    std::reverse(resultado4.begin(),resultado4.end());

    //Face de direita
    std::vector<vertices> resultado5 = cria_plano_esquerda_direita((largura/2),altura,comprimento,camadas);

    return resultado5;
}