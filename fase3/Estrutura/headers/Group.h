#include "Transformacao.h"
#include "Vertices.h"

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
        void setFilho(std::vector<Group*> g);
        void insereTransformacoes(Transformacao* t);
        void insereVerts(std::vector<Vertices*> vert);
        void insereFilho(Group* f);
        void insereNome(std::string name);
        Transformacao* getTransformacoes();
        std::vector<Vertices*> getVertices();
        std::vector<Group*> getFilhos();
        std::string getNome();
        void desenha();
        void VBO();
        void insereN(int n);



};


#endif //GENERATOR_GROUP_H
