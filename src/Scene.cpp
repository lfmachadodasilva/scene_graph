/* 
 * File:   Scene.cpp
 * Author: Luiz Felipe Machado da Silva
 */

#ifdef _WIN32
	#include <windows.h>
#endif

#include <stdio.h>

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

