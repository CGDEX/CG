#include "../Estrutura/headers/estrutura.h"
#include "../Estrutura/headers/Forma.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>


// Função que cria um vector com as coordenadas de vários pontos para criar um plano
Forma* plano (float lado) {

    Forma* resultado = new Forma();
    Vertices* verts;

    float tamanho = lado/2;

//////////// COORDENADAS

    // TRIANGULO 1
    verts = new Vertices(-tamanho,0,-tamanho);
    resultado->insereVerts(verts);

    verts = new Vertices(-tamanho,0,tamanho);
    resultado->insereVerts(verts);

    verts = new Vertices(tamanho,0,-tamanho);
    resultado->insereVerts(verts);


    // TRIANGULO 2
    verts = new Vertices(-tamanho,0,-tamanho);
    resultado->insereVerts(verts);

    verts = new Vertices(tamanho,0,tamanho);
    resultado->insereVerts(verts);

    verts = new Vertices(tamanho,0,-tamanho);
    resultado->insereVerts(verts);

//////////// NORMAIS
    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);

    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);

    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);

    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);

    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);

    verts = new Vertices(0,1,0);
    resultado->insereNorms(verts);


//////////// TEXTURAS

    verts = new Vertices(1,1,0);
    resultado->insereTexts(verts);

    verts = new Vertices(1,0,0);
    resultado->insereTexts(verts);

    verts = new Vertices(0,1,0);
    resultado->insereTexts(verts);

    verts = new Vertices(0,1,0);
    resultado->insereTexts(verts);

    verts = new Vertices(1,0,0);
    resultado->insereTexts(verts);

    verts = new Vertices(0,0,0);
    resultado->insereTexts(verts);


    return resultado;
}

