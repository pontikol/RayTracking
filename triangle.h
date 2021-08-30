#ifndef _Triangle_h_
#define _Triangle_h_
#include "float3.h"
#include "color.h"


class Triangle
{
	Color color;
	float3 normal;
	float3 vertex[3];
	
	public:
	
		Triangle(){};
		Triangle(float3 v1, float3 v2, float3 v3, Color color = Color(1.f, 1.f, 1.f, 1.f));
		
		bool intersection( float3& origin,  float3& direction, float3& oNormal, float3& oPoint);
		
		Color GetColor(){return color;}
		
		float3 GetVertex(int i) {return vertex[i];}
		
		float3 GetNormal(){return normal;}
		
		void SetVertex(int i, float3 value) {vertex[i] = value;} 
		
		friend std::ostream& operator<<(std::ostream&, const Triangle& t);
		
		void SetNormal(float3 value){normal = value;}
	
};

#endif 
