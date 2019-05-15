#include "../Estrutura/headers/estrutura.h"
#include <algorithm>
#include <vector>

// Função que cria um vector com as coordenadas de vários pontos para criar um plano de frente e outra de trás.
std::vector<vertices> cria_plano_frente_tras(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

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
            coordenadas1.x = -x+(j*desl_x);
            coordenadas1.y = -y+(i*desl_y);
            coordenadas1.z = comprimento;
            resultado.push_back(coordenadas1);

            coordenadas2.x = (-x+desl_x)+(j*desl_x);
            coordenadas2.y = -y+(i*desl_y);
            coordenadas2.z = comprimento;
            resultado.push_back(coordenadas2);

            coordenadas3.x = (-x+desl_x)+(j*desl_x);
            coordenadas3.y = (-y+desl_y)+(i*desl_y);
            coordenadas3.z = comprimento;
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = -x+(j*desl_x);
            coordenadas6.y = (-y+desl_y)+(i*desl_y);
            coordenadas6.z = comprimento;
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}
// Função que cria um vector com as coordenadas de vários pontos para criar um plano de cima e outra de baixo.
std::vector<vertices> cria_plano_cima_baixo(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

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

            coordenadas1.x = -x+(i*desl_x);
            coordenadas1.y = altura;
            coordenadas1.z = -z+(j*desl_z);
            resultado.push_back(coordenadas1);

            coordenadas2.x = -x+(i*desl_x);
            coordenadas2.y = altura;
            coordenadas2.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas2);

            coordenadas3.x = (-x+desl_x)+(i*desl_x);
            coordenadas3.y = altura;
            coordenadas3.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = (-x+desl_x)+(i*desl_x);
            coordenadas6.y = altura;
            coordenadas6.z = -z+(j*desl_z);
            resultado.push_back(coordenadas6);
        }
    }

    return resultado;

}


// Função que cria um vector com as coordenadas de vários pontos para criar um plano de esquerda e outra de direita.
std::vector<vertices> cria_plano_esquerda_direita(float largura, float altura, float comprimento, int camadas) {
    std::vector<vertices> resultado;
    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;

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

            coordenadas1.x = largura;
            coordenadas1.y = -y+(i*desl_y);
            coordenadas1.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas1);

            coordenadas2.x = largura;
            coordenadas2.y = -y+(i*desl_y);
            coordenadas2.z = -z+(j*desl_z);
            resultado.push_back(coordenadas2);

            coordenadas3.x = largura;
            coordenadas3.y = (-y+desl_y)+(i*desl_y);
            coordenadas3.z = -z+(j*desl_z);
            resultado.push_back(coordenadas3);

            coordenadas4 = coordenadas1;
            resultado.push_back(coordenadas4);

            coordenadas5 = coordenadas3;
            resultado.push_back(coordenadas5);

            coordenadas6.x = largura;
            coordenadas6.y = (-y+desl_y)+(i*desl_y);
            coordenadas6.z = (-z+desl_z)+(j*desl_z);
            resultado.push_back(coordenadas6);

        }
    }

    return resultado;

}


// Função que cria um vector com as coordenadas de vários pontos para criar uma caixa
std::vector<vertices> box(float largura, float altura, float comprimento, int camadas) {
    // Face da frente
    std::vector<vertices> resultado1 = cria_plano_frente_tras(largura,altura,(comprimento/2),camadas);

    //face de trás
    std::vector<vertices> resultado2 = cria_plano_frente_tras(largura,altura,(-comprimento/2),camadas);
    std::reverse(resultado2.begin(),resultado2.end());

    // Face de cima
    std::vector<vertices> resultado3 = cria_plano_cima_baixo(largura,(altura/2),comprimento,camadas);

    // Face de baixo
    std::vector<vertices> resultado4 = cria_plano_cima_baixo(largura,(-altura/2),comprimento,camadas);
    std::reverse(resultado4.begin(),resultado4.end());

    //Face de direita
    std::vector<vertices> resultado5 = cria_plano_esquerda_direita((largura/2),altura,comprimento,camadas);

    //Face da esquerda
    std::vector<vertices> resultado6 = cria_plano_esquerda_direita((-largura/2),altura,comprimento,camadas);
    std::reverse(resultado6.begin(),resultado6.end());


    std::vector<vertices> resultadoFinal (resultado1.size()+resultado2.size()+resultado3.size()+resultado4.size()+resultado5.size()+resultado6.size());
    resultadoFinal.insert(resultadoFinal.end(),resultado1.begin(),resultado1.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado2.begin(),resultado2.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado3.begin(),resultado3.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado4.begin(),resultado4.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado5.begin(),resultado5.end());
    resultadoFinal.insert(resultadoFinal.end(),resultado6.begin(),resultado6.end());


    return resultadoFinal;
}