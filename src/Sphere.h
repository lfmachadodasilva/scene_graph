/* 
 * File:   Sphere.h
 * Author: luizfelipe
 */

#ifndef _SPHERE_H
#define	_SPHERE_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
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
