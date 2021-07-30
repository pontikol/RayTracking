#include "sphere.h"
#include <cmath>

bool Sphere::intersection(const float3& origin, const float3& normal, float3& output)
{

	 float3 u = normal;
	 float3 o = origin;
	 float3 c = center;
	 float3 oc = o-c;
	 float r = radius;
	const float dotUoc = dot(u, oc);
	const float delta = dotUoc * dotUoc - dot(oc, oc) + r * r;
	/* std::cout << "u: " << u << std::endl;
	std::cout << "o: " << o << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "oc: " << oc << std::endl;
	std::cout << "r: " << r<< std::endl;
	std::cout << "dotUoc: " << dotUoc << std::endl;
	std::cout << "delta: " << delta << std::endl;
	std::cout << std::endl; */
	if(delta < 0.f) return false;
	
	 float d1 = -dotUoc + std::sqrt(delta);
	 float d2 = -dotUoc - std::sqrt(delta);
	
	const float3 p1 = o + (u * d1);
	const float3 p2 = o + (u * d2);
	
	 float3 op1 = o - p1;
	 float3 op2 = o - p2;
	
	if(op1.lenght() < op2.lenght()) output = p1;
	else output = p2;
	return true;
	
}



