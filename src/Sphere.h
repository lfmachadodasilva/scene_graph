/* 
 * File:   Sphere.h
 * Author: luizfelipe
 */

#ifndef _SPHERE_H
#define	_SPHERE_H

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef WIN32
#include <Windows.h>    /* includes only in MSWindows not in UNIX */
#include <gl/gl.h>     /* OpenGL functions*/
#include <gl/glu.h>    /* OpenGL utilitary functions*/
#include <gl/glut.h>    /* OpenGL utilitary functions*/
#else
#include <GL/gl.h>     /* OpenGL functions*/
#include <GL/glu.h>    /* OpenGL utilitary functions*/
#include <GL/glut.h>    /* OpenGL utilitary functions*/
#endif

#include "Shape.h"

class Sphere : public Shape {
protected:
    float angulo;
public:
    void setRadius(float angulo) {
        this->angulo = angulo;
    }

    void draw(void) {
		glutSolidSphere(angulo, 30, 30);
    }
};
#endif
