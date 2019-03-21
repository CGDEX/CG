#include "../Estrutura/structure.h"
#include "tinyxml2.h"



int achouT = 0;
translations* translacao = new translations();

int achouS = 0;
scales* escala = new scales();

int achouR = 0;
rotations* rotacao = new rotations();

int i=0;

std::vector<Structure*> estrut;


// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
std::vector<vertices*> lerFicheiro(std::string caminho) {

    std::ifstream ficheiro(caminho);
    std::string linha;
    std::vector<vertices*> verts;

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



std::vector<vertices*>  parserFiguras(tinyxml2::XMLElement* elemento) {
    std::cout<<"dasjdosaijdoisa"<<std::endl;
    std::vector<vertices*> verts;
    for(elemento=elemento->FirstChildElement();elemento;elemento=elemento->NextSiblingElement()) {
        std::cout<<"ciclo for parserFiguras"<<std::endl;
        std::string caminho3D= "../Files3D/";
        caminho3D.append(elemento->Attribute("file"));
        std::cout<<"caminho: "<<caminho3D<<std::endl;
        verts = lerFicheiro(caminho3D);
    }
    return verts;
}

void parserRotation(tinyxml2::XMLElement* elemento,rotations* rotate) {

    elemento->QueryFloatAttribute("angle",&(rotate->angle));
    elemento->QueryFloatAttribute("axisX",&(rotate->x));
    elemento->QueryFloatAttribute("axisY",&(rotate->y));
    elemento->QueryFloatAttribute("axisZ",&(rotate->z));
}

void parserTranslate(tinyxml2::XMLElement* elemento,translations* transl) {

    elemento->QueryFloatAttribute("X",&(transl->x));
    elemento->QueryFloatAttribute("Y",&(transl->y));
    elemento->QueryFloatAttribute("Z",&(transl->z));
}

void parserScale(tinyxml2::XMLElement* elemento,scales* scale) {


    elemento->QueryFloatAttribute("X",&(scale->x));
    elemento->QueryFloatAttribute("Y",&(scale->y));
    elemento->QueryFloatAttribute("Z",&(scale->z));

    if(scale->x==0) scale->x=1;
    if(scale->y==0) scale->y=1;
    if(scale->z==0) scale->z=1;

}


std::vector<Structure*> parserElementos(tinyxml2::XMLElement* elemento) {
    tinyxml2::XMLElement* atual = elemento;



    if(!(strcmp(elemento->Name(),"models"))) {
        std::vector<vertices*> coords;
        Structure* temp = new Structure();

        coords=parserFiguras(elemento);

        temp->insertCoords(coords);

        if(achouT==1) {
            temp->insertTranslate(translacao);
            achouT=0;
        }
        if(achouS==1) {
            temp->insertScale(escala);
            achouS=0;
        }
        if(achouR==1) {
            temp->insertRotacao(rotacao);
            achouR=0;
        }

        estrut.push_back(temp);


        i++;
    }
    else if (!(strcmp(elemento->Name(),"group"))){

        std::cout<<"chegou ao if group"<<std::endl;
        elemento = elemento->FirstChildElement();
        parserElementos(elemento);
    }
    else if (!(strcmp(elemento->Name(),"translate"))) {
        std::cout<<"chegou ao if translate"<<std::endl;
        achouT=1;
        parserTranslate(elemento,translacao);
    }
    else if(!(strcmp(elemento->Name(),"rotate"))) {
        std::cout<<"chegou ao if rotate"<<std::endl;
        parserRotation(elemento,rotacao);
        achouR=1;
    }
    else if(!(strcmp(elemento->Name(),"scale"))) {
        achouS=1;
        parserScale(elemento,escala);
    }

    atual = atual->NextSiblingElement();
    if(atual) {
        parserElementos(atual);
    }



    return estrut;
}


// Função que recebe o caminho de um ficheiro XML e depois vai ler esse mesmo ficheiro utilizando o parser tinyxml2.
std::vector<Structure*> lerXML(std::string caminho) {
    std::vector<Structure*> structure;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;
    std::cout<<"A LER O XML!"<<std::endl;

    if(!(doc.LoadFile(caminho.c_str()))) {
        elem = doc.FirstChildElement("scene")->FirstChildElement();
        structure = parserElementos(elem);
    }

    else {
        std::cout << "Bip bip! Erro xml! Não consegui encontrar o ficheiro :(" << std::endl;
    }


    return structure;
}

