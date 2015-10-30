/* 
 * File:   Transform.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Group.h"

class Transform : public Group {
protected:
	float matrixTransf[16];
	float matrixTransfI[16];
public:
	Transform(void);	
	void translate(float x, float y, float z);
	void rotate(float angle, float x, float y, float z);
	void scale(float x, float y, float z);
	void applyTransf(void);
	void applyITransf(void);
	bool setupCamera(void) {
		return false;
	}
	int setupLight(void) {
		return 0;
	}
	void render(void);
};
#endif
