/* 
 * File:   Camera.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Node.h"
#include "VVector.h"
#include "manipulator.h"

class Camera : public Node {
protected:
	VVector eye, center, up;
	float znear, zfar, fovy;
	VManipulator *manipulator;
public:
	Camera(void){
		manipulator = VManipulator::Instance();
	}
	void setEye(VVector eye);
	VVector getEye(void);
	void setCenter(VVector center);
	VVector getCenter(void);
	void setUp(VVector up);
	VVector getUp(void);
	void setZnear(float znear);
	float getZnear(void);
	void setZfar(float zfar);
	float getZfar(void);
	void setfovy(float fovy);
	float getfovy(void);
	bool setupCamera(void);
	int  setupLight(void);
	void render(void);
};
#endif