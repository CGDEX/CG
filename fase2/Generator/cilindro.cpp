#include "../Estrutura/estrutura.h"
#include <algorithm>
#include <vector>
#include <math.h>


// Função que cria um vector com as coordenadas de vários pontos para criar um cilindro
std::vector<vertices> cilindro (float raio, float altura,  int slices) {

    std::vector<vertices> resultado;
    int i;
    float desl1 = 360.0/slices;



    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;



    // Parte de cima
    for (i=0;i<slices;i++) {
        coordenadas1.x = 0;
        coordenadas1.y = altura*0.5;
        coordenadas1.z = 0;
        resultado.push_back(coordenadas1);

        coordenadas2.x = cos(i*desl1*M_PI/180.0)*raio;
        coordenadas2.y = altura*0.5;
        coordenadas2.z = -sin(i*desl1*M_PI/180)*raio;
        resultado.push_back(coordenadas2);

        coordenadas3.x = cos((i+1)*desl1*M_PI/180.0)*raio;
        coordenadas3.y = altura*0.5;
        coordenadas3.z = -sin((i+1)*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas3);

    }

    // Parte de baixo
    for (i=0;i<slices;i++) {
        coordenadas1.x = 0;
        coordenadas1.y = -(altura*0.5);
        coordenadas1.z = 0;
        resultado.push_back(coordenadas1);

        coordenadas2.x = cos((i+1)*desl1*M_PI/180.0)*raio;
        coordenadas2.y = -(altura*0.5);
        coordenadas2.z = -sin((i+1)*desl1*M_PI/180)*raio;
        resultado.push_back(coordenadas2);

        coordenadas3.x = cos(i*desl1*M_PI/180.0)*raio;
        coordenadas3.y = -(altura*0.5);
        coordenadas3.z = -sin(i*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas3);
    }

    // Corpo
    for (i=0;i<slices;i++) {
        coordenadas1.x = cos((i*desl1*M_PI)/180.0)*raio;
        coordenadas1.y = altura*0.5;
        coordenadas1.z = -sin(i*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas1);

        coordenadas2.x = cos(i*desl1*M_PI/180.0)*raio;
        coordenadas2.y = -(altura*0.5);
        coordenadas2.z = -sin(i*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas2);

        coordenadas3.x = cos((i+1)*desl1*M_PI/180.0)*raio;
        coordenadas3.y = altura*0.5;
        coordenadas3.z = -sin((i+1)*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas3);

        coordenadas4 = coordenadas2;
        resultado.push_back(coordenadas4);

        coordenadas5.x = cos((i+1)*desl1*M_PI/180.0)*raio;
        coordenadas5.y = -(altura*0.5);
        coordenadas5.z = -sin((i+1)*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas5);

        coordenadas6.x = cos((i+1)*desl1*M_PI/180.0)*raio;
        coordenadas6.y = altura*0.5;
        coordenadas6.z = -sin((i+1)*desl1*M_PI/180.0)*raio;
        resultado.push_back(coordenadas6);

    }

    return resultado;
}


