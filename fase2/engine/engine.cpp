#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include "./parser.cpp"


int centerX, centerY;

float pos_x = 10;
float pos_y = 5;
float pos_z = 10;

float dir_x = 0;
float dir_y = 0;
float dir_z = 0;

float h_angle;
float v_angle;
float speed = 0.2;

bool frente = false;
bool tras = false;
bool esquerda = false;
bool direita = false;
bool mexe_esquerda = false;
bool mexe_direita = false;

bool fps_cam = false;

float camX = 10, camY = 5, camZ = 10;


int modo_desenho = GL_LINE;

Structure* structure = new Structure();





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
            esquerda = true;
            break;

        case 'd':
        case 'D':
            direita = true;
            break;

        case 'w':
        case 'W':
            frente = true;
            break;

        case 's':
        case 'S':
            tras = true;
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

        case 'f':
        case 'F':
            glutFullScreen();
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


void letrasTecladoRelease(unsigned char key, int x, int y){
    switch (key) {

        case 'w':
            frente = false;
            break;

        case 's':
            tras = false;
            break;

        case 'a':
            esquerda = false;

            break;

        case 'd':
            direita = false;

            break;

        case 'q':
            esquerda = false;

            break;

        case 'e':
            direita = false;

            break;
    }
}

void move_frente_f() {
    pos_x += dir_x * speed;
    pos_y += dir_y * speed;
    pos_z += dir_z * speed;
}

void move_tras_f() {
    pos_x -= dir_x * speed;
    pos_y -= dir_y * speed;
    pos_z -= dir_z * speed;
}

void move_left_f() {
    pos_x += dir_z * speed;
    pos_z -= dir_x * speed;
}

void move_right_f() {
    pos_x -= dir_z * speed;
    pos_z += dir_x * speed;
}

/* ************ */
/* TRD CAM CALC*/
/* ************ */

void move_frente_t() {
    float xrot, yrot;
    yrot = (v_angle / 180.0f * M_PI);
    xrot = (h_angle / 180.0f * M_PI);
    pos_x += (sin(yrot))*speed;
    pos_z -= (cos(yrot))*speed;
    pos_y -= (sin(xrot))*speed;
}

void move_tras_t() {
    float xrot, yrot;
    yrot = (v_angle / 180.0f * M_PI);
    xrot = (h_angle / 180.0f * M_PI);
    pos_x -= (sin(yrot))*speed;
    pos_z += (cos(yrot))*speed;
    pos_y += (sin(xrot))*speed;
}

void move_left_t() {
    float yrot;
    yrot = (v_angle / 180.0f * M_PI);
    pos_x -= (cos(yrot)) * speed;
    pos_z -= (sin(yrot)) * speed;
}

void move_right_t() {
    float yrot;
    yrot = (v_angle / 180.0f * M_PI);
    pos_x += (cos(yrot)) * speed;
    pos_z += (sin(yrot)) * speed;
}

void turnLeft() {
    v_angle -= 1;
    if (v_angle < 360) v_angle += 360;
}

void turnRight() {
    v_angle += 1;
    if (v_angle > 360) v_angle -= 360;
}

void camera() {
    centerX = 0;
    centerY = 0;


    if (fps_cam) {
        if (frente) move_frente_f();
        if (tras) move_tras_f();
        if (esquerda) move_left_f();
        if (direita) move_right_f();
        if (mexe_esquerda) turnLeft();
        if (mexe_direita) turnRight();

        gluLookAt(pos_x, pos_y, pos_z,
                  pos_x + dir_x, pos_y + dir_y, pos_z + dir_z,
                  0.0f, 1.0f, 0.0f);
    }

    else {
        if (frente) move_frente_t();
        if (tras) move_tras_t();
        if (esquerda) move_left_t();
        if (direita) move_right_t();
        if (mexe_esquerda) turnLeft();
        if (mexe_direita) turnRight();

        glTranslatef(0, centerY / 1000 - 0.7, -centerX / 225);

        glRotatef(h_angle, 1, 0, 0);
        glRotatef(v_angle, 0, 1, 0);
        glTranslatef(-pos_x, -pos_y, -pos_z);
    }
}



void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camera();




    glColor3f(1,1,1);



    glPolygonMode(GL_FRONT_AND_BACK,modo_desenho);


    for (Structure* test : structure->getNext()) {
        std::vector<Transformacoes*> transf = test->getTransforms();
        for(int k=0;k<transf.size();k++) {
            std :: cout << k << std::endl;
            std::cout << transf[k]->getX() << std::endl;
            transf[k]->aplicaEfeito2();
        }
        glBegin(GL_TRIANGLES);
        for (int k=0;k<test->getCoords().size();k++) {

            glVertex3f(test->getCoords()[k]->x,test->getCoords()[k]->y,test->getCoords()[k]->z);

        }
        glEnd();
    }






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

    else lerXML(argv[1],structure);




    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

    glutKeyboardFunc(letrasTeclado);
    glutKeyboardUpFunc(letrasTecladoRelease);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutMainLoop();

    return 1;
}
