/* 
* File:   Fog.cpp
* Author: Luiz Felipe Machado da Silva
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

#include "Fog.h"

void Fog :: setColor(float r, float g, float b, float a) {
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	this->color[3] = a;
}

//-----------------------------------------------------------------------------------------------------------

void Fog :: setDistance(float start, float end) {
	this->start = start;
	this->end   = end;
}

//-----------------------------------------------------------------------------------------------------------

void Fog :: render(void) {
	glEnable (GL_FOG); 
	glFogfv(GL_FOG_COLOR, this->color);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, this->start);
	glFogf(GL_FOG_END, this->end);
	glFogi(GL_FOG_MODE, GL_LINEAR);
}

//-----------------------------------------------------------------------------------------------------------