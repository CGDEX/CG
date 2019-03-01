#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdlib.h>
#include "../Estrutura/estrutura.h"
#include "./plano.cpp"

std::vector<vertices> dados;


// FUNÇÕES
std::vector<vertices> esfera (float raio, int camadasX, int camadasY);
std::vector<vertices> cone (float raio, float altura,  int camadasX, int camadasY);
void escreverFicheiro(std::string, std::vector<vertices> dados);


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
                           dados = plano(atof(argv[2]));
                           escreverFicheiro("../Files3D/box.3d",dados);
                           std::cout << "Ficheiro plano.3d escrito com sucesso"<< std::endl;
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




std::vector<vertices> esfera (float raio, int camadasH, int camadasV) {

    // STACKS - CAMADAS HORIZONTAIS
    // SLICES - VERTICAL

    std::vector<vertices> resultado;

    float deslV = (2*M_PI)/camadasH;
    float deslH = (M_PI)/camadasV;

    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;

    float a,b = 0;

    for (int i=0;i<camadasH;i++) {
        a=0;
        for(int j=0;j<camadasV;j++) {


            coordenadas1.x = raio*sin(b)*sin(a);
            coordenadas1.y = raio*cos(b);
            coordenadas1.z = raio*sin(b)*cos(a);
            resultado.push_back(coordenadas1);

            coordenadas2.x = raio*sin(b+deslH)*sin(a+deslV);
            coordenadas2.y = raio*cos(b+deslH);
            coordenadas2.z = raio*sin(b+deslH)*cos(a+deslV);
            resultado.push_back(coordenadas2);

            coordenadas3.x = raio*sin(b+deslH)*sin(a);
            coordenadas3.y = raio*cos(b+deslH);
            coordenadas3.z = raio*sin(b+deslH)*cos(a);
            resultado.push_back(coordenadas3);

            coordenadas4.x = raio*sin(b)*sin(a+deslV);
            coordenadas4.y = raio*cos(b);
            coordenadas4.z = raio*sin(b)*cos(a+deslV);
            resultado.push_back(coordenadas4);

            a+=deslV;
        }
        b+=deslH;
    }

    return resultado;
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

    float desl1 = (2*M_PI)/slices;
    float desl2 = altura/stacks;
    float alt = -(altura/2);

    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float a,aux = 0;
    for (a=0;a<2*M_PI;a+=desl1) {
        coordenadas1.x = raio*sin(a);
        coordenadas1.y = (-altura)/2;
        coordenadas1.z = raio*cos(a);
        resultado.push_back(coordenadas3);


        coordenadas2.x = 0;
        coordenadas2.y = (-altura)/2;
        coordenadas2.z = 0;
        resultado.push_back(coordenadas1);

        coordenadas3.x = raio*sin(a+desl1);
        coordenadas3.y = (-altura)/2;
        coordenadas3.z = raio*cos(a+desl1);
        resultado.push_back(coordenadas2);
    }

    for (int i=0;i<stacks;i++) {
        for (int j=0;j<slices;j++) {
            a += desl1;
            aux = raio- (raio/stacks);

            coordenadas1.x = raio*sin(a);
            coordenadas1.y = alt;
            coordenadas1.z = raio*cos(a);
            resultado.push_back(coordenadas1);

            coordenadas2.x = raio*sin(a+desl1);
            coordenadas2.y = alt;
            coordenadas2.z = raio*cos(a+desl1);
            resultado.push_back(coordenadas2);

            coordenadas3.x = aux*sin(a);
            coordenadas3.y = alt+desl2;
            coordenadas3.z = aux*cos(a);
            resultado.push_back(coordenadas3);

            coordenadas4.x = raio*sin(a+desl1);
            coordenadas4.y = alt;
            coordenadas4.z = raio*cos(a+desl1);
            resultado.push_back(coordenadas4);

            coordenadas5.x = aux*sin(a+desl1);
            coordenadas5.y = alt+desl2;
            coordenadas5.z = aux*cos(a+desl1);
            resultado.push_back(coordenadas5);

            coordenadas6.x = aux*sin(a);
            coordenadas6.y = alt+desl2;
            coordenadas6.z = aux*cos(a+desl1);
            resultado.push_back(coordenadas6);
        }
        raio -= (raio/stacks);
        alt +=  desl2;
    }

    return resultado;
}

std::vector<vertices> box(float width, float height, float length, float layers) {

    std::vector<vertices> resultado;

    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float x_pos, x_shift, y_pos, y_shift, z_pos, z_shift;

    y_pos = height / 2;
    if (layers == 0) {
        y_shift = height;
    }
    else {
        y_shift = height / layers;
    }

    x_pos = width / 2;
    if (layers == 0) {
        x_shift = width;
        layers = 1;
    }
    else {
        x_shift = width / layers;
    }

    z_pos = length / 4;
    if (layers == 0) {
        z_shift = length;
        layers = 1;
    }
    else {
        z_shift = length / layers;
    }


    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < layers; j++) {

            //cria a face da frente de XY
            coordenadas1.x = -x_pos + (j*x_shift);
            coordenadas1.y = -y_pos + (i*y_shift);
            coordenadas1.z = length;
            resultado.push_back(coordenadas1);

            coordenadas2.x = (-x_pos + x_shift) + (j*x_shift);
            coordenadas2.y = -y_pos + (i*y_shift);
            coordenadas2.z = length;
            resultado.push_back(coordenadas2);

            coordenadas3.x = (-x_pos + x_shift) + (j*x_shift);
            coordenadas3.y = (-y_pos + y_shift) + (i*y_shift);
            coordenadas3.z = length;
            resultado.push_back(coordenadas3);

            coordenadas4.x = -x_pos + (j*x_shift);
            coordenadas4.y = -y_pos + (i*y_shift);
            coordenadas4.z = length;
            resultado.push_back(coordenadas4);

            coordenadas5.x = (-x_pos + x_shift) + (j*x_shift);
            coordenadas5.y = (-y_pos + y_shift) + (i*y_shift);
            coordenadas5.z = length;
            resultado.push_back(coordenadas5);

            coordenadas6.x = -x_pos + (j*x_shift);
            coordenadas6.y = (-y_pos + y_shift) + (i*y_shift);
            coordenadas6.z = length;
            resultado.push_back(coordenadas6);
        }
    }


    return resultado;
}