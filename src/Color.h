/* 
 * File:   Color.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _COLOR_H_
#define _COLOR_H_

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

#include "Appearance.h"

class Color : public Appearance {
protected:
	VVector color;
public:	
	void setColor(VVector color) {
		this->color = color;
	}
	void load(void) {
		glPushAttrib(GL_CURRENT_BIT);
		glColor3f(this->color.x, this->color.y, this->color.z);
	}
	void unLoad(void) {
		glPopAttrib();
	}
};
#endif