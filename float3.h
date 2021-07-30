#ifndef _Float3_h_
#define _Float3_h_

#include <iostream>
#include <cmath>

class float3
{
	public:
		float x;
		float y;
		float z;
		
		float3();
		float3(float x, float y, float z);
		float3(float x);
		void print();
		
		void dodaj(const float3& a) {x += a.x; y += a.y; z += a.z;}
		
		void mul(const float b) {x *= b; y *= b; z*= b;} 
		
		float3 operator +(const float3& a) {return float3(x + a.x, y + a.y, z + a.z);}
		
		float3 operator *(const float a) {return float3(x * a, y * a, z * a);}
		
		float3 operator /(const float a) {return float3(x / a, y / a, z / a);}
		
		float lenght(){return std::sqrt(x * x + y * y + z * z);}
		
		float3 normalize()
		{
		float n = lenght();
		if(n>0)	 return float3(x/n, y/n, z/n); 
		 else return float3(0.f);
		}
					
		friend std::ostream& operator<<(std::ostream&, const float3& a);
		
		 
};

float3 operator *(const float a, const float3& b);
float3 operator -(const float3& a, const float3& b);
float dot (const float3& a, const float3& b);

#endif

