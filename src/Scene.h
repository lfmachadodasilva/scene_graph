/* 
 * File:   Scene.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _SCENE_H_
#define _SCENE_H_

#include "Group.h"
#include "Node.h"

class Scene : public Group {
protected:
	Node * camera;
public:
	Scene(void) {}
	Node* getParent(void) {
		return NULL;
	}
	void setParent(Node * parent) {
		return;
	}
	Node * getCamera(void) {
		return camera;
	}
	void setCamera(Node * camera) {
		this->camera = camera;
	}
	bool setupCamera(void);
	int  setupLight(void) { 
		return 0; 
	}
	void render(void);
};
#endif _SCENE_H_