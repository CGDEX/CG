#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include "../Estrutura/estrutura.h"
#include "tinyxml2.h"

std::vector<vertices> estrutura;

float camX = 10, camY = 5, camZ = 10;
float translate_x, translate_y, translate_z;
float eixo_x, eixo_y, eixo_z;
int modo_desenho = GL_LINE;





void changeSize(int w, int h) {

    if (h == 0) h = 1;

    float ratio = w * 1.0f / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}


void tecladoSpecial(int key_code, int x , int y){
    switch(key_code){
        case GLUT_KEY_UP:
            camY+=1;
            break;
        case GLUT_KEY_DOWN:
            camY-=1;
            break;
        case GLUT_KEY_LEFT:
            camX-=1;
            break;
        case GLUT_KEY_RIGHT:
            camX+=1;
            break;
    }
    glutPostRedisplay();
}

void letrasTeclado(unsigned char key, int x, int y){
    switch (key) {

        case 'a':
        case 'A':
            translate_x+=3;
            break;

        case 'd':
        case 'D':
            translate_x-=3;
            break;

        case 'w':
        case 'W':
            translate_z+=3;
            break;

        case 's':
        case 'S':
            translate_z-=3;
            break;

        case 'p':
        case 'P':
            modo_desenho = GL_POINT;
            break;

        case 'l':
        case 'L':
            modo_desenho = GL_LINE;
            break;

        case 'o':
        case 'O':
            modo_desenho = GL_FILL;
            break;

        case '-':
            gluLookAt(camX += 0.5, camY += 0.5, camZ += 0.5, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
            break;

        case '+':
            gluLookAt(camX -= 0.5, camY -= 0.5, camZ -= 0.5, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
            break;

    }

    glutPostRedisplay();
}




// Função que recebe um string que é o caminho e vai ler o ficheiro e a medida que vai lendo o ficheiro vai meter na estrutura as coordenadas
void lerFicheiro(std::string caminho) {

    std::ifstream ficheiro(caminho);
    std::string linha;

    if(ficheiro.fail()) {
        std::cout << "Bip bip! não consegui encontrar o ficheiro 3D!"<< std::endl;
    }
    else {
        while(getline(ficheiro,linha)) {
            vertices coordenadas;
            size_t pos;
            coordenadas.x = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            coordenadas.y = std::stof(linha,&pos);

            linha.erase(0,pos+1);
            coordenadas.z = std::stof(linha,&pos);

            estrutura.push_back(coordenadas);
        }
    }
}

// Função que recebe o caminho de um ficheiro XML e depois vai ler esse mesmo ficheiro utilizando o parser tinyxml2.
void lerXML(std::string caminho) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;

    if(!(doc.LoadFile(caminho.c_str()))) {

        elem = doc.FirstChildElement();

        for (elem = elem->FirstChildElement();elem;elem = elem->NextSiblingElement()){
            std::string caminho3D= "../Files3D/";
            caminho3D.append(elem->Attribute("file"));
            lerFicheiro(caminho3D);
        }
    }
    else {
        std::cout << "Bip bip! Erro xml! Não consegui encontrar o ficheiro :(" << std::endl;
    }
}



void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);


    glTranslatef(translate_x, translate_y, translate_z);
    glBegin(GL_LINES);

    // Eixo X
    glColor3f(1.0,0,0);
    glVertex3f(0,0,0);
    glVertex3f(5 + eixo_x,0,0);

    // Eixo Y
    glColor3f(0,1.0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,5 + eixo_y,0);

    // Eixo Z
    glColor3f(0,0,1.0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,5 + eixo_z);

    glEnd();

    glColor3f(1,1,1);
    glPolygonMode(GL_FRONT_AND_BACK,modo_desenho);
    glBegin(GL_TRIANGLES);
    for (int i=0;i<estrutura.size();i++) {
        glVertex3f(estrutura[i].x,estrutura[i].y,estrutura[i].z);
    }
    glEnd();

    glutSwapBuffers();

}


// Função main que vai receber o ficheiro XML e desenhar a figura.
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG-BOT's engine");

    if(argc < 2){
        std::cout << "Bip bip! Não recebi nenhuma directoria do ficheiro xml! " << std::endl;
        return 0;
    }

    else lerXML(argv[1]);

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(tecladoSpecial);
    glutKeyboardFunc(letrasTeclado);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutMainLoop();

    return 1;
}
