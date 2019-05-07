#include "../Estrutura/headers/estrutura.h"
#include <algorithm>
#include <vector>
#include <math.h>

// Função que cria um vector com as coordenadas de vários pontos para criar uma esfera
Forma* esfera (float raio, int slices, int stacks) {

    // STACKS - CAMADAS HORIZONTAIS
    // SLICES - VERTICAL

    Forma* resultado = new Forma();

    float desl1 = (2*M_PI)/slices;
    float desl2 = (M_PI)/stacks;
    float textV = 1/(float)stacks;
    float textH = 1/(float) slices;



    float a,b = 0;

    for (int i=0;i<stacks;i++) {
        a=0;
        for(int j=0;j<slices;j++) {


            float x1= raio*sin(b)*sin(a);
            float y1 = raio*cos(b);
            float z1 = raio*sin(b)*cos(a);


            float x2 = raio*sin(b+desl2)*sin(a+desl1);
            float y2 = raio*cos(b+desl2);
            float z2 = raio*sin(b+desl2)*cos(a+desl1);


            float x3 = raio*sin(a+desl1)*sin(b);
            float y3 = raio*cos(b);
            float z3 = raio*sin(b)*cos(a+desl1);


            float x4 = raio*sin(a)*sin(b+desl2);
            float y4 = raio*cos(b+desl2);
            float z4 = raio*sin(b+desl2)*cos(a);


            resultado->insereVerts(new Vertices(x1,y1,z1));
            resultado->insereVerts(new Vertices(x2,y2,z2));
            resultado->insereVerts(new Vertices(x3,y3,z3));


            resultado->insereNorms(new Vertices(x1/raio,y1/raio,z1/raio));
            resultado->insereNorms(new Vertices(x2/raio,y2/raio,z2/raio));
            resultado->insereNorms(new Vertices(x3/raio,y3/raio,z3/raio));


            resultado->insereVerts(new Vertices(x1,y1,z1));
            resultado->insereVerts(new Vertices(x3,y3,z3));
            resultado->insereVerts(new Vertices(x4,y4,z4));


            resultado->insereNorms(new Vertices(x1/raio,y1/raio,z1/raio));
            resultado->insereNorms(new Vertices(x3/raio,y3/raio,z3/raio));
            resultado->insereNorms(new Vertices(x4/raio,y4/raio,z4/raio));


            resultado->insereTexts(new Vertices(j*textV,i*textH,0));
            resultado->insereTexts(new Vertices(j*textV + textV,i*textH + textH,0));
            resultado->insereTexts(new Vertices(j*textV + textV,i*textH,0));

            resultado->insereTexts(new Vertices(j*textV + textV,i*textH + textH,0));
            resultado->insereTexts(new Vertices(j*textV,i*textH,0));
            resultado->insereTexts(new Vertices(j*textV,i*textH + textH,0));


            a = (j+1)*desl1;
        }
        b = (i+1)*desl2;
    }

    return resultado;
}