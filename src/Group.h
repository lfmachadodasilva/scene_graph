/* 
 * File:   Group.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include "Boundingbox.h"

class Group : public Node {
protected :
	int size;
	Node * node[20];
public :
	Group(void);
	bool addNode(Node * node);
	virtual bool setupCamera(void) = 0;
	virtual int  setupLight(void)  = 0;
	virtual void render(void)      = 0;
};
#endif