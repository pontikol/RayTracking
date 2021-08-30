#ifndef _ray_h_
#define _ray_h_
#include "float3.h"
#include "color.h"

class Object3d;

class Ray
{
	public:
	float3 origin;
	float3 direction;
	Color color;	
	bool isEnd = true;
	Object3d *object;
};


#endif
