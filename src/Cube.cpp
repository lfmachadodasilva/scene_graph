/*
 * File:   Cube.cpp
 * Author: luizfelipe
 *
 * Created on April 29, 2009, 10:32 PM
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "Cube.h"

//------------------------------------------------------------------------------

void Cube :: draw(void) {
    glBegin(GL_QUADS);//Face de baixo
    {
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(size.x, 0.0f, 0.0f);
        glVertex3f(size.x, 0.0f, size.z);
        glVertex3f(0.0f, 0.0f, size.z);
    }
    glEnd();

    glBegin(GL_QUADS);//Face de cima
    {
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, size.y, 0.0f);
        glVertex3f(0.0f, size.y, size.z);
        glVertex3f(size.x, size.y, size.z);
        glVertex3f(size.x, size.y, 0.0f);
    }
    glEnd();

    glBegin(GL_QUADS);//Face lateral esquerda
    {
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, size.z);
        glVertex3f(0.0f, size.y, size.z);
        glVertex3f(0.0f, size.y, 0.0f);
    }
    glEnd();

    glBegin(GL_QUADS);//Face lateral direita
    {
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(size.x, 0.0f, 0.0f);
        glVertex3f(size.x, size.y, 0.0f);
        glVertex3f(size.x, size.y, size.z);
        glVertex3f(size.x, 0.0f, size.z);
    }
    glEnd();

    glBegin(GL_QUADS);//Face front
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(size.x, size.y, size.z);
        glVertex3f(0.0f, size.y, size.z);
        glVertex3f(0.0f, 0.0f, size.z);
        glVertex3f(size.x, 0.0f, size.z);
    }
    glEnd();

    glBegin(GL_QUADS);//Face back
    {
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, size.y, 0.0f);
        glVertex3f(size.x, size.y, 0.0f);
        glVertex3f(size.x, 0.0f, 0.0f); 
    }
    glEnd();
}

//------------------------------------------------------------------------------


