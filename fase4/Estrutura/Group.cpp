#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "headers/Group.h"
#include <IL/il.h>
Group::Group(){

}


void Group::insereTransformacoes(Transformacao* t) {
    tranformacoes = t;
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

    if(normal.size() != 0){
        glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
        glNormalPointer(GL_FLOAT, 0 , 0);
    }
    if(textura.size() != 0){
        glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
        glTexCoordPointer(2 , GL_FLOAT, 0 , 0); // 2 porque é o numero de coordenadas das texturas
    }

    glDrawArrays(GL_TRIANGLES,0,nvertices);
}

void Group::VBO() {

    size_t i=0;
    int p=0;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    v = (float*) malloc(sizeof(float) * vertics.size()*3);
    n = (float*) malloc(sizeof(float) * normal.size()*3);
    t = (float*) malloc(sizeof(float) * textura.size()*2);

    for(i=0; i < vertics.size(); i++) {
        v[p] = vertics[i]->getX1();
        v[p + 1] = vertics[i]->getY1();
        v[p + 2] = vertics[i]->getZ1();
        p += 3;
    }

    p = 0;

    for(i=0; i < normal.size(); i++){
        n[p] = normal[i]->getX1();
        n[p+1] = normal[i]->getY1();
        n[p+2] = normal[i]->getZ1();
        p+=3;
    }

    p = 0;
    for(i=0; i < textura.size(); i++){
        t[p] = textura[i]->getX1();
        t[p+1]  = textura[i]->getY1();
        p+=2;
    }

    nvertices = vertics.size() * 3;
    nnormais = normal.size() * 3;
    ntexturas= textura.size() * 2;

    glGenBuffers(3,buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*nvertices,v,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*nnormais,n,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*ntexturas,t,GL_STATIC_DRAW);


    free(v);
    free(n);
    free(t);
    novaTextura();
}

unsigned int Group::getTexID() {
    return texID;
}

void Group::novaTextura() {

    std::string caminho = "../Texturas/" + nomeTextura;

    ilGenImages(1, &tt);
    ilBindImage(tt);
    ilLoadImage((ILstring) caminho.c_str());
    width =  (unsigned int) ilGetInteger(IL_IMAGE_WIDTH);
    height = (unsigned int) ilGetInteger(IL_IMAGE_HEIGHT);
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    data = ilGetData();
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height,
                      GL_RGBA, GL_UNSIGNED_BYTE, data);

}

void Group::setFilho(std::vector<Group*> g) {
    filhos = g;
}



void Group::insereTextura(std::string text) {
    nomeTextura = text;
}

std::string Group::getTextura() {
    return nomeTextura;
}





void Group::insereVerts(std::vector<Vertices *> vert) {
    vertics = vert;
}

void Group::insereNorms(std::vector<Vertices *> nms) {
    normal = nms;
}

void Group::insereTexts(std::vector<Vertices *> texts) {
    textura = texts;
}