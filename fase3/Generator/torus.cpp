#include "../Estrutura/estrutura.h"
#include <algorithm>
#include <vector>
#include <math.h>



std::vector<vertices> createTorus(float distance, float radius, int slices, int stacks) {
    std::vector<vertices> result;

    float theta = 0;
    float phi = 0;
    float desl1 = (2*M_PI)/slices;
    float desl2 = (2*M_PI)/stacks;



    vertices coordenadas1;
    vertices coordenadas2;
    vertices coordenadas3;
    vertices coordenadas4;
    vertices coordenadas5;
    vertices coordenadas6;




    for (int i=0;i< slices; i++) {
        for(int j=0; j<stacks; j++) {

            
            coordenadas1.x = cos(theta)*(distance + radius * cos(phi));
            coordenadas1.y= sin(theta)*(distance + radius * cos(phi));
            coordenadas1.z= radius*sin(phi);
            result.push_back(coordenadas1);



            coordenadas2.x = cos(theta + desl1)*(distance + radius * cos(phi));
            coordenadas2.y = sin(theta + desl1)*(distance + radius * cos(phi));
            coordenadas2.z = radius*sin(phi);
            result.push_back(coordenadas2);


            coordenadas3.x = cos(theta + desl1)*(distance + radius * cos(phi + desl2));
            coordenadas3.y = sin(theta+desl1)*(distance + radius * cos(phi+desl2));
            coordenadas3.z = radius*sin(phi+desl2);
            result.push_back(coordenadas3);


            coordenadas4.x = cos(theta + desl1)*(distance + radius * cos(phi + desl2));
            coordenadas4.y = sin(theta+desl1)*(distance + radius * cos(phi+desl2));
            coordenadas4.z = radius*sin(phi+desl2);
            result.push_back(coordenadas4);

            coordenadas5.x =  cos(theta)*(distance + radius * cos(phi + desl2));
            coordenadas5.y =  sin(theta)*(distance + radius * cos(phi + desl2));
            coordenadas5.z =  radius*sin(phi + desl2);
            result.push_back(coordenadas5);

            coordenadas6.x =  cos(theta)*(distance + radius * cos(phi));
            coordenadas6.y=   sin(theta)*(distance + radius * cos(phi));
            coordenadas6.z =  radius*sin(phi);
            result.push_back(coordenadas6);
            phi = desl2 * (j + 1);
        }
        theta = desl1 * (i + 1);
    }





    return result;
}
