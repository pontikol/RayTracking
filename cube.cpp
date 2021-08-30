#include "cube.h"

bool Cube::isInside(float3 point)
{
	float3 min = origin - size * 0.5f;
	float3 max = origin + size * 0.5f;
	
	if(point.x >= min.x && point.x <= max.x
	&& point.y >= min.y && point.y <= max.y
	&& point.z >= min.z && point.z <= max.z)
	return true;
	else 
	return false;	
		
}


/* bool Cube::intersection(const float3& origin, const float3& normal, float3& output) 

{
	float3 p;
	float3 n;
	float3 l = origin;
	float3 r = normal;
	float3 point[6];
	bool cross[6]; 
	
	for(int = i; i<6; i++) cross=false;
	
	// ---------------------------- X ------------------------------//
	 p = this->origin + float3(size.x/2.f, 0.f, 0.f);
	 n= float3(1.f, 0.f, 0.f);

	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[0] = origin + normal * d;
	corss[0] = true;
	}
	
	//------------------------------ -X -------------------------------//
	p = this->origin + float3(-size.x/2.f, 0.f, 0.f);
	n = float3(1.f, 0.f, 0.f);
	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[1] = origin + normal * d;
	corss[1] = true;
	}
	
	//------------------------------ Y -------------------------------//
	p = this->origin + float3(0.f, +size.y/2.f, 0.f);
	n = float3(0.f, 1.f, 0.f);
	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[2] = origin + normal * d;
	corss[2] = true;
	}
	
	//------------------------------ Y -------------------------------//
	p = this->origin + float3(0.f, -size.y/2.f, 0.f);
	n = float3(0.f, 1.f, 0.f);
	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[3] = origin + normal * d;
	corss[3] = true;
	}
	
	//------------------------------ Z -------------------------------//
	p = this->origin + float3(0.f, 0.f, +size.z/2.f);
	n = float3(0.f, 0.f, 1.f);
	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[4] = origin + normal * d;
	corss[4] = true;
	}
	
	//------------------------------ Z -------------------------------//
	p = this->origin + float3(0.f, 0.f, -size.z/2.f);
	n = float3(0.f, 0.f, 1.f);
	if(dot(n, r) != 0.f)
	{
	float d = dot(p - l, n) / dot(n, r);	 
	point[5] = origin + normal * d;
	corss[5] = true;
	}
	
	for(int i = 0; i < 6; i++)
	{
		if(cross[i] == true)
		{
			
		}
	}
} */ 

