#include "../Estrutura/Vertices.h"
#include <algorithm>
#include <vector>
#include <math.h>
// Função que cria um vector com as coordenadas de vários pontos para criar um cone
std::vector<Vertices*> cone (float raio, float altura,  int slices, int stacks) {

    std::vector<Vertices*> resultado;

    float desl1 = (2*M_PI)/slices; // Horizontal
    float desl2 = altura/stacks; // Vertical
    float alt = -(altura/2);
    float desl_r = raio/stacks;


    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();

    float a,novo_raio= 0;


    for (int i=0;i<slices;i++) {

        coordenadas1->insereX(raio*sin(a));
        coordenadas1->insereY((-altura)/2);
        coordenadas1->insereZ(raio*cos(a));
        resultado.push_back(coordenadas1);


        coordenadas2->insereX(0);
        coordenadas2->insereY((-altura)/2);
        coordenadas2->insereZ(0);
        resultado.push_back(coordenadas2);

        coordenadas3->insereX(raio*sin(a+desl1));
        coordenadas3->insereY((-altura)/2);
        coordenadas3->insereZ(raio*cos(a+desl1));
        resultado.push_back(coordenadas3);
        a+=desl1;
    }

    for (int i=0;i<stacks;i++) {
        for (int j=0;j<slices;j++) {
            a += desl1;
            novo_raio = raio-desl_r;

            coordenadas1->insereX(raio*sin(a));
            coordenadas1->insereY(alt);
            coordenadas1->insereZ(raio*cos(a));
            resultado.push_back(coordenadas1);

            coordenadas2->insereX(raio*sin(a+desl1));
            coordenadas2->insereY(alt);
            coordenadas2->insereZ(raio*cos(a+desl1));
            resultado.push_back(coordenadas2);

            coordenadas3->insereX(novo_raio*sin(a));
            coordenadas3->insereY(alt+desl2);
            coordenadas3->insereZ(novo_raio*cos(a));
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas2;
            resultado.push_back(coordenadas4);

            coordenadas5->insereX(novo_raio*sin(a+desl1));
            coordenadas5->insereY(alt+desl2);
            coordenadas5->insereZ(novo_raio*cos(a+desl1));
            resultado.push_back(coordenadas5);

            coordenadas6 = coordenadas3;
            resultado.push_back(coordenadas6);
        }
        raio -= desl_r;
        alt +=  desl2;
    }

    return resultado;
}


