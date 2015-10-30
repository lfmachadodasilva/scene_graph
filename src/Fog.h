/* 
 * File:   Fog.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _FOG_H_
#define _FOG_H_

#include "Node.h"
#include "VVector.h"

class Fog : public Node {
protected:
	float color[4];
	float start, end;
public:
	Fog(void) {}
	void setColor(float r, float g, float b, float a);
	void setDistance(float start, float end);
	bool setupCamera(void) { 
		return true;
	}
	int setupLight(void) {
		return 0;
	}
	void render(void);
};
#endif