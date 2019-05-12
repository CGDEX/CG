#include "../Estrutura/headers/estrutura.h"
#include "../Estrutura/headers/Vertices.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

// Função que cria um vector com as coordenadas de vários pontos para criar uma esfera
void sphere (float radius, int slices, int stacks){
    ofstream file("../Files3D/sphere.3d");

    std::vector<Vertices*> normal;
    std::vector<Vertices*> textura;
    Vertices* aux;

    float a = 0, h = 0;
    float desl1 = (2 * M_PI)/slices;
    float desl2 = M_PI/stacks;

    float texH = 1 / (float)slices;
    float texV = 1 / (float)stacks;

    for(int i = 0; i < stacks; i++){
        a = 0;

        for(int j = 0; j < slices;j++){
            float x1 = (radius*sin(a)*sin(h));
            float y1 = (radius*cos(h));
            float z1 = (radius*cos(a)*sin(h));

            float x2 = (radius*sin(a+desl1)*sin(h+desl2));
            float y2 = (radius*cos(h+desl2));
            float z2 = (radius*cos(a+desl1)*sin(h+desl2));

            float x3 = (radius*sin(a+desl1)*sin(h));
            float y3 = (radius*cos(h));
            float z3 = (radius*cos(a+desl1)*sin(h));

            float  x4 = (radius*sin(a)*sin(h+desl2));
            float  y4 = (radius*cos(h+desl2));
            float  z4 = (radius*cos(a)*sin(h+desl2));


            file << x1 << "," << y1 << "," << z1 << endl;
            aux = Vertices::normalCalc(new Vertices(x1,y1,z1));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH,i*texV + texV,0));



            file << x2 << "," << y2 << "," << z2 << endl;
            aux = Vertices::normalCalc(new Vertices(x2,y2,z2));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH + texH,i*texV,0));



            file << x3 << "," << y3 << "," << z3 << endl;
            aux = Vertices::normalCalc(new Vertices(x3,y3,z3));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH + texH, i*texV + texV, 0));



            file << x1 << "," << y1 << "," << z1 << endl;
            aux = Vertices::normalCalc(new Vertices(x1,y1,z1));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH,i*texV + texV,0));


            file << x4 << "," << y4 << "," << z4 << endl;
            aux = Vertices::normalCalc(new Vertices(x4,y4,z4));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH, i*texV, 0));



            file << x2 << "," << y2 << "," << z2 << endl;
            aux = Vertices::normalCalc(new Vertices(x2,y2,z2));
            normal.push_back(aux);
            textura.push_back(new Vertices(j*texH + texH, i*texV + texV, 0));

            a= (j+1) * desl1;
        }

        h= (i+1) * desl2;
    }


    file <<">>normais<<" << endl;
    for(int i=0;i<normal.size();i++) {
        file << normal[i]->getX1() << "," << normal[i]->getY1() << "," << normal[i]->getZ1()<< endl;
    }


    file << ">>texturas<<" << endl;
    for(int i = textura.size() - 1; i >= 0; i-=3){
        file << textura[i]->getX1() << "," << textura[i]->getY1()<< "," << textura[i]->getZ1() << endl;
        file << textura[i-1]->getX1() << "," << textura[i-1]->getY1()<< "," << textura[i-1]->getZ1() << endl;
        file << textura[i-2]->getX1() << "," << textura[i-2]->getY1()<< "," << textura[i-2]->getZ1() << endl;
    }
    file.close();
}


