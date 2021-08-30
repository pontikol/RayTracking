#include "float3.h"
#include <iostream>

float3::float3(const float3& a) : float3(a.x, a.y, a.z){}

float3::float3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;	
}



float3::float3(float _x) : float3(_x, _x, _x)
	{	 
	}
	
float3::float3() : float3(0.f, 0.f, 0.f)
{
	
}

void float3::print()
{
	std::cout << x << ", " << y << ", " << z << std::endl;
}

std::ostream& operator<<(std::ostream& out, const float3& a)
{
	out << a.x << ", " <<  a.y << ", " << a.z;
	return out;
}



float3 operator *(const float& a, const float3& b) {return float3(b.x * a, b.y * a, b.z * a);}	
float3 operator -(const float3& a, const float3& b) {return float3(a.x - b.x, a.y - b.y, a.z - b.z);}
float dot (const float3& a, const float3& b) {return a.x * b.x + a.y * b.y + a.z * b.z;}
float3 cross (const float3& a, const float3& b) 
{
	float3 out;
	out.x = a.y * b.z - a.z * b.y;
	out.y = a.z * b.x - a.x * b.z;
	out.z = a.x * b.y - a.y * b.x;
	return out;
}

float3 normalize(float3 a) 
{
	return a.normalize();
}

