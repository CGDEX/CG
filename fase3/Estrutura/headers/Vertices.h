
#ifndef GENERATOR_VERTICES_H
#define GENERATOR_VERTICES_H


class Vertices {
    float vertice_x;
    float vertice_y;
    float vertice_z;


public:
    Vertices();
    Vertices(float x, float y, float z);
    float getX1();
    float getY1();
    float getZ1();
    void insereX1(float xx);
    void insereY1(float yy);
    void insereZ1(float zz);

};



#endif //GENERATOR_VERTICES_H
