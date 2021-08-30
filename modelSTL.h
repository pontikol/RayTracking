#ifndef _readerSTL_h_
#define _readerSTL_h_
#include <vector>
#include <string>
#include "triangle.h"
#include "object3d.h"


class ModelSTL : public Object3d
{
	std::vector<Triangle> elements;
	float3 min;
	float3 max;
	float3 size;
	float3 origin;
	public:
	void calSize();
	void read(std::string name);
	void print();
	float3 GetSize(){return size;}
	float3 GetOrigin(){return origin;}
	bool intersection( float3& origin,  float3& direction, float3& oNormal, float3& oPoint, Color& color);
	
	void scale(float value);
	void move(float3 value);
	void addTriangle(Triangle triangle){elements.push_back(triangle);}
	void clear(){elements.clear();}
	
	Triangle GetTriangle(int i) {return elements[i];}
	
	void rotate(float phi, float psi, float tetha);
	
	Ray interaction(Ray ray);
	
};


#endif
