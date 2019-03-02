#include "./plano.cpp"
#include <math.h>

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

