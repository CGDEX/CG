#include "Transformacao.h"
#include "Vertices.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#ifndef GENERATOR_GROUP_H
#define GENERATOR_GROUP_H


class Group {
    std::string nome;
    Transformacao* tranformacoes;
    std::vector<Vertices*> vertics;
    std::vector<Group*> filhos;
    GLuint buffer[3];
    int nvertices;



    public:
        Group();

        void insereTransformacoes(Transformacao* t);
        void insereVerts(std::vector<Vertices*> vert);
        void insereFilho(Group* f);
        void insereNome(std::string name);
        Transformacao* getTransformacoes();
        std::vector<Vertices*> getVertices();
        std::vector<Group*> getFilhos();
        std::string getNome();
        void desenha();


};


#endif //GENERATOR_GROUP_H
