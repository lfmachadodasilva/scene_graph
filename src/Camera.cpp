/* 
* File:   Camera.cpp
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

#include "Camera.h"
#include "Transform.h"

//-----------------------------------------------------------------------------------------------------------

bool Camera :: setupCamera(void) {

	int vp[4];
	glGetIntegerv(GL_VIEWPORT, vp);
	float aspect_ratio = (float)vp[2]/vp[3];

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->fovy, aspect_ratio, this->znear, this->zfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	manipulator->SetZCenter((this->zfar - this->znear)/50);	
	manipulator->Load();

	gluLookAt( this->eye.x, this->eye.y, this->eye.z, this->center.x, this->center.y, this->center.z, this->up.x, this->up.y, this->up.z );

	Node * node = this->getParent();
	Node * node_parent = node->getParent();
	while(node_parent != NULL)
	{
		((Transform*)node)->applyITransf();
		node = node_parent;
		node_parent = node->getParent();
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setEye(VVector eye){
	this->eye = eye;
}

//-----------------------------------------------------------------------------------------------------------

VVector Camera :: getEye(void) {
	return this->eye;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setCenter(VVector center){
	this->center = center;
}

//-----------------------------------------------------------------------------------------------------------

VVector Camera :: getCenter(void) {
	return this->center;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setUp(VVector up){
	this->up = up;
}

//-----------------------------------------------------------------------------------------------------------

VVector Camera :: getUp(void) {
	return this->up;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setZnear(float znear) {
	this->znear = znear;
}

//-----------------------------------------------------------------------------------------------------------

float Camera :: getZnear(void) {
	return this->znear;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setZfar(float zfar) {
	this->zfar = zfar;
}

//-----------------------------------------------------------------------------------------------------------

float Camera :: getZfar(void) {
	return this->zfar;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: setfovy(float fovy) {
	this->fovy = fovy;
}

//-----------------------------------------------------------------------------------------------------------

float Camera :: getfovy(void) {
	return this->fovy;
}

//-----------------------------------------------------------------------------------------------------------

int  Camera :: setupLight(void) { 
	return 0;
}

//-----------------------------------------------------------------------------------------------------------

void Camera :: render(void) {
	return;
}

//-----------------------------------------------------------------------------------------------------------