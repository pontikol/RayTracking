#ifndef _sphere_h_
#define _sphere_h_
#include "float3.h"

class Sphere
{
	float3 center;
	float radius;
	
	public:
	
	Sphere(float radius, float3 center): radius(radius), center(center){}
	
	bool intersection(const float3& origin, const float3& normal, float3& output);
	
	float3 GetCenter(){return center;} 
};

#endif
