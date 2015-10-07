/* 
 * File:   Group.cpp
 * Author: Luiz Felipe Machado da Silva
 */

#include <stdlib.h>
#include <stdio.h>

#include "Group.h"

//-----------------------------------------------------------------------------------------------------------

Group :: Group(void) {
	this->size = 0;
}

//-----------------------------------------------------------------------------------------------------------

bool Group :: addNode(Node *node) {
	if(size > 20){
		printf("Error - File: Group.cpp - Size of the vector of node.\n\n");
		return false;
	}
	this->node[this->size] = node;
	(this->node[this->size])->setParent(this);
	(this->size)++;
	return true;
}

//-----------------------------------------------------------------------------------------------------------

int Group :: setupLight(void) {
	int lights = 0;
	for(int i = 0; i < this->size; i++)
		lights += this->node[i]->setupLight();

	return lights;
}

//-----------------------------------------------------------------------------------------------------------

void Group :: render(void) {
	for(int i = 0; i < this->size; i++)
		this->node[i]->render();
}

//-----------------------------------------------------------------------------------------------------------
