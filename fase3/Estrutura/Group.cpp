#include "Group.h"




Group::Group(){

}


Group::Group(Transformacao* t, std::vector<Vertices*> vert, std::vector<Group*> n) {
    tranformacoes=t;
    vertics=vert;
    next=n;
}

void Group::insereTransformacoes(Transformacao* t) {
    tranformacoes = t;
}

void Group::insereVerts(std::vector<Vertices*> vert) {

    vertics = vert;
}

void Group::insereNext(std::vector<Group*> n) {
    next = n;
}

Transformacao* Group::getTransformacoes() {
    return tranformacoes;
}

std::vector<Vertices*> Group::getVertices() {
    return vertics;
}

std::vector<Group*> Group::getGroups() {
    return next;
}