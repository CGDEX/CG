#include "../Estrutura/structure.h"
#include "tinyxml2.h"




// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
std::vector<vertices*> lerFicheiro(std::string caminho) {
    std::vector<vertices*> verts;
    std::ifstream ficheiro(caminho);
    std::string linha;


    if(ficheiro.fail()) {
        std::cout << "Bip bip! não consegui encontrar o ficheiro 3D!"<< std::endl;
    }
    else {
        while(getline(ficheiro,linha)) {
            vertices* vertice = new vertices();

            size_t pos;
            vertice->x = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            vertice->y = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            vertice->z = std::stof(linha,&pos);

            verts.push_back(vertice);
        }
    }

    return verts;
}



void parserFiguras(tinyxml2::XMLElement* elemento, Structure* estrutura) {


    std::vector<vertices*> verts;
    for(elemento=elemento->FirstChildElement();elemento;elemento=elemento->NextSiblingElement()) {

        std::string caminho3D= "../Files3D/";
        caminho3D.append(elemento->Attribute("file"));

        verts = lerFicheiro(caminho3D);
        estrutura->insereCoords(verts);

    }



}

void parserRotation(tinyxml2::XMLElement* elemento,Structure* estrutura) {
    float angulo = 0, x = 0, y = 0, z = 0;
    elemento->QueryFloatAttribute("angle",&angulo);
    elemento->QueryFloatAttribute("axisX",&x);
    elemento->QueryFloatAttribute("axisY",&y);
    elemento->QueryFloatAttribute("axisZ",&z);



    Rotacao* rotacao = new Rotacao(x,y,z,angulo);

    estrutura->insereRotacao(rotacao);

}

void parserTranslate(tinyxml2::XMLElement* elemento, Structure* estrutura) {
    float x = 0, y = 0, z = 0;

    elemento->QueryFloatAttribute("X",&x);
    elemento->QueryFloatAttribute("Y",&y);
    elemento->QueryFloatAttribute("Z",&z);

    Translacao* transl = new Translacao(x,y,z);

    estrutura->insereTranslacao(transl);

}

void parserScale(tinyxml2::XMLElement* elemento,Structure* estrutura) {
    float x = 1, y = 1, z = 1;

    elemento->QueryFloatAttribute("X",&x);
    elemento->QueryFloatAttribute("Y",&y);
    elemento->QueryFloatAttribute("Z",&z);

    Escala* escala = new Escala(x,y,z);

    estrutura->insereEscala(escala);

}


void parserElementos(tinyxml2::XMLElement* elemento,Structure* estrutura) {
    tinyxml2::XMLElement* atual = elemento;

    if(!(strcmp(elemento->Name(),"models"))) {
        parserFiguras(elemento,estrutura);
    }
    else if (!(strcmp(elemento->Name(),"group"))){
        Structure* children = new Structure();
        estrutura->insereNext(children);
        elemento = elemento->FirstChildElement();
        parserElementos(elemento,children);
    }
    else if (!(strcmp(elemento->Name(),"translate"))) {

        parserTranslate(elemento,estrutura);
    }
    else if(!(strcmp(elemento->Name(),"rotate"))) {

        parserRotation(elemento,estrutura);

    }
    else if(!(strcmp(elemento->Name(),"scale"))) {
        parserScale(elemento,estrutura);
    }

    atual = atual->NextSiblingElement();
    if(atual) {
        parserElementos(atual,estrutura);
    }


}


// Função que recebe o caminho de um ficheiro XML e depois vai ler esse mesmo ficheiro utilizando o parser tinyxml2.
Structure* lerXML(std::string caminho, Structure* estrutura) {

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;


    if(!(doc.LoadFile(caminho.c_str()))) {
        elem = doc.FirstChildElement("scene")->FirstChildElement();
         parserElementos(elem,estrutura);
    }

    else {
        std::cout << "Bip bip! Erro xml! Não consegui encontrar o ficheiro :(" << std::endl;
    }


    return estrutura;
}
