#ifndef _sphere_h_
#define _sphere_h_
#include "float3.h"
#include "object3d.h"


class Sphere : public Object3d
{
	float3 center;
	float radius;
	
	public:
	
	Sphere(float radius, float3 center): radius(radius), center(center){}

	Sphere(float radius, float3 center, Color color) : radius(radius), center(center) {this -> color = color;} 
		
	bool intersection(const float3& origin, const float3& normal, float3& output);
	
	Ray interaction(Ray ray);
	
	float3 GetCenter(){return center;}
	
	 
};

#endif
