/* 
* File:   Mesh.cpp
* Author: Luiz Felipe Machado da Silva
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <vector>

#include "VVector.h"
#include "Mesh.h"

//------------------------------------------------------------------------------

Mesh :: Mesh(void) {
    qtdVertices        = 0;
    qtdTriangulos      = 0;
    listaTriangulos    = NULL;
    listaVertices      = NULL;
    listaNormalFace    = NULL;
    listaNormalvertice = NULL;
}

//------------------------------------------------------------------------------

Mesh :: ~Mesh() {
    delete listaNormalFace;
    delete listaNormalvertice;
    delete listaTriangulos;
    delete listaVertices;
}

//------------------------------------------------------------------------------

bool Mesh :: loadGeometry(const char* filename) {
    FILE * pFile = fopen(filename, "rt");
    int num;
	if (pFile == NULL) {
		printf("Error - open file: %s\n\n", filename);
        delete listaVertices;
        delete listaTriangulos;
        delete listaNormalFace;
        delete listaNormalvertice;
        return false;
    }
    fscanf(pFile, "%d %d", &qtdVertices, &qtdTriangulos);
    listaVertices = new VVector[qtdVertices];
    listaTriangulos = new unsigned int[qtdTriangulos*3];
    listaNormalFace = new VVector[qtdTriangulos];
    listaNormalvertice = new VVector[qtdVertices];
    for(int i = 0; i < (int)qtdVertices; i++)
        fscanf(pFile, "%d %f %f %f", &num, &listaVertices[i].x, &listaVertices[i].y, &listaVertices[i].z);
    for(int i = 0; i < (int)(qtdTriangulos*3); i+=3)
        fscanf(pFile, "%d %d %d %d", &num, &listaTriangulos[i], &listaTriangulos[i+1], &listaTriangulos[i+2]);
    calculaNormal();
    return true;
}

//------------------------------------------------------------------------------

void Mesh :: calculaNormal(void) {
    VVector v0, v1;
    VVector p1, p2, p3;
	VVector normal;
	int qtd_cont = 0;
	for(int i = 0; i < (int)qtdVertices; i++) {
		listaNormalvertice[i].x = 0; listaNormalvertice[i].z = 0; listaNormalvertice[i].z = 0;
	}
	//printf("Calculando normal para cada face.\n");
	for(int i = 0, j = 0; i < (int)qtdTriangulos*3; i += 3, j++) {
        p1 = listaVertices[listaTriangulos[i]]; p2 = listaVertices[listaTriangulos[i+1]]; p3 = listaVertices[listaTriangulos[i+2]];
        v0.Set(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z); v1.Set(p2.x - p3.x, p2.y - p3.y, p2.z - p3.z);//Coloca na estrutura do vector.h//
        normal = Cross(v0, v1);
        normal.Normalize();
        listaNormalFace[j] = normal;
    }
    /*printf("Calculando normal para cada vertice.\n");
    for(int i = 0; i < (int)qtdVertices; i++) {
        for(int j = 0; j < (int)(qtdTriangulos*3); j++) {
            if(listaTriangulos[j] == i)
                listaNormalvertice[i] += listaNormalFace[j/3];
        }
        listaNormalvertice[i].Normalize();
    }*/
}

//------------------------------------------------------------------------------

void Mesh :: draw(void) {
	glBegin(GL_TRIANGLES);
	for(int i = 0, j = 0; i < qtdTriangulos*3; i++, j++)
	{
		glNormal3f(listaNormalFace[j].x, listaNormalFace[j].y, listaNormalFace[j].z);
		glVertex3f(listaVertices[listaTriangulos[i]].x, listaVertices[listaTriangulos[i]].y, listaVertices[listaTriangulos[i]].z); i++;
		glVertex3f(listaVertices[listaTriangulos[i]].x, listaVertices[listaTriangulos[i]].y, listaVertices[listaTriangulos[i]].z); i++;
		glVertex3f(listaVertices[listaTriangulos[i]].x, listaVertices[listaTriangulos[i]].y, listaVertices[listaTriangulos[i]].z);
	}
	glEnd();
}

//------------------------------------------------------------------------------