#include "triangle.h"
#define kEpsilon 1.0E-10

Triangle::Triangle(float3 v1, float3 v2, float3 v3, Color color) : color(color)
{
	vertex[0] = v1;
	vertex[1] = v2;
	vertex[2] = v3;
	float3 v0v1 = vertex[1] - vertex[0];
	float3 v0v2 = vertex[2] - vertex[0];
	float3 N = cross(v0v1, v0v2); 
	float area2 = N.length();
	normal = N / area2;
	
	
};

bool Triangle::intersection( float3& origin,  float3& direction, float3& oNormal, float3& oPoint)
{
	float NdotRayDirection = dot(normal, direction); 
	if (fabs(NdotRayDirection) < kEpsilon) 
	return false; 

	float t = (dot(normal, vertex[0] - origin)) / NdotRayDirection;
	//std::cout << "\n\nt: " << t << "\nnormal: " << normal << "\nvertex0-origin: " << vertex[0] - origin << std::endl;
	
	if (t < 0) return false; 
	float3 _dir = direction;
	float3 P = origin + _dir * t;
	oPoint = P;
	oNormal = normal;
	//std::cout << "P: " << P << "\n _dir " << _dir << "\n origin: " << origin << std::endl;
	
	//edge 0
	float3 edge0 = vertex[1] - vertex[0];
	float3 vp0 = P - vertex[0];
	float3 C = cross(edge0, vp0); 
	//std::cout << "edge0 DotNormalC: " << dot(normal, C) << std::endl;
	//std::cout << "edge0:: " << edge0 << "\n V1: " << vertex[1] << "\n V0: "<< vertex[0] << "\n vp0: "<< vp0 << "\n P: " << P << "\n C:" << C << "\n normal: "<< normal << std::endl;
	if (dot(normal, C) < 0 ) return false; 

	// edge 1
	float3 edge1 = vertex[2] - vertex[1];
	float3 vp1 = P - vertex[1];
	C = cross(edge1, vp1); 
	//std::cout << "edge1: " << dot(normal, C) << std::endl;
	if (dot(normal, C) < 0 ) return false;

	// edge 2
	float3 edge2 = vertex[0] - vertex[2];
	float3 vp2 = P - vertex[2];
	C = cross(edge2, vp2);	
	//std::cout << "edge2: " << dot(normal, C) << std::endl;
	if (dot(normal, C) < 0) return false; 
	//std::cout << "." << std::endl;
	return true; 
}

std::ostream& operator<<(std::ostream& out, const Triangle& t) 
{
	out << t.normal << "\n" << t.vertex[0] << "\n" << t.vertex[1] << "\n" << t.vertex[2];
}

