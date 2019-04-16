#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "Group.h"

Group::Group(){

}


void Group::insereTransformacoes(Transformacao* t) {
    tranformacoes = t;
}

void Group::insereVerts(std::vector<Vertices*> vert) {

    vertics = vert;
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

std::vector<Vertices*> Group::getVertices() {
    return vertics;
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