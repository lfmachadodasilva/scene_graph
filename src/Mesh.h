/* 
 * File:   Mesh.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _MESH_H_
#define _MESH_H_

#include "Shape.h"

class Mesh : public Shape {
protected:
	unsigned int qtdVertices;//Quantidade de vertices//
    unsigned int qtdTriangulos;//Quantidade de triangulos//
    VVector * listaVertices;//Lista de vertices//
    unsigned int * listaTriangulos;//Lista de triangulos//
    VVector * listaNormalFace;//Lista de normais de cada triangulo//
    VVector * listaNormalvertice;//Lista de normais de cada vertice//
    void calculaNormal(void);//Calcula normais//
public:
    Mesh(void);
    ~Mesh(void);
    bool loadGeometry(const char* filename);
    void draw(void);
};
#endif