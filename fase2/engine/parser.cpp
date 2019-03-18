#include "../Estrutura/structure.h"
#include "tinyxml2.h"


// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
void lerFicheiro(std::string caminho,Structure* structure) {
    std::vector<vertices*> resultado;
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

            resultado.push_back(vertice);

        }
        structure->setCoordenadas(resultado);
    }
}



void parserFiguras(tinyxml2::XMLElement* elemento,Structure* structure) {


    std::cout<<"JDIOSJADOSIJADIOSJAODIJ"<<std::endl;
    for(elemento=elemento->FirstChildElement();elemento;elemento=elemento->NextSiblingElement()) {
        std::cout<<"ciclo for parserFiguras"<<std::endl;
        std::string caminho3D= "../Files3D/";
        caminho3D.append(elemento->Attribute("file"));
        std::cout<<"caminho: "<<caminho3D<<std::endl;
        lerFicheiro(caminho3D,structure);
    }


}

void parserRotation(tinyxml2::XMLElement* elemento,Structure* structure) {
    std::cout<<"PARSING ROTATION!"<<std::endl;
    std::cout<<"parserRotation - Elemento nome: " <<elemento->Name() <<std::endl;

    rotations* resultado = new rotations();

    elemento->QueryFloatAttribute("angle",&(resultado->angle));
    elemento->QueryFloatAttribute("axisX",&(resultado->x));
    elemento->QueryFloatAttribute("axisY",&(resultado->y));
    elemento->QueryFloatAttribute("axisZ",&(resultado->z));

    std::cout<<resultado->angle<<std::endl;


    structure->insertRotacao(resultado);
}

void parserTranslate(tinyxml2::XMLElement* elemento,Structure* structure) {


    translations* resultado = new translations();


    elemento->QueryFloatAttribute("X",&(resultado->x));
    elemento->QueryFloatAttribute("Y",&(resultado->y));
    elemento->QueryFloatAttribute("Z",&(resultado->z));
    std::cout<< "X: " <<resultado->x << " Y: " << resultado->y << " Z: " << resultado->z <<std::endl;
    structure->insertTranslate(resultado);
}

void parserScale(tinyxml2::XMLElement* elemento,Structure* structure) {


    scales* resultado = new scales();

    float x=0;
    float y=0;
    float z=0;

    elemento->QueryFloatAttribute("X",&x);
    elemento->QueryFloatAttribute("Y",&y);
    elemento->QueryFloatAttribute("Z",&z);

    if(x==0) x=1;
    if(y==0) y=1;
    if(z==0) z=1;

    structure->insertScale(resultado);

}





void parserElementos(tinyxml2::XMLElement* elemento,Structure* structure) {
    tinyxml2::XMLElement* atual = elemento;


    if(!(strcmp(elemento->Name(),"models"))) {
        std::cout<<"chegou ao if models"<<std::endl;
        parserFiguras(elemento,structure);
    }
    else if (!(strcmp(elemento->Name(),"group"))){
        std::cout<<"chegou ao if group"<<std::endl;
        elemento = elemento->FirstChildElement();
        parserElementos(elemento,structure);
    }
    else if (!(strcmp(elemento->Name(),"translate"))) {
        std::cout<<"chegou ao if translate"<<std::endl;
        parserTranslate(elemento,structure);
    }
    else if(!(strcmp(elemento->Name(),"rotate"))) {
        std::cout<<"chegou ao if rotate"<<std::endl;
        parserRotation(elemento,structure);
    }
    else if(!(strcmp(elemento->Name(),"scale"))) {
        std::cout<<"chegou ao if scale"<<std::endl;
    }


    atual = atual->NextSiblingElement();
    if(atual) {
        parserElementos(atual,structure);
    }
}


// Função que recebe o caminho de um ficheiro XML e depois vai ler esse mesmo ficheiro utilizando o parser tinyxml2.
void lerXML(std::string caminho, Structure* structure) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;
    std::cout<<"A LER O XML!"<<std::endl;

    if(!(doc.LoadFile(caminho.c_str()))) {
        elem = doc.FirstChildElement("scene")->FirstChildElement();
        parserElementos(elem,structure);
    }

    else {
        std::cout << "Bip bip! Erro xml! Não consegui encontrar o ficheiro :(" << std::endl;
    }
}

