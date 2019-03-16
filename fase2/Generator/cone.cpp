#include "../Estrutura/vertice.h"
#include <algorithm>
#include <vector>
#include <math.h>
// Função que cria um vector com as coordenadas de vários pontos para criar um cone
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


    for (int i=0;i<slices;i++) {

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
        a+=desl1;
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

            coordenadas4 = coordenadas2;
            resultado.push_back(coordenadas4);

            coordenadas5.x = novo_raio*sin(a+desl1);
            coordenadas5.y = alt+desl2;
            coordenadas5.z = novo_raio*cos(a+desl1);
            resultado.push_back(coordenadas5);

            coordenadas6 = coordenadas3;
            resultado.push_back(coordenadas6);
        }
        raio -= desl_r;
        alt +=  desl2;
    }

    return resultado;
}


