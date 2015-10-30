/* 
 * File:   Scene.cpp
 * Author: Luiz Felipe Machado da Silva
 */

#ifdef _WIN32
	#include <windows.h>
#endif

#include <stdio.h>

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

#include "Scene.h"

//-----------------------------------------------------------------------------------------------------------

bool Scene :: setupCamera(void) {
	if(camera == NULL)
		return false;
	return camera->setupCamera();
}

//-----------------------------------------------------------------------------------------------------------

void Scene :: render(void) {
	if(!setupCamera())
		printf("Error - File: Scene.cpp - Setup of the camera.");
	if(Group::setupLight() > 0)
		glEnable(GL_LIGHTING);
	Group::render();
}

//-----------------------------------------------------------------------------------------------------------

