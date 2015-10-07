/* 
 * File:   Material.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "VVector.h"
#include "Appearance.h"

class Material : public Appearance {
protected:
	float ambient[4], diffuse[4], speculate[4];
public:
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpeculate(float r, float g, float b, float a);
	void load(void);
	void unLoad(void);
};
#endif