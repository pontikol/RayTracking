#include "plane.h"


Plane::Plane(float3 origin, float3 normal) : origin(origin), normal(normal)
{
	
}

Ray Plane::interaction(Ray ray)
{
	float dotLN = dot(ray.direction, normal);
//	std::cout << "DotLN: " << dotLN << std::endl;
	if(dotLN == 0) return Ray();
	float t = dot(origin - ray.origin, normal) / dotLN;
	
//	std::cout << "Ray.direction: " << ray.direction << "\norigin: " << origin << "\nnormal: " << normal << "\nDotLN: " << dotLN << std::endl;
//	std::cout << "t: " << t << std::endl;
//	if(t < 0) return Ray();
	if(dotLN > 0) return Ray();
	
	float3 point = ray.origin + ray.direction * t;
	
//	std::cout << "Point: " << point << std::endl;
	
//	if (dot(point - ray.origin, ray.direction) < 0)
//	return Ray();

Ray output;
output.origin = point;

	float3 p = output.origin + ray.direction;
	float d = dot(ray.direction * -1.f , normal);
	float3 pp = p + normal * 2.f * d;
	output.direction = pp - output.origin;
//	output.direction = normal;
	output.color = color;
	output.isEnd = false; 
	
return output;
}


