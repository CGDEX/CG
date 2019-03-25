
#ifndef GENERATOR_VERTICES_H
#define GENERATOR_VERTICES_H


class Vertices {
    float x;
    float y;
    float z;


public:
    Vertices();
    Vertices(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void insereX(float xx);
    void insereY(float yy);
    void insereZ(float zz);

};



#endif //GENERATOR_VERTICES_H
