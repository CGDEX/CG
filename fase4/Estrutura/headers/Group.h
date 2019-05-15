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
    std::vector<Vertices*> normal;
    std::vector<Vertices*> textura;



    std::vector<Group*> filhos;

    //VBOS
    GLuint buffer[3];
    int nvertices;
    int nnormais;
    int ntexturas;
    float* v;
    float* n;
    float* t;



    unsigned int tt, width, height;
    unsigned int texID;
    unsigned char *data;

    std::string nomeTextura;



    public:
        Group();
        void setFilho(std::vector<Group*> g);
        void insereTransformacoes(Transformacao* t);

        void insereVerts(std::vector<Vertices*> vert);
        void insereNorms(std::vector<Vertices*> nms);
        void insereTexts(std::vector<Vertices*> texts);
        void insereFilho(Group* f);
        void insereNome(std::string name);
        Transformacao* getTransformacoes();


        std::vector<Group*> getFilhos();
        std::string getNome();
        void desenha();
        void VBO();

        void insereTextura(std::string text);
        std::string getTextura();




        void novaTextura();
        unsigned int getTexID();


};


#endif //GENERATOR_GROUP_H
