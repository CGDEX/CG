#include "./engine.h"
#include "../Estrutura/estrutura.h"
#include "tinyxml2.h"


// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
void lerFicheiro(std::string caminho,Estrutura* structure) {
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



void parserFiguras(tinyxml2::XMLElement* elemento,Estrutura* structure) {


    std::cout<<"JDIOSJADOSIJADIOSJAODIJ"<<std::endl;
    for(elemento=elemento->FirstChildElement();elemento;elemento=elemento->NextSiblingElement()) {
        std::cout<<"ciclo for parserFiguras"<<std::endl;
        std::string caminho3D= "../Files3D/";
        caminho3D.append(elemento->Attribute("file"));
        std::cout<<"caminho: "<<caminho3D<<std::endl;
        lerFicheiro(caminho3D,structure);
    }


}

void parserRotation(tinyxml2::XMLElement* elemento) {
    std::cout<<"PARSING ROTATION!"<<std::endl;
    std::cout<<"parserRotation - Elemento nome: " <<elemento->Name() <<std::endl;
    float x=0;
    elemento->QueryFloatAttribute("angle",&x);

    std::cout<<x<<std::endl;

}





void parserElementos(tinyxml2::XMLElement* elemento,Estrutura* structure) {
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
    }
    else if(!(strcmp(elemento->Name(),"rotate"))) {
        std::cout<<"chegou ao if rotate"<<std::endl;
        parserRotation(elemento);
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
void lerXML(std::string caminho, Estrutura* structure) {
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

