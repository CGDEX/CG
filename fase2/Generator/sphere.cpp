#include "../Estrutura/Vertices.h"
#include <algorithm>
#include <vector>
#include <math.h>

// Função que cria um vector com as coordenadas de vários pontos para criar uma esfera
std::vector<Vertices*> esfera (float raio, int slices, int stacks) {

    // STACKS - CAMADAS HORIZONTAIS
    // SLICES - VERTICAL

    std::vector<Vertices*> resultado;

    float desl1 = (2*M_PI)/slices;
    float desl2 = (M_PI)/stacks;

    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();

    float a,b = 0;

    for (int i=0;i<stacks;i++) {
        a=0;
        for(int j=0;j<slices;j++) {


            coordenadas1->insereX(raio*sin(b)*sin(a));
            coordenadas1->insereY(raio*cos(b));
            coordenadas1->insereZ(raio*sin(b)*cos(a));
            resultado.push_back(coordenadas1);

            coordenadas2->insereX(raio*sin(b+desl2)*sin(a+desl1));
            coordenadas2->insereY(raio*cos(b+desl2));
            coordenadas2->insereZ(raio*sin(b+desl2)*cos(a+desl1));
            resultado.push_back(coordenadas2);

            coordenadas3->insereX(raio*sin(a+desl1)*sin(b));
            coordenadas3->insereY(raio*cos(b));
            coordenadas3->insereZ(raio*sin(b)*cos(a+desl1));
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);


            coordenadas5->insereX(raio*sin(a)*sin(b+desl2));
            coordenadas5->insereY(raio*cos(b+desl2));
            coordenadas5->insereZ(raio*sin(b+desl2)*cos(a));
            resultado.push_back(coordenadas5);

            coordenadas6 = coordenadas2;
            resultado.push_back(coordenadas6);


            a = (j+1)*desl1;
        }
        b = (i+1)*desl2;
    }

    return resultado;
}
