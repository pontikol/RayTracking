#include "sphere.h"
#include <cmath>


Ray Sphere::interaction(Ray ray) 
{

	 float3 u = ray.direction;
	 float3 o = ray.origin;
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
	if(delta < 0.f) return Ray();
	Ray outRay;
	 float d1 = -dotUoc + std::sqrt(delta);
	 float d2 = -dotUoc - std::sqrt(delta);
	
	const float3 p1 = o + (u * d1);
	const float3 p2 = o + (u * d2);
	
	 float3 op1 = o - p1;
	 float3 op2 = o - p2;
	
	if(op1.length() < op2.length()) outRay.origin = p1;
	else outRay.origin = p2;
	
	if (dot(outRay.origin - ray.origin, ray.direction) < 0)
	return Ray();
	
	
	float3 normal = outRay.origin - center;
	normal = normal.normalize();
	//std::cout << "\nnormal: " << normal << std::endl;
	//std::cout << "\norigin: " << outRay.origin << std::endl;
	float3 p = outRay.origin + ray.direction;
	float t = dot(ray.direction * -1.f , normal);
	float3 pp = p + normal * 2.f * t;
	//std::cout << "P: " << p << std::endl;
	//std::cout << "PP: " << pp << std::endl;
	//std::cout << "T: " << t << std::endl;
	outRay.direction = pp - outRay.origin;
	outRay.color = color;
	outRay.isEnd = false;	
	
	return outRay;
	
}


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
	
	if(op1.length() < op2.length()) output = p1;
	else output = p2;
	return true;
	
}



