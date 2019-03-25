#include "Transformacao.h"
#include "Vertices.h"
#include <iostream>
#include <vector>

#ifndef GENERATOR_GROUP_H
#define GENERATOR_GROUP_H


class Group {
    Transformacao* tranformacoes;
    std::vector<Vertices*> vertics;
    std::vector<Group*> next;


    public:
        Group();
        Group(Transformacao* t, std::vector<Vertices*> vert, std::vector<Group*> n);
        void insereTransformacoes(Transformacao* t);
        void insereVerts(std::vector<Vertices*> vert);
        void insereNext(std::vector<Group*> n);
        Transformacao* getTransformacoes();
        std::vector<Vertices*> getVertices();
        std::vector<Group*> getGroups();
};


#endif //GENERATOR_GROUP_H
