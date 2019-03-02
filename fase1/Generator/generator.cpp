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
std::vector<vertices> esfera (float raio, int layersX, int layersY);
std::vector<vertices> cone (float raio, float altura,  int layersX, int layersY);
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




std::vector<vertices> esfera (float raio, int layersH, int layersV) {

    // STACKS - layers HORIZONTAIS
    // SLICES - VERTICAL

    std::vector<vertices> resultado;

    float deslV = (2*M_PI)/layersH;
    float deslH = (M_PI)/layersV;

    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;

    float a,b = 0;

    for (int i=0;i<layersH;i++) {
        a=0;
        for(int j=0;j<layersV;j++) {


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

	float x, y, z, xx, yy, zz;
	float pontoX, pontoY, pontoZ, r, s;

	//definição dos espaços entre as layers
	float espC = length / layers;
	float espL = width / layers;
	float espA = height / layers;

	//fazer as faces da frente e face de trás.
	y = height / 2;
	yy = -y;
	x = length / 2;
	xx = -x;
	z = length / 2;
	zz = -z;

	//faz as layers percorrendo a linha X e quando acabar sobe uma posiçao de Y.
	for (int i = 0; i < layers; i++) {
		s = yy + (espA * i);

		for (int j = 0; j < layers; j++) {
			r = xx + (espC * j);

			pontoX = r + espC; //shift em x
			pontoY = s + espA; //shift em y

			//face da frente
			coordenadas1.x = r;
			coordenadas1.y = s;
			coordenadas1.z = z;
			resultado.push_back(coordenadas1);

			coordenadas2.x = pontoX;
			coordenadas2.y = s;
			coordenadas2.z = z;
			resultado.push_back(coordenadas2);

			coordenadas3.x = pontoX;
			coordenadas3.y = pontoY;
			coordenadas3.z = z;
			resultado.push_back(coordenadas3);
			
			coordenadas4.x = pontoX;
			coordenadas4.y = pontoY;
			coordenadas4.z = z;
			resultado.push_back(coordenadas4);
			
			coordenadas5.x = r;
			coordenadas5.y = pontoY;
			coordenadas5.z = z;
			resultado.push_back(coordenadas5);

			coordenadas6.x = pontoX;
			coordenadas6.y = s;
			coordenadas6.z = z;
			resultado.push_back(coordenadas6);
			

			//face de trás
			coordenadas1.x = r;
			coordenadas1.y = s;
			coordenadas1.z = zz;
			resultado.push_back(coordenadas1);

			coordenadas2.x = r;
			coordenadas2.y = pontoY;
			coordenadas2.z = zz;
			resultado.push_back(coordenadas2);
			
			coordenadas3.x = pontoX;
			coordenadas3.y = pontoY;
			coordenadas3.z = zz;
			resultado.push_back(coordenadas3);
			
			coordenadas4.x = pontoX;
			coordenadas4.y = pontoY;
			coordenadas4.z = zz;
			resultado.push_back(coordenadas4);
			
			coordenadas5.x = pontoX;
			coordenadas5.y = s;
			coordenadas5.z = zz;
			resultado.push_back(coordenadas5);
			
			coordenadas6.x = r;
			coordenadas6.y = s;
			coordenadas6.z = zz;
			resultado.push_back(coordenadas6);
		}
	}
	
	//face de cima e de baixo
	//começa numa posição Z e depois faz a linha toda de X e no fim sobe uma posição de Y
	y = height / 2;
	yy = -y;
	x = length / 2;
	xx = -x;
	z = width / 2;
	zz = -z;

	for (int i = 0; i < layers; i++) {
		s = zz + (espL * i);


		for (int j = 0; j < layers; j++) {

			r = xx + (espC * j);

			pontoX = r + espC;
			pontoZ = s + espL;

			//face da cima
			coordenadas1.x = r;
			coordenadas1.y = y;
			coordenadas1.z = s;
			resultado.push_back(coordenadas1);

			coordenadas2.x = r;
			coordenadas2.y = y;
			coordenadas2.z = pontoZ;
			resultado.push_back(coordenadas2);
			
			coordenadas3.x = pontoX;
			coordenadas3.y = y;
			coordenadas3.z = s;
			resultado.push_back(coordenadas3);

			coordenadas4.x = r;
			coordenadas4.y = y;
			coordenadas4.z = pontoZ;
			resultado.push_back(coordenadas4);

			coordenadas5.x = pontoX;
			coordenadas5.y = y;
			coordenadas5.z = pontoZ;
			resultado.push_back(coordenadas5);
			
			coordenadas6.x = pontoX;
			coordenadas6.y = y;
			coordenadas6.z = s;
			resultado.push_back(coordenadas6);


			//face de baixo
			coordenadas1.x = r;
			coordenadas1.y = yy;
			coordenadas1.z = s;
			resultado.push_back(coordenadas1);

			coordenadas2.x = pontoX;
			coordenadas2.y = yy;
			coordenadas2.z = s;
			resultado.push_back(coordenadas2);

			coordenadas3.x = pontoX;
			coordenadas3.y = yy;
			coordenadas3.z = pontoZ;
			resultado.push_back(coordenadas3);
			
			coordenadas4.x = pontoX;
			coordenadas4.y = yy;
			coordenadas4.z = pontoZ;
			resultado.push_back(coordenadas4);

			coordenadas5.x = r;
			coordenadas5.y = yy;
			coordenadas5.z = pontoZ;
			resultado.push_back(coordenadas5);
			
			coordenadas6.x = r;
			coordenadas6.y = yy;
			coordenadas6.z = s;
			resultado.push_back(coordenadas6);
		}
	}

	//face da esquerda e da direita
	//começa numa posição de Z faz toda a linha e depois sobe uma unidade de Y.
	y = height / 2;
	yy = -y;
	x = length / 2;
	xx = -x;
	z = width / 2;
	zz = -z;

	for (int i = 0; i < layers; i++) {
		s = yy + (espA * i);

		for (int j = 0; j < layers; j++) {
			r = zz + (espL * j);

			pontoZ = r + espL;
			pontoY = s + espA;

			//face da esquerda
			coordenadas1.x = xx;
			coordenadas1.y = s;
			coordenadas1.z = r;
			resultado.push_back(coordenadas1);

			coordenadas2.x = xx;
			coordenadas2.y = s;
			coordenadas2.z = pontoZ;
			resultado.push_back(coordenadas2);

			coordenadas3.x = xx;
			coordenadas3.y = pontoY;
			coordenadas3.z = pontoZ;
			resultado.push_back(coordenadas3);

			coordenadas4.x = xx;
			coordenadas4.y = pontoY;
			coordenadas4.z = pontoZ;
			resultado.push_back(coordenadas4);

			coordenadas5.x = xx;
			coordenadas5.y = pontoY;
			coordenadas5.z = r;
			resultado.push_back(coordenadas5);
			
			coordenadas6.x = xx;
			coordenadas6.y = s;
			coordenadas6.z = r;
			resultado.push_back(coordenadas6);


			//face da direita
			coordenadas1.x = x;
			coordenadas1.y = s;
			coordenadas1.z = r;
			resultado.push_back(coordenadas1);
			
			coordenadas2.x = x;
			coordenadas2.y = pontoY;
			coordenadas2.z = r;
			resultado.push_back(coordenadas2);

			coordenadas3.x = x;
			coordenadas3.y = s;
			coordenadas3.z = pontoZ;
			resultado.push_back(coordenadas3);

			coordenadas4.x = x;
			coordenadas4.y = pontoY;
			coordenadas4.z = r;
			resultado.push_back(coordenadas4);
			
			coordenadas5.x = x;
			coordenadas5.y = pontoY;
			coordenadas5.z = pontoZ;
			resultado.push_back(coordenadas5);

			coordenadas6.x = x;
			coordenadas6.y = s;
			coordenadas6.z = pontoZ;
			resultado.push_back(coordenadas6
);
		}
	}

	return resultado;
}