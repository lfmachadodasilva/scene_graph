/* 
 * File:   Shape.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "VVector.h"

class Shape {
protected:
	VVector location;
public:
	VVector getLocation(void) {
		return this->location;
	}
	void setLocation(VVector location) {
		this->location = location;
	}
	virtual void draw(void) = 0;
};
#endif