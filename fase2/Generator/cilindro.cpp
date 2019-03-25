#include "../Estrutura/Vertices.h"
#include <algorithm>
#include <vector>
#include <math.h>


// Função que cria um vector com as coordenadas de vários pontos para criar um cilindro
std::vector<Vertices*> cilindro (float raio, float altura,  int slices) {

    std::vector<Vertices*> resultado;
    int i;
    float desl1 = 360.0/slices;



    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();



    // Parte de cima
    for (i=0;i<slices;i++) {
        coordenadas1->insereX(0);
        coordenadas1->insereY(altura*0.5);
        coordenadas1->insereZ(0);
        resultado.push_back(coordenadas1);

        coordenadas2->insereX(cos(i*desl1*M_PI/180.0)*raio);
        coordenadas2->insereY(altura*0.5);
        coordenadas2->insereZ(-sin(i*desl1*M_PI/180)*raio);
        resultado.push_back(coordenadas2);

        coordenadas3->insereX(cos((i+1)*desl1*M_PI/180.0)*raio);
        coordenadas3->insereY(altura*0.5);
        coordenadas3->insereZ(-sin((i+1)*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas3);

    }

    // Parte de baixo
    for (i=0;i<slices;i++) {
        coordenadas1->insereX(0);
        coordenadas1->insereZ(-(altura*0.5));
        coordenadas1->insereZ(0);
        resultado.push_back(coordenadas1);

        coordenadas2->insereX(cos((i+1)*desl1*M_PI/180.0)*raio);
        coordenadas2->insereY(-(altura*0.5));
        coordenadas2->insereZ(-sin((i+1)*desl1*M_PI/180)*raio);
        resultado.push_back(coordenadas2);

        coordenadas3->insereX(cos(i*desl1*M_PI/180.0)*raio);
        coordenadas3->insereY(-(altura*0.5));
        coordenadas3->insereZ(-sin(i*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas3);
    }

    // Corpo
    for (i=0;i<slices;i++) {
        coordenadas1->insereX(cos((i*desl1*M_PI)/180.0)*raio);
        coordenadas1->insereY(altura*0.5);
        coordenadas1->insereZ(-sin(i*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas1);

        coordenadas2->insereX(cos(i*desl1*M_PI/180.0)*raio);
        coordenadas2->insereY(-(altura*0.5));
        coordenadas2->insereZ(-sin(i*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas2);

        coordenadas3->insereX(cos((i+1)*desl1*M_PI/180.0)*raio);
        coordenadas3->insereY(altura*0.5);
        coordenadas3->insereZ(-sin((i+1)*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas3);

        coordenadas4 = coordenadas2;
        resultado.push_back(coordenadas4);

        coordenadas5->insereX(cos((i+1)*desl1*M_PI/180.0)*raio);
        coordenadas5->insereY(-(altura*0.5));
        coordenadas5->insereZ(-sin((i+1)*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas5);

        coordenadas6->insereX(cos((i+1)*desl1*M_PI/180.0)*raio);
        coordenadas6->insereY(altura*0.5);
        coordenadas6->insereZ(-sin((i+1)*desl1*M_PI/180.0)*raio);
        resultado.push_back(coordenadas6);

    }

    return resultado;
}


