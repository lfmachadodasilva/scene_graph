/* 
* File:   Texture.cpp
* Author: Luiz Felipe Machado da Silva
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

#include "Texture.h"

void Texture :: setTexture(int texture) {
	this->texture = texture;
}

//-----------------------------------------------------------------------------------------------------------

void Texture :: setType(int texture) {
	this->type = type;
}

//-----------------------------------------------------------------------------------------------------------

void Texture :: loadTextureFile(char *filename) {
	Image* image = loadBMP(filename);
	if(this->texture == GL_TEXTURE_2D) {
		glGenTextures(1, &this->id_texture); 
		glBindTexture(GL_TEXTURE_2D, this->id_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	}
	else if(this->texture == GL_TEXTURE_1D) {

	}
}

//-----------------------------------------------------------------------------------------------------------

void Texture :: load(void) {
	if(this->texture == GL_TEXTURE_2D){
		GLint type;
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, this->id_texture);

		if(this->type == GL_NEAREST)
			type = GL_NEAREST;
		else
			type = GL_LINEAR;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, type);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, type);
		
	}
	else if(this->texture == GL_TEXTURE_1D) {

	}
	glColor3f(1.0f, 1.0f, 1.0f);
}

//-----------------------------------------------------------------------------------------------------------

void Texture :: unLoad(void) {
	if(this->texture == GL_TEXTURE_2D) 
		glDisable(GL_TEXTURE_2D);
	else
		glDisable(GL_TEXTURE_1D);
}

//-----------------------------------------------------------------------------------------------------------