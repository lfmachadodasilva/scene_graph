/* 
 * File:   Environ.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _ENVIRON_H_
#define _ENVIRON_H_

#include "Group.h"

class Environ : public Group {
protected:
public :
	bool setupCamera(void) {
		return false;
	}
	int  setupLight(void) {
		return 0;
	}
	void render(void) {
		Group::render();
	}
};
#endif
