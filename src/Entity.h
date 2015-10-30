/* 
 * File:   Entity.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Shape.h"
#include "Appearance.h"

class Entity : public Node {

protected:
	Shape * shp;
	Appearance * app;
public:
	void setShape(Shape * shape) {
		this->shp = shape;
	}
	void setAppearence(Appearance * appearence) {
		this->app = appearence;
	}
	bool setupCamera(void) {
		return false;
	}
	int setupLight(void) {
		return 0;
	}
	void render(void) {
		this->app->load();
		this->shp->draw();
		this->app->unLoad();
	}
};
#endif
