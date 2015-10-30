/* 
 * File:   Texture.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Appearance.h"
#include "imageloader.h"

class Texture : public Appearance {
protected:
	int texture, //GL_TEXTURE_1D / GL_TEXTURE_2D
		type;    // GL_NEAREST / GL_LINEAR
	GLuint id_texture;
public:
	void setTexture(int texture) ;
	void setType(int texture);
	void loadTextureFile(char * filename);
	void load(void);
	void unLoad(void);
};
#endif
