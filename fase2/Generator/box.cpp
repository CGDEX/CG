#include "../Estrutura/Vertices.h"
#include <algorithm>
#include <vector>

// Função que cria um vector com as coordenadas de vários pontos para criar um plano de frente e outra de trás.
std::vector<Vertices*> cria_plano_frente_tras(float largura, float altura, float comprimento, int camadas) {
    std::vector<Vertices*> resultado;
    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();

    float desl_y, desl_x;
    float x,y;

    x = largura/2;
    y = altura/2;


    if (camadas==0) {
        desl_x = largura;
        desl_y = altura;
        camadas = 1;
    }
    else {
        desl_y = altura/camadas;
        desl_x = largura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {

        for(j=0;j<camadas;j++) {
            coordenadas1->insereX(x+(j*desl_x));
            coordenadas1->insereY(-y+(i*desl_y));
            coordenadas1->insereZ(comprimento);
            resultado.push_back(coordenadas1);

            coordenadas2->insereX((-x+desl_x)+(j*desl_x));
            coordenadas2->insereY(-y+(i*desl_y));
            coordenadas2->insereZ(comprimento);
            resultado.push_back(coordenadas2);

            coordenadas3->insereX((-x+desl_x)+(j*desl_x));
            coordenadas3->insereY((-y+desl_y)+(i*desl_y));
            coordenadas3->insereZ(comprimento);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6->insereX(-x+(j*desl_x));
            coordenadas6->insereY((-y+desl_y)+(i*desl_y));
            coordenadas6->insereZ(comprimento);
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}
// Função que cria um vector com as coordenadas de vários pontos para criar um plano de cima e outra de baixo.
std::vector<Vertices*> cria_plano_cima_baixo(float largura, float altura, float comprimento, int camadas) {
    std::vector<Vertices*> resultado;
    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();

    float desl_z, desl_x;
    float x,z;

    x = largura/2;
    z = comprimento/2;


    if (camadas==0) {
        desl_x = largura;
        desl_z = comprimento;
        camadas = 1;
    }
    else {
        desl_z = comprimento/camadas;
        desl_x = largura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {
        for(j=0;j<camadas;j++) {

            coordenadas1->insereX(-x+(i*desl_x));
            coordenadas1->insereY(altura);
            coordenadas1->insereZ(-z+(j*desl_z));
            resultado.push_back(coordenadas1);

            coordenadas2->insereX(-x+(i*desl_x));
            coordenadas2->insereY(altura);
            coordenadas2->insereZ((-z+desl_z)+(j*desl_z));
            resultado.push_back(coordenadas2);

            coordenadas3->insereX((-x+desl_x)+(i*desl_x));
            coordenadas3->insereY(altura);
            coordenadas3->insereZ((-z+desl_z)+(j*desl_z));
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6->insereX((-x+desl_x)+(i*desl_x));
            coordenadas6->insereY(altura);
            coordenadas6->insereZ(-z+(j*desl_z));
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}


// Função que cria um vector com as coordenadas de vários pontos para criar um plano de esquerda e outra de direita.
std::vector<Vertices*> cria_plano_esquerda_direita(float largura, float altura, float comprimento, int camadas) {
    std::vector<Vertices*> resultado;
    Vertices* coordenadas1 = new Vertices();
    Vertices* coordenadas2 = new Vertices();
    Vertices* coordenadas3 = new Vertices();
    Vertices* coordenadas4 = new Vertices();
    Vertices* coordenadas5 = new Vertices();
    Vertices* coordenadas6 = new Vertices();

    float desl_z, desl_y;
    float y,z;

    y = altura/2;
    z = comprimento/2;


    if (camadas==0) {
        desl_y = largura;
        desl_z = comprimento;
        camadas = 1;
    }
    else {
        desl_z = comprimento/camadas;
        desl_y = altura/camadas;
    }

    int i,j;
    for (i=0;i<camadas;i++) {
        for(j=0;j<camadas;j++) {

            coordenadas1->insereX(largura);
            coordenadas1->insereY(-y+(i*desl_y));
            coordenadas1->insereZ((-z+desl_z)+(j*desl_z));
            resultado.push_back(coordenadas1);

            coordenadas2->insereX(largura);
            coordenadas2->insereY(-y+(i*desl_y));
            coordenadas2->insereZ(-z+(j*desl_z));
            resultado.push_back(coordenadas2);

            coordenadas3->insereX(largura);
            coordenadas3->insereY((-y+desl_y)+(i*desl_y));
            coordenadas3->insereZ(-z+(j*desl_z));
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6->insereX(largura);
            coordenadas6->insereY((-y+desl_y)+(i*desl_y));
            coordenadas6->insereZ((-z+desl_z)+(j*desl_z));
            resultado.push_back(coordenadas6);

        }
    }

    return resultado;

}


// Função que cria um vector com as coordenadas de vários pontos para criar uma caixa
std::vector<Vertices*> box(float largura, float altura, float comprimento, int camadas) {
    // Face da frente
    std::vector<Vertices*> resultado1 = cria_plano_frente_tras(largura,altura,(comprimento/2),camadas);

    //face de trás
    std::vector<Vertices*> resultado2 = cria_plano_frente_tras(largura,altura,(-comprimento/2),camadas);
    std::reverse(resultado2.begin(),resultado2.end());

    // Face de cima
    std::vector<Vertices*> resultado3 = cria_plano_cima_baixo(largura,(altura/2),comprimento,camadas);

    // Face de baixo
    std::vector<Vertices*> resultado4 = cria_plano_cima_baixo(largura,(-altura/2),comprimento,camadas);
    std::reverse(resultado4.begin(),resultado4.end());

    //Face de direita
    std::vector<Vertices*> resultado5 = cria_plano_esquerda_direita((largura/2),altura,comprimento,camadas);

    //Face da esquerda
    std::vector<Vertices*> resultado6 = cria_plano_esquerda_direita((-largura/2),altura,comprimento,camadas);
    std::reverse(resultado6.begin(),resultado6.end());


    std::vector<Vertices*> resultadoFinal (resultado1.size()+resultado2.size()+resultado3.size()+resultado4.size()+resultado5.size()+resultado6.size());
    resultadoFinal.insert(resultadoFinal.end(),resultado1.begin(),resultado1.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado2.begin(),resultado2.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado3.begin(),resultado3.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado4.begin(),resultado4.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado5.begin(),resultado5.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado6.begin(),resultado6.end());


    return resultadoFinal;
}
