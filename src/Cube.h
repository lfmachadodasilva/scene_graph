/* 
 * File:   Cube.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _CUBE_H_
#define _CUBE_H_

#include "VVector.h"
#include "Shape.h"
#include "Boundingbox.h"

class Cube : public Shape {
protected:
	VVector size;
	VVector vertices[8];
public:
	void setSize(VVector size) {
		this->size = size;
	}
	BoundingBox getBoundingBox(void);
	void draw(void);
};
#endif