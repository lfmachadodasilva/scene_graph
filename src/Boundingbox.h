/* 
 * File:   Boundingbox.h
 * Author: Luiz Felipe Machado da Silva
 */

#ifndef _BOUNDINGBOX_H_
#define _BOUNDINGBOX_H_

struct BoundingBox {
	float xmin, xmax;
	float ymin, ymax;
	float zmin, zmax;
	BoundingBox Compare(BoundingBox obj){
		BoundingBox res;
		if( this->xmin < obj.xmin )
			res.xmin = this->xmin;
		else
			res.xmin = obj.xmin;
		if( this->xmax > obj.xmax )
			res.xmax = this->xmax;
		else
			res.xmax = obj.xmax;
		if( this->ymin < obj.ymin )
			res.ymin = this->ymin;
		else
			res.ymin = obj.ymin;
		if( this->ymax > obj.ymax )
			res.ymax = this->ymax;
		else
			res.ymax = obj.ymax;
		if( this->zmin < obj.zmin )
			res.zmin = this->zmin;
		else
			res.zmin = obj.zmin;
		if( this->zmax > obj.zmax )
			res.zmax = this->zmax;
		else
			res.zmax = obj.zmax;
		return res;
	}
};
#endif