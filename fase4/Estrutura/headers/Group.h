#include "Transformacao.h"
#include "Vertices.h"

#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "Forma.h"
#ifndef GENERATOR_GROUP_H
#define GENERATOR_GROUP_H


class Group {
    std::string nome;
    Transformacao* tranformacoes;
    //std::vector<Vertices*> vertics;
    std::vector<Forma*> figuras;
    std::vector<Group*> filhos;
    GLuint buffer[3];
    int nvertices;




    std::string textura;



    public:
        Group();
        void setFilho(std::vector<Group*> g);
        void insereTransformacoes(Transformacao* t);
        void insereFiguras(std::vector<Forma*> figrs);
        //void insereVerts(std::vector<Vertices*> vert);
        void insereFilho(Group* f);
        void insereNome(std::string name);
        Transformacao* getTransformacoes();
        //std::vector<Vertices*> getVertices();
        std::vector<Forma*> getFormas();
        std::vector<Group*> getFilhos();
        std::string getNome();
        void desenha();
        void VBO();
        void insereN(int n);
        void insereTextura(std::string text);
        std::string getTextura();


};


#endif //GENERATOR_GROUP_H
