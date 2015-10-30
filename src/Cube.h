/* 
 * File:   Cube.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _CUBE_H_
#define _CUBE_H_

#include "VVector.h"
#include "Shape.h"

class Cube : public Shape {
protected:
	VVector size;
	VVector vertices[8];
	float texture;
	float offset_factor, offset_units;
public:
	Cube(void) {
		this->texture = 0.0f;
	}
	void setSize(VVector size) {
		this->size = size;
	}
	void setTextureSize(float texture) {
		this->texture = texture;
	}
	void setOffSet(float factor, float units);
	void draw(void);
};
#endif