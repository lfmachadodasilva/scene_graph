/* 
 * File:   Node.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _NODE_H_
#define _NODE_H_

class Node {
protected :
	Node * parent;
public :
	virtual Node * getParent(void) {
		return parent;
	}
	virtual void setParent(Node * parent) {
		this->parent = parent;
	}
	virtual bool setupCamera(void) = 0;
	virtual int  setupLight(void)  = 0;
	virtual void render(void)      = 0;
};
#endif