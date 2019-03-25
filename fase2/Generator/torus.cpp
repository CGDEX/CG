#include "../Estrutura/Vertices.h"
#include <algorithm>
#include <vector>
#include <math.h>



std::vector<Vertices*> createTorus(float distancia, float raio, float slices, float stacks) {
    std::vector<Vertices*> resultado;

    float alpha = 0;
    float theta = 0;
    float desl1 = (2*M_PI)/slices;
    float desl2 = (2*M_PI)/stacks;


    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();



    for (int i=0;i< slices; i++) {
        alpha = i*desl1;

        for(int j=0; j<stacks; j++) {
            theta = j*desl2;


            coordenadas1->insereX((raio+distancia*cos(theta))*cos(alpha));
            coordenadas1->insereY(distancia*sin(theta));
            coordenadas1->insereZ((raio+distancia*cos(theta))*sin(alpha));
            resultado.push_back(coordenadas1);

            coordenadas2->insereX((raio+distancia*cos(theta))*cos(alpha+desl1));
            coordenadas2->insereY(distancia*sin(theta));
            coordenadas2->insereZ((raio+distancia*cos(theta))*sin(alpha+desl1));
            resultado.push_back(coordenadas2);

            coordenadas3->insereX((raio+distancia*cos(theta+desl2))*cos(alpha+desl1));
            coordenadas3->insereY(distancia*sin(theta+desl2));
            coordenadas3->insereZ((raio+distancia*cos(theta+desl2))*sin(alpha+desl1));
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6->insereX((raio+distancia*cos(theta+desl2))*cos(alpha));
            coordenadas6->insereY(distancia*sin(theta+desl2));
            coordenadas6->insereZ((raio+distancia*cos(theta+desl2))*sin(alpha));
            resultado.push_back(coordenadas6);

        }
    }
    return resultado;
}
