#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "./parser.cpp"
#include <GL/glew.h>
#include <GL/glut.h>

std::vector<Group*> groups;

int centerX, centerY;
int window;

float pos_x = 30;
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

int frame = 0;
int tempo2 = 0;

int modo_desenho = GL_LINE;



void lerXML(std::string caminho);

void changeSize(int w, int h) {

    if (h == 0) h = 1;

    float ratio = w * 1.0f / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
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


        case 'e':
        case 'E':
            if(!fps_cam) {
                mexe_direita= true;
                break;
            }
            else break;

        case 'q':
        case 'Q':
            if(!fps_cam) {
                mexe_esquerda = true;
                break;
            }
            else break;



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
            speed -= 0.5;
            break;

        case '+':
            speed += 0.5;
            if (speed<0) speed=0;
            break;

        case 27:
            glutDestroyWindow(window);
            exit(0);

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
            mexe_esquerda= false;

            break;

        case 'e':
            mexe_direita = false;

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
    centerY = 0 ;


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

void fps() {
    float sec;
    int tempo;
    char titulo[64];

    frame++;
    tempo = glutGet(GLUT_ELAPSED_TIME);

    if (tempo - tempo2 > 1000) {
        sec = frame*1000.0 / (tempo - tempo2);
        tempo2 = tempo;
        frame = 0;
        sprintf(titulo,"Engine  |  %.2f FPS",sec);
        glutSetWindowTitle(titulo);
    }
}

void renderCurva(std::vector<Vertices*> curva) {
    float ponts[3];
    int i;


    glBegin(GL_LINE_LOOP);
    for(i=0;i<curva.size();i++) {
        ponts[0] = curva[i]->getX1();
        ponts[1] = curva[i]->getY1();
        ponts[2] = curva[i]->getZ1();
        glVertex3fv(ponts);
    }
    glEnd();
}


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camera();
    glPolygonMode(GL_FRONT_AND_BACK,modo_desenho);
    int i,j;
    float resultado[3];


    for(i=0;i<groups.size();i++) {
        glPushMatrix();
        Rotacao* rotacao = groups[i]->getTransformacoes()->getRotacao();
        Escala* escala = groups[i]->getTransformacoes()->getEscala();
        Cor* cor = groups[i]->getTransformacoes()->getCor();
        Translacao* transl = groups[i]->getTransformacoes()->getTranslacao();
        Group* grupo = groups[i];



        if(transl->getTempo()!=0 && transl->getPontos().size()!=0) {
            float t1 = glutGet(GLUT_ELAPSED_TIME) % (int) (transl->getTempo()*1000);
            float t2 = t1 / (transl->getTempo()*1000);
            std::vector<Vertices*> pontos = transl->getPontos();
            transl->curva();
            renderCurva(transl->getCurva());
            transl->getGlobalCatmullRomPoint(t2,resultado,pontos);
            glTranslatef(resultado[0],resultado[1],resultado[2]);
        }

        if(rotacao->getTempo()!=0 && rotacao->getXR()!=0 && rotacao->getYR()!=0 && rotacao->getZR()!=0) {
            float r1 = glutGet(GLUT_ELAPSED_TIME) % (int) (transl->getTempo()*1000);
            float r2 = (r1*360) / (transl->getTempo()*1000);
            glRotatef(r2,rotacao->getXR(),rotacao->getYR(),rotacao->getZR());
        }

        // 1º verifica se os pontos são diferentes de 0, se forem então aplica a funçção scalef, senão passa a frente.
        if(escala->getXE()!=0 && escala->getYE()!=0 && escala->getZE()!=0) {
            glScalef(escala->getXE(),escala->getYE(),escala->getZE());
        }

        if(cor->getR1()!=0 && cor->getG1()!=0 && cor->getB1()!=0) {
            glColor3f(cor->getR1(),cor->getG1(),cor->getB1());
        }


// Parte dos filhos
        if(groups[i]->getFilhos().size()!=0) {
            std::vector<Group*> aux = groups[i]->getFilhos();

            for(j=0;j<aux.size();j++) {
                glPushMatrix();
                Translacao* translacao = aux[j]->getTransformacoes()->getTranslacao();
                if (!translacao->vazioT()) {
                    float t3 = glutGet(GLUT_ELAPSED_TIME) % (int) (translacao->getTempo()*1000);
                    float t4 = t3 / (translacao->getTempo()*1000);
                    std::vector<Vertices*> vertices = translacao->getPontos();
                    translacao->curva();
                    renderCurva(translacao->getCurva());
                    translacao->getGlobalCatmullRomPoint(t4,resultado,vertices);
                    glTranslatef(resultado[0],resultado[1],resultado[2]);
                }

                Rotacao* rot = aux[j]->getTransformacoes()->getRotacao();
                if(!rot->vazioR()) {
                    float r3 = glutGet(GLUT_ELAPSED_TIME) % (int) (rot->getTempo()*1000);
                    float r4 = (r3*360) / (rot->getTempo()*1000);
                    glRotatef(r4,rot->getXR(),rot->getYR(),rot->getZR());
                }

                Escala* scale = aux[j]->getTransformacoes()->getEscala();
                if(!scale->vazioE()) {
                    glScalef(scale->getXE(),scale->getYE(),scale->getZE());
                }

                aux[j]->desenha();
                glPopMatrix();
            }
        }

        if(cor->getR1()!=0 && cor->getG1()!=0 && cor->getB1()!=0) {
            glColor3f(cor->getR1(),cor->getG1(),cor->getB1());
        }
        grupo->desenha();
        glPopMatrix();


    }

    fps();
    glutSwapBuffers();

}

void setVBO() {
    glPolygonMode(GL_FRONT,modo_desenho);

    for (size_t i = 0; i<groups.size();i++) {


        groups[i]->VBO();

        if(groups[i]->getFilhos().size()>0) {
            std::vector<Group*> sub = groups[i]->getFilhos();

            for(size_t j=0; j<sub.size();j++) {
                sub[j]->VBO();
            }
            groups[i]->setFilho(sub);
        }
    }
}

// Função main que vai receber o ficheiro XML e desenhar a figura.
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1080,720);
    window = glutCreateWindow("CG-BOT's engine");
    glewInit();

    if(argc < 2){
        std::cout << "Bip bip! Não recebi nenhuma directoria do ficheiro xml! " << std::endl;
        return 0;
    }

    else lerXML(argv[1]);



    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glutKeyboardFunc(letrasTeclado);
    glutKeyboardUpFunc(letrasTecladoRelease);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);
    setVBO();
    glutMainLoop();

    return 1;
}




void parserElementos(tinyxml2::XMLElement* elemento,Transformacao* transf, std::string identif) {

    std::cout << "IDENTI: " << identif << std::endl;

    Transformacao* transform = new Transformacao();
    Translacao* translacao = new Translacao();
    Rotacao* rotacao = new Rotacao();
    Escala* escala = new Escala();
    Cor* cor = new Cor();

    if((strcmp(elemento->FirstChildElement()->Value(),"group"))==0) {
        std::cout << " IF GRUPO " << std::endl;
        elemento = elemento->FirstChildElement();
    }

    for( tinyxml2::XMLElement* atual=elemento->FirstChildElement(); (strcmp(atual->Value(),"models"))!=0; atual = atual->NextSiblingElement()) {
        std::cout << atual->Name() << std::endl;

        if((strcmp(atual->Value(),"translate"))==0) {
            std::cout << " IF TRANSLATE " << std::endl;
            translacao = parserTranslate(atual);
            achouT=1;
        }

        if((strcmp(atual->Value(),"scale"))==0) {
            std::cout << " IF SCALE" << std::endl;
            escala = parserScale(atual);
            achouS=1;
        }

        if((strcmp(atual->Value(),"rotate"))==0) {
            std::cout << " IF ROTATE" << std::endl;
            rotacao = parserRotation(atual);
            achouR=1;
        }


        if((strcmp(atual->Value(),"color"))==0) {
            std::cout << " IF COLOR" << std::endl;
            cor = parserColor(atual);
            achouC=1;
        }
    }

    std::cout << " IFS PARA INSERIR" << std::endl;
    if(achouS==1) transform->insereEscala(escala);
    else {
        escala->insereXE(1);escala->insereYE(1);escala->insereZE(1);
        transform->insereEscala(escala);
    }
    if(achouC==1) transform->insereCor(cor);
    else {
        cor->insereR1(1);cor->insereG1(1);cor->insereB1(1);
        transform->insereCor(cor);
    }
    if(achouR==1) transform->insereRotacao(rotacao);
    else {
        rotacao->insereAngulo(0);rotacao->insereX(0);rotacao->insereY(0);rotacao->insereZ(0);
        transform->insereRotacao(rotacao);
    }
    if(achouT==1) transform->insereTranslacao(translacao);
    else {
        Translacao* transl = new Translacao();
        transform->insereTranslacao(transl);

    }
    std::cout << " IF DEPOIS DE INSERIR" << std::endl;
    achouT=achouS=achouR=achouC=0;




    for(tinyxml2::XMLElement* modelo=elemento->FirstChildElement("models")->FirstChildElement("model");modelo;modelo=modelo->NextSiblingElement("model")) {
        std::cout << " 2º FOR MODEL" << std::endl;
        Group* grupo = new Group();
        grupo->insereNome(modelo->Attribute("file"));

        std::vector<Vertices*> verts;
        std::string caminho3D= "../Files3D/";
        caminho3D.append(grupo->getNome());

        verts = lerFicheiro(caminho3D);


        grupo->insereVerts(verts);
        grupo->insereN(0);
        grupo->insereTransformacoes(transform);



        if(identif=="filho") {
            int pos = groups.size() - 1;
            std::cout << " FILHO " << std::endl;
            groups[pos]->insereFilho(grupo);
        }
        else if(identif=="pai") {
            int pos = groups.size() -1;
            groups[pos]->insereFilho(grupo);
        }
        else {
            std::cout << "ULTIMO ELSE " << std::endl;
            groups.push_back(grupo);
        }


    }


    if (elemento->FirstChildElement("group")) {
        std::cout << "CASO 2" << std::endl;
        parserElementos(elemento->FirstChildElement("group"),transform,"filho");
    }


    if ( (identif=="filho" || identif=="pai") && (elemento->NextSiblingElement("group"))) {
        std::cout << "CASO 1" << std::endl;
        parserElementos(elemento->NextSiblingElement("group"),transf,"pai");
    }


    if ((identif!="filho" && identif!="pai") && (elemento->NextSiblingElement("group"))) {
        std::cout << "CASO 3" << std::endl;
        parserElementos(elemento->NextSiblingElement("group"),transf,"irmao");
    }


}


// Função que recebe o caminho de um ficheiro XML e depois vai ler esse mesmo ficheiro utilizando o parser tinyxml2.
void lerXML(std::string caminho) {

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *elem;


    if(!(doc.LoadFile(caminho.c_str()))) {
        elem = doc.FirstChildElement("scene")->FirstChildElement("group");
        Transformacao* transform = new Transformacao();
        Escala* esc = new Escala(1,1,1);
        transform->insereEscala(esc);
        std::cout << " Chegou ao if carregar ficheiro " << std::endl;
        parserElementos(elem,transform,"irmao");

    }

    else {
        std::cout << "Bip bip! Erro xml! Não consegui encontrar o ficheiro :(" << std::endl;
    }


}
