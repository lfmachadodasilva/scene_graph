/* 
 * File:   Light.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Node.h"
#include "VVector.h"

class Light : public Node {
protected:
	int id;
	VVector location;
	float ambient[4], diffuse[4], speculate[4];
public:
	Light(void);
	void setLocation(VVector location);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpeculate(float r, float g, float b, float a);
	bool setupCamera(void);
	int setupLight(void);
	void render(void);
};
#endif