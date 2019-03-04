#include "./plano.cpp"
#include <math.h>

std::vector<vertices> esfera (float raio, int slices, int stacks) {

    // STACKS - CAMADAS HORIZONTAIS
    // SLICES - VERTICAL

    std::vector<vertices> resultado;

    float desl1 = (2*M_PI)/slices;
    float desl2 = (M_PI)/stacks;

    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

    float a,b = 0;

    for (int i=0;i<stacks;i++) {
        a=0;
        for(int j=0;j<slices;j++) {


            coordenadas1.x = raio*sin(b)*sin(a);
            coordenadas1.y = raio*cos(b);
            coordenadas1.z = raio*sin(b)*cos(a);
            resultado.push_back(coordenadas1);

            coordenadas2.x = raio*sin(b+desl2)*sin(a+desl1);
            coordenadas2.y = raio*cos(b+desl2);
            coordenadas2.z = raio*sin(b+desl2)*cos(a+desl1);
            resultado.push_back(coordenadas2);

            coordenadas3.x = raio*sin(a+desl1)*sin(b);
            coordenadas3.y = raio*cos(b);
            coordenadas3.z = raio*sin(b)*cos(a+desl1);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);


            coordenadas5.x = raio*sin(a)*sin(b+desl2);
            coordenadas5.y = raio*cos(b+desl2);
            coordenadas5.z = raio*sin(b+desl2)*cos(a);
            resultado.push_back(coordenadas5);

            coordenadas6 = coordenadas2;
            resultado.push_back(coordenadas6);


            a = (j+1)*desl1;
        }
        b = (i+1)*desl2;
    }

    return resultado;
}
