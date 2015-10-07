/* 
* File:   Light.cpp
* Author: Luiz Felipe Machado da Silva
*/

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

#include "Light.h"

static bool lights[5] = {true, true, true, true, true} ;

//-----------------------------------------------------------------------------------------------------------

Light :: Light(void) {
	for(int i = 0; i < 5; i++) {
		if(lights[i]) {
			lights[i] = false;
			this->id = i;
			break;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------

void Light :: setAmbient(float r, float g, float b, float a) {
	this->ambient[0] = r;
	this->ambient[1] = g;
	this->ambient[2] = b;
	this->ambient[3] = a;
}

//-----------------------------------------------------------------------------------------------------------

void Light :: setDiffuse(float r, float g, float b, float a) {
	this->diffuse[0] = r;
	this->diffuse[1] = g;
	this->diffuse[2] = b;
	this->diffuse[3] = a;
}

//-----------------------------------------------------------------------------------------------------------

void Light :: setSpeculate(float r, float g, float b, float a) {
	this->speculate[0] = r;
	this->speculate[1] = g;
	this->speculate[2] = b;
	this->speculate[3] = a;
}

//-----------------------------------------------------------------------------------------------------------

bool Light :: setupCamera(void) {
	return false;
}

//-----------------------------------------------------------------------------------------------------------

int Light :: setupLight(void) {
	GLenum light = GL_LIGHT0 + this->id;
	float pos[4] = { this->location.x, this->location.y, this->location.z, 1.0f }; 
	glLightfv(light, GL_POSITION, pos);
	glLightfv(light, GL_AMBIENT,  this->ambient);
	glLightfv(light, GL_DIFFUSE,  this->diffuse);
	glLightfv(light, GL_SPECULAR, this->speculate);
	glEnable(light);
	return 1;
}

//-----------------------------------------------------------------------------------------------------------

void Light :: render(void) {
	return;
}

//-----------------------------------------------------------------------------------------------------------

void Light :: setLocation(VVector location) {
	this->location = location;
}

//-----------------------------------------------------------------------------------------------------------