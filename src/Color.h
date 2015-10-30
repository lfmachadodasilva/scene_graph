/* 
 * File:   Color.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _COLOR_H_
#define _COLOR_H_

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

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