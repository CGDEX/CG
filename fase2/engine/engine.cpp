#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include "./parser.cpp"


float camX = 10, camY = 5, camZ = 10;
float translate_x, translate_y, translate_z;
float eixo_x, eixo_y, eixo_z;
int modo_desenho = GL_LINE;

Structure* structure = new Structure();
std::vector<Structure*> estrutura;




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







void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);



    std::vector<rotations*> roots = structure->getRotacoes();
    std::vector<scales*> escalas = structure->getEscalas();
    std::vector<vertices*> coords;
    std::vector<translations*> transl = structure->getTranslacoes();




    glColor3f(1,1,1);

    glPolygonMode(GL_FRONT_AND_BACK,modo_desenho);
    glBegin(GL_TRIANGLES);




    for(int j=0;j<estrutura.size();j++) {
        coords = estrutura[j]->getCoordenadas();

        for (int i=0;i<coords.size();i++) {
            glVertex3f(coords[i]->x,coords[i]->y,coords[i]->z);


        }
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

    else estrutura = lerXML(argv[1]);



    for(int j=0;j<estrutura.size();j++) {
        std::cout<<j<<std::endl;
    }



    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(tecladoSpecial);
    glutKeyboardFunc(letrasTeclado);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutMainLoop();

    return 1;
}
