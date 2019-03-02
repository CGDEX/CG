#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include "../Estrutura/estrutura.h"
#include "tinyxml2.h"

std::vector<vertices> estrutura;

void lerFicheiro(std::string caminho) {

    std::ifstream ficheiro(caminho);
    std::string linha;

    if(ficheiro.fail()) {
        std::cout << "Doh, não consegui encontrar o ficheiro 3D!"<< std::endl;
    }
    else {
        while(getline(ficheiro,linha)) {
            vertices coordenadas;
            size_t pos;
            coordenadas.x = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            coordenadas.y = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            coordenadas.z = std::stof(linha,&pos);

            estrutura.push_back(coordenadas);
        }
    }
}

void lerXML(std::string caminho) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;

    if(!(doc.LoadFile(caminho.c_str()))) {

        elem = doc.FirstChildElement();

        for (elem = elem->FirstChildElement();elem;elem = elem->NextSiblingElement()){
            std::string caminho3D= "../Files3D/";
            caminho3D.append(elem->Attribute("file"));
            lerFicheiro(caminho3D);
        }
    }
    else {
        std::cout << "Doh, não encontrei o ficheiro :(" << std::endl;
    }
}

int main(int argc, char** argv) {

    lerXML(argv[1]);

    std::vector<vertices>::iterator it;
    for (it=estrutura.begin();it!=estrutura.end();it++) {
        std::cout << "coordenada x: " << it->x << " coordenada y: " << it->y << " coordenada z: " << it->z << std::endl;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Homer Simpson's Engine");



    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutMainLoop();
}