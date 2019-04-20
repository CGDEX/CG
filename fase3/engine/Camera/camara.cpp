#include "../engine.h"


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


void changeSize(int w, int h) {

    if (h == 0) h = 1;

    float ratio = w * 1.0f / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
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


