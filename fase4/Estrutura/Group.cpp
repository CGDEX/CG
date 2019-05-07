#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "headers/Group.h"

Group::Group(){

}


void Group::insereTransformacoes(Transformacao* t) {
    tranformacoes = t;
}
/*
void Group::insereVerts(std::vector<Vertices*> vert) {

    vertics = vert;
}
*/

void Group::insereFiguras(std::vector<Forma*> figrs) {
    figuras = figrs;
}



void Group::insereFilho(Group* f) {
    filhos.push_back(f);
}

void Group::insereNome(std::string name) {
    nome = name;
}
Transformacao* Group::getTransformacoes() {
    return tranformacoes;
}
/*
std::vector<Vertices*> Group::getVertices() {
    return vertics;
}
*/

std::vector<Forma*> Group::getFormas() {
    return figuras;
}
std::vector<Group*> Group::getFilhos() {
    return filhos;
}

std::string Group::getNome() {
    return nome;
}

void Group::desenha() {
    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glVertexPointer(3,GL_FLOAT,0,0);
    glDrawArrays(GL_TRIANGLES,0,nvertices);
}

void Group::VBO() {
    glEnableClientState(GL_VERTEX_ARRAY);
    float* vert = (float*) malloc(sizeof(float)*vertics.size()*3);

    for(int i=0;i<vertics.size();i++) {

        vert[nvertices] = vertics[i]->getX1();
        vert[nvertices+1] = vertics[i]->getY1();
        vert[nvertices+2] = vertics[i]->getZ1();
        nvertices+=3;
    }

    glGenBuffers(1,buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertics.size()*3,vert,GL_STATIC_DRAW);
    free(vert);
}

void Group::setFilho(std::vector<Group*> g) {
    filhos = g;
}

void Group::insereN(int n) {
    nvertices = n;
}


void Group::insereTextura(std::string text) {
    textura = text;
}

std::string Group::getTextura() {
    return textura;
}