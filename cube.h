#ifndef _cube_h_
#define _cube_h_
#include "float3.h"


class Cube
{
	float3 size;
	float3 origin;
	
	public: 
	
	Cube(float3 a, float3 b) : size(a), origin(b){} 
	
	bool intersection(const float3& origin, const float3& normal, float3& output);
	
	bool isInside(float3 point);
};

#endif
