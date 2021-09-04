#ifndef _plane_h_
#define _plane_h_
#include "object3d.h"

class Plane : public Object3d
{
	float3 normal;
	float3 origin;
	
	public:
		
		Plane(float3 origin, float3 normal);
		
		Ray interaction(Ray ray);
	
};

#endif
