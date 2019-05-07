#include "../Estrutura/headers/Group.h"
#include "tinyxml2.h"


int achouR = 0;
int achouS = 0;
int achouT = 0;
int achouC = 0;

// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
std::vector<Vertices*> lerFicheiro(std::string caminho) {

    std::vector<Vertices*> verts;
    std::ifstream ficheiro(caminho);
    std::string linha;


    if(ficheiro.fail()) {
        std::cout << "Bip bip! não consegui encontrar o ficheiro 3D!"<< std::endl;
    }
    else {
        while(getline(ficheiro,linha)) {
            size_t pos;
            Vertices* vertice = new Vertices();


            vertice->insereX1(std::stof(linha,&pos));

            linha.erase(0,pos+1);
            vertice->insereY1(std::stof(linha,&pos));

            linha.erase(0,pos+1);
            vertice->insereZ1(std::stof(linha,&pos));

            verts.push_back(vertice);
        }
    }
    return verts;
}



Rotacao* parserRotation(tinyxml2::XMLElement* elemento) {
    float angulo = 0, x = 0, y = 0, z = 0, tempo = 0;


    elemento->QueryFloatAttribute("Time",&tempo);
    elemento->QueryFloatAttribute("angle",&angulo);
    elemento->QueryFloatAttribute("axisX",&x);
    elemento->QueryFloatAttribute("axisY",&y);
    elemento->QueryFloatAttribute("axisZ",&z);

    Rotacao* rotacao = new Rotacao();
    rotacao->insereAngulo(angulo);
    rotacao->insereTempo(tempo);
    rotacao->insereX(x);
    rotacao->insereY(y);
    rotacao->insereZ(z);

    return rotacao;

}


Cor* parserColor(tinyxml2::XMLElement* elemento) {
    float r = 0, g = 0, b = 0;

    elemento->QueryFloatAttribute("R",&r);
    elemento->QueryFloatAttribute("G",&g);
    elemento->QueryFloatAttribute("B",&b);




    Cor* cor = new Cor();
    cor->insereR1(r/255);
    cor->insereG1(g/255);
    cor->insereB1(b/255);

    return cor;

}




Translacao* parserTranslate(tinyxml2::XMLElement* elemento) {

    float x = 0, y = 0, z = 0, time=0;
    Translacao* transl= new Translacao();
    std::vector<Vertices*> pontos;
    elemento->QueryFloatAttribute("Time",&time);



    for (tinyxml2::XMLElement* aux = elemento->FirstChildElement();aux; aux = aux->NextSiblingElement()) {
        aux->QueryFloatAttribute("X",&x);
        aux->QueryFloatAttribute("Y",&y);
        aux->QueryFloatAttribute("Z",&z);

        Vertices* v =  new Vertices(x,y,z);

        pontos.push_back(v);
        //v->insereX1(x);v->insereY1(y);v->insereZ1(z);
    }

    transl->inserePontosT(pontos);
    transl->insereTempo(time);


    return transl;

}

Escala* parserScale(tinyxml2::XMLElement* elemento) {

    float x = 0, y = 0, z = 0;

    elemento->QueryFloatAttribute("X",&x);
    elemento->QueryFloatAttribute("Y",&y);
    elemento->QueryFloatAttribute("Z",&z);



    Escala* escala = new Escala();
    escala->insereXE(x);
    escala->insereYE(y);
    escala->insereZE(z);

    return escala;

}



