#include "../Estrutura/Group.h"
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

void getCatmullRomPoint(float t, int* indices, float* resultado, std::vector<Vertices*> pontosT) {

    float m[4][4] = {{-0.5f, 1.5f,  -1.5f, 0.5f},
                     {1.0f,  -2.5f, 2.0f,    -0.5f},
                     {-0.5f, 0.0f,    0.5f,  0.0f},
                     {0.0f,    1.0f,    0.0f,    0.0f}};

    float quad = t*t;
    float cubo = t*t*t;
    float aux[4];

    resultado[0] = 0;
    resultado[1] = 0;
    resultado[2] = 0;

    aux[0] = (cubo * m[0][0]) + (quad * m[1][0]) + (t * m[2][0]) + (m[3][0]);
    aux[1] = (cubo * m[0][1]) + (quad * m[1][1]) + (t * m[2][1]) + (m[3][1]);
    aux[2] = (cubo * m[0][2]) + (quad * m[1][2]) + (t * m[2][2]) + (m[3][2]);
    aux[3] = (cubo * m[0][3]) + (quad * m[1][3]) + (t * m[2][3]) + (m[3][3]);

    int i1 = indices[0];
    int i2 = indices[1];
    int i3 = indices[2];
    int i4 = indices[3];


    Vertices* p1 = pontosT[i1];
    Vertices* p2 = pontosT[i2];
    Vertices* p3 = pontosT[i3];
    Vertices* p4 = pontosT[i4];

    resultado[0] = (aux[0]* p1->getX1()) + (aux[1]*p2->getX1()) + (aux[2]*p3->getX1()) + (aux[3]*p4->getX1());
    resultado[1] = (aux[0]* p1->getY1()) + (aux[1]*p2->getY1()) + (aux[2]*p3->getY1()) + (aux[3]*p4->getY1());
    resultado[2] = (aux[0]* p1->getZ1()) + (aux[1]*p2->getZ1()) + (aux[2]*p3->getZ1()) + (aux[3]*p4->getZ1());


}

void getGlobalCatmullRomPoint(float gt, float* resultado, std::vector<Vertices*> pontosT) {
    int tamanho = pontosT.size();
    int* ind = new int[4];
    int i = 0;
    float t;

    t = tamanho * gt;
    i = floor(t); // Serve para truncar
    t = t-i;

    ind[0] = (i+tamanho-1)%tamanho;
    ind[1] = (ind[0]+1)%tamanho;
    ind[2] = (ind[1]+1)%tamanho;
    ind[3] = (ind[2]+1)%tamanho;

    getCatmullRomPoint(t, ind, resultado, pontosT);

}





std::vector<Vertices*> criaCurva(std::vector<Vertices*> pontosT) {


    std::vector<Vertices*> resultado;






    return resultado;

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



