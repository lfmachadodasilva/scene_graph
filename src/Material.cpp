/* 
* File:   Material.cpp
* Author: Luiz Felipe Machado da Silva
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

#include "Material.h"

void Material :: setAmbient(float r, float g, float b, float a) {
	this->ambient[0] = r;
	this->ambient[1] = g;
	this->ambient[2] = b;
	this->ambient[3] = a;
}
void Material :: setDiffuse(float r, float g, float b, float a) {
	this->diffuse[0] = r;
	this->diffuse[1] = g;
	this->diffuse[2] = b;
	this->diffuse[3] = a;
}
void Material :: setSpeculate(float r, float g, float b, float a) {
	this->speculate[0] = r;
	this->speculate[1] = g;
	this->speculate[2] = b;
	this->speculate[3] = a;
}
void Material :: load(void) {
	glPushAttrib(GL_LIGHTING_BIT);
	glMaterialfv(GL_FRONT, GL_AMBIENT,  this->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,  this->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, this->speculate);
}
void Material :: unLoad(void) {
	glPopAttrib();
}