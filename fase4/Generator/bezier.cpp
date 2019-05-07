#include "../Estrutura/headers/estrutura.h"
#include <algorithm>
#include <vector>


float* formula (float t, float* p1, float* p2, float* p3, float* p4) {

    float aux = 1.0 - t;
    float *result = new float[3];

    float ponto1 = aux*aux*aux;
    float ponto2 = 3*(aux*aux)*t;
    float ponto3 = 3*aux*(t*t);
    float ponto4 = t*t*t;

    result[0] = (ponto1 * p1[0]) + (ponto2 * p2[0]) + (ponto3 * p3[0]) + (ponto4 * p4[0]);
    result[1] = (ponto1 * p1[1]) + (ponto2 * p2[1]) + (ponto3 * p3[1]) + (ponto4 * p4[1]);
    result[2] = (ponto1 * p1[2]) + (ponto2 * p2[2]) + (ponto3 * p3[2]) + (ponto4 * p4[2]);



    return result;
}


float* bezier(float a, float b,float** pontos, int* indice) {

    float* ponto = new float[3];
    float  alt[4][3];
    float  res[4][3];

    int i,j,x;
    i=j=x=0;
    float *resultado;

    for(i=0; i<16; i++) {
        alt[j][0] = pontos[indice[i]][0];
        alt[j][1] = pontos[indice[i]][1];
        alt[j][2] = pontos[indice[i]][2];
        j++;

        if(j%4==0) {
            ponto = formula(a,alt[0],alt[1],alt[2],alt[3]);
            res[x][0] = ponto[0];
            res[x][1] = ponto[1];
            res[x][2] = ponto[2];
            x++;
            j=0;
        }
    }


    resultado = formula(b,res[0],res[1],res[2],res[3]);

    return resultado;
}


void patch (std::string file, int tess) {

    std::ofstream bezierFile("../Examples/bezier.3d");
    std::ifstream read(file);
    std::string linha, aux;

    int posicao;
    int i1, i2, i3;
    int j1, j2;


    float inc = 1.0/tess;

    if (read.is_open()) {
        getline(read,linha);
        int numeroPatch = atoi(linha.c_str());

        int** indices = new int*[numeroPatch];
        std::cout << "Numero patch: " << numeroPatch << std::endl;
        float*** pontosResult = new float**[numeroPatch];

        for(i1=0;i1<numeroPatch;i1++) {
            getline(read,linha);
            indices[i1] = new int[16];


            for(j1=0;j1<16;j1++) {
                posicao = linha.find(",");
                aux = linha.substr(0,posicao);
                indices[i1][j1] = atoi(aux.c_str());
                std::cout<< "Indices: " << indices[i1][j1] << std::endl;
                linha.erase(0,posicao+1);
            }
        }



        getline(read,linha);
        int controlPontos = atoi(linha.c_str());
        float** pontos = new float*[controlPontos];


        for(i2=0;i2<controlPontos;i2++) {
            getline(read,linha);
            pontos[i2] = new float[3];


            for(j2=0;j2<3;j2++) {
                posicao = linha.find(",");
                aux = linha.substr(0,posicao);
                pontos[i2][j2] = atof(aux.c_str());
                linha.erase(0,posicao+1);
            }
        }

        for(i3=0;i3<numeroPatch;i3++) {
            pontosResult[i3] = new float*[4];

            for(int x=0;x<tess;x++) {
                for(int y=0;y<tess;y++) {

                    float x1 = inc * x;
                    float x2 = inc * (x+1);
                    float y1 = inc * y;
                    float y2 = inc * (y+1);

                    pontosResult[i3][0] = bezier(x1,y1,pontos,indices[i3]);
                    pontosResult[i3][1] = bezier(x1,y2,pontos,indices[i3]);
                    pontosResult[i3][2] = bezier(x2,y1,pontos,indices[i3]);
                    pontosResult[i3][3] = bezier(x2,y2,pontos,indices[i3]);



                    bezierFile << pontosResult[i3][0][0] << ","<< pontosResult[i3][0][1] << ","<< pontosResult[i3][0][2] << std::endl;
                    bezierFile << pontosResult[i3][2][0] << ","<< pontosResult[i3][2][1] << ","<< pontosResult[i3][2][2] << std::endl;
                    bezierFile << pontosResult[i3][3][0] << ","<< pontosResult[i3][3][1] << ","<< pontosResult[i3][3][2] << std::endl;

                    bezierFile << pontosResult[i3][0][0] << ","<< pontosResult[i3][0][1] << ","<< pontosResult[i3][0][2] << std::endl;
                    bezierFile << pontosResult[i3][3][0] << ","<< pontosResult[i3][3][1] << ","<< pontosResult[i3][3][2] << std::endl;
                    bezierFile << pontosResult[i3][1][0] << ","<< pontosResult[i3][1][1] << ","<< pontosResult[i3][1][2] << std::endl;

                }
            }
        }
        bezierFile.close();
        read.close();

    }
    else {
        std::cout << "Ficheiro invalido" << std::endl;
    }

}