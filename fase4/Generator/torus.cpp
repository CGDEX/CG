#include "../Estrutura/headers/estrutura.h"
#include <algorithm>
#include <vector>
#include <math.h>


void createTorus(float raioI, float raioE, float slices, float stacks) {
    std::ofstream file("../Files3D/torus.3d");

    std::vector<Vertices*> normal;
    std::vector<Vertices*> textura;

    float texturaSide = float(1) / stacks;
    float texturaRing = float(1) / slices;

    float x1,x2,x3,x4;
    float y1,y2,y3,y4;
    float z1,z2,z3,z4;


    float phi_shift = 2*M_PI / stacks;
    float theta_shift= 2*M_PI / slices;

    float theta = 0;
    float phi = 0;
    
    for(int i=0;i<slices;i++) {

        for(int j=0;j<stacks;j++) {
            x1 = cos(theta)*(raioI+raioE*cos(phi));
            y1 = sin(theta) * (raioI + raioE * cos(phi));
            z1 = raioE * sin(phi);

            x2 = cos(theta + theta_shift)*(raioI+raioE*cos(phi));
            y2 = sin(theta + theta_shift) * (raioI + raioE * cos(phi));
            z2 = raioE * sin(phi);

            x3 = cos(theta + theta_shift)*(raioI+raioE*cos(phi + phi_shift));
            y3 = sin(theta + theta_shift) * (raioI + raioE * cos(phi + phi_shift));
            z3 = raioE * sin(phi + phi_shift);

            x4 = cos(theta)*(raioI+raioE*cos(phi + phi_shift));
            y4 = sin(theta) * (raioI + raioE * cos(phi + phi_shift));
            z4 = raioE * sin(phi + phi_shift);

            file << x1 << "," << y1 << "," << z1 << endl;
            file<< x2 << "," << y2 << "," << z2 << endl;
            file<< x3 << "," << y3 << "," << z3 << endl;

            //normal
            normal.push_back(new Vertices(cos(theta)*cos(phi), sin(theta) * cos(phi), sin(phi)));
            normal.push_back(new Vertices(cos(theta + theta_shift)*cos(phi), sin(theta + theta_shift) * cos(phi), sin(phi)));
            normal.push_back(new Vertices(cos(theta + theta_shift)*cos(phi + phi_shift), sin(theta + theta_shift) * cos(phi + phi_shift), sin(phi + phi_shift)));

            //texturas
            textura.push_back(new Vertices(i*texturaRing, j*texturaSide, 0));
            textura.push_back(new Vertices((i+1)*texturaRing, j*texturaSide, 0));
            textura.push_back(new Vertices((i+1)*texturaRing, (j+1)*texturaSide, 0));

            file<< x3 << "," << y3 << "," << z3 << endl;
            file<< x4 << "," << y4 << "," << z4 << endl;
            file<< x1 << "," << y1 << "," << z1 << endl;

            //normal
            normal.push_back(new Vertices(cos(theta + theta_shift)*cos(phi + phi_shift), sin(theta + theta_shift) * cos(phi + phi_shift), sin(phi + phi_shift)));
            normal.push_back(new Vertices(cos(theta)*cos(phi + phi_shift), sin(theta) * cos(phi + phi_shift), sin(phi + phi_shift)));
            normal.push_back(new Vertices(cos(theta)*cos(phi), sin(theta) * cos(phi), sin(phi)));

            //texturas
            textura.push_back(new Vertices((i+1)*texturaRing, (j+1)*texturaSide, 0));
            textura.push_back(new Vertices(i*texturaRing, (j+1)*texturaSide, 0));
            textura.push_back(new Vertices(i*texturaRing, j*texturaSide, 0));

            phi = phi_shift * (j+1);
        }
        theta = theta_shift * (i+1) ;
    }

    file << ">>normais<<" << endl;
    for(size_t i=0;i<normal.size();i++) {
        std::cout << "OLA" <<std::endl;
        file << normal[i]->getX1() << "," << normal[i]->getY1() << "," << normal[i]->getZ1() << endl;
    }
    file << ">>texturas<<" << endl;
    for (size_t i=0; i<normal.size();i++) {
        file << textura[i]->getX1() << "," << textura[i]->getY1() << "," << textura[i]->getZ1() << endl;
    }
    file.close();
}