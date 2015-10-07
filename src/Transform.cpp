/* 
 * File:   Transform.cpp
 * Author: Luiz Felipe Machado da Silva
 */
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef WIN32
#include <Windows.h>    /* includes only in MSWindows not in UNIX */
#include <gl/gl.h>     /* OpenGL functions*/
#include <gl/glu.h>    /* OpenGL utilitary functions*/
//#include <gl/glut.h>    /* OpenGL utilitary functions*/
#else
#include <GL/gl.h>     /* OpenGL functions*/
#include <GL/glu.h>    /* OpenGL utilitary functions*/
//#include <GL/glut.h>    /* OpenGL utilitary functions*/
#endif

#include "Transform.h"

//-----------------------------------------------------------------------------------------------------------

Transform :: Transform(void) {
	glPushAttrib(GL_TRANSFORM_BIT);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, this->matrixTransf);
	for(int i = 0; i < 16; ++i)
		this->matrixTransfI[i] = this->matrixTransf[i];
	glPopMatrix();
	glPopAttrib();
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: translate(float x, float y, float z) {
	glPushMatrix();
	glLoadMatrixf(matrixTransf);
	glTranslatef(x, y, z);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransf);
	glLoadIdentity();
	/*glTranslatef(-x, -y, -z);
	glMultMatrixf(matrixTransfI);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransfI);*/
	glPopMatrix();
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: rotate(float angle, float x, float y, float z) {
	glPushMatrix();
	glLoadMatrixf(matrixTransf);
	glRotatef(angle, x, y, z);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransf);
	glLoadIdentity();
	/*glRotatef(-angle, x, y, z);
	glMultMatrixf(matrixTransfI);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransfI);*/
	glPopMatrix();
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: applyTransf(void) {
	glMultMatrixf(matrixTransf);
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: applyITransf(void) {
	glMultMatrixf(matrixTransfI);
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: render(void) {
	glPushMatrix();
	glMultMatrixf(matrixTransf);
	Group::render();
	glPopMatrix();
}

//-----------------------------------------------------------------------------------------------------------

void Transform :: scale(float x, float y, float z)
{
	glPushMatrix();
	glLoadMatrixf(matrixTransf);
	glScalef(x, y, z);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransf);
	glLoadIdentity();
	/*glScalef(-x, -y, -z);
	glMultMatrixf(matrixTransfI);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixTransfI);*/
	glPopMatrix();
}
