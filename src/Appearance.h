/* 
 * File:   Appearance.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _APPEARANCE_H_
#define _APPEARANCE_H_

class Appearance
{
public:
	virtual void load(void)   = 0;
	virtual void unLoad(void) = 0;
};
#endif