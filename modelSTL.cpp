#include "modelSTL.h"
#include <fstream>

void ModelSTL::read(std::string name) 
{
	std::ifstream file (name,  std::ios::binary);
	if(file.is_open()) 
	{
		char buffer[80];
		file.read(buffer, 80);
		unsigned int NumberOfTriangles = 0;
		file.read((char*)&NumberOfTriangles, sizeof(NumberOfTriangles));
		elements.resize(NumberOfTriangles);
		for(int i = 0; i < NumberOfTriangles; i++)
		{
			float normal[3];
			float vertex1[3];
			float vertex2[3];
			float vertex3[3];
			short count;
			
			file.read((char*)&normal, sizeof(normal));
			file.read((char*)&vertex1, sizeof(vertex1));
			file.read((char*)&vertex2, sizeof(vertex2));
			file.read((char*)&vertex3, sizeof(vertex3));
			file.read((char*)&count, sizeof(count));	
			float3 v1(vertex1);
			float3 v2(vertex2);
			float3 v3(vertex3);
			
			
			elements[i] = Triangle(v1, v2, v3, Color(1, 0, 0, 1));	
		}
		
		file.close();
		calSize();
	}
	else 
	{
		std::cout << "Nie ma takiego pliku" << std::endl;
	}
}

void ModelSTL::print() 
{
	/*for(int i = 0; i < elements.size(); i++)
	{
		std::cout << elements[i] << "\n" << std::endl;
	}*/
	
	std::cout << "Min: " << min << "\nMax: " << max << "\nSize: " << size << "\nOrigin: " << origin << std::endl; 
}

void ModelSTL::calSize()
{
	if(elements.size() == 0) 
	{
		min = float3(0.f);
		max = float3(0.f);
		size = float3(0.f);
		origin = float3(0.f);
		
		return;
	}
	
	min = elements[0].GetVertex(0);
	max = elements[0].GetVertex(0);
	
	for(int i = 0; i < elements.size(); i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(max.x < elements[i].GetVertex(j).x) max.x = elements[i].GetVertex(j).x;
			if(max.y < elements[i].GetVertex(j).y) max.y = elements[i].GetVertex(j).y;
			if(max.z < elements[i].GetVertex(j).z) max.z = elements[i].GetVertex(j).z;
			if(min.x > elements[i].GetVertex(j).x) min.x = elements[i].GetVertex(j).x;
			if(min.y > elements[i].GetVertex(j).y) min.y = elements[i].GetVertex(j).y;
			if(min.z > elements[i].GetVertex(j).z) min.z = elements[i].GetVertex(j).z;
		}
	}
	
	size = max - min;
	origin = (max + min) * 0.5f;
	
}


void ModelSTL::scale(float value)
{
	for(int i = 0; i < elements.size(); i++)
	{
		elements[i].SetVertex(0,  elements[i].GetVertex(0) * value);
		elements[i].SetVertex(1,  elements[i].GetVertex(1) * value);
		elements[i].SetVertex(2,  elements[i].GetVertex(2) * value);
	}
}

void ModelSTL::move(float3 value)
{
	for(int i = 0; i < elements.size(); i++)
	{
		elements[i].SetVertex(0,  elements[i].GetVertex(0) + value);
		elements[i].SetVertex(1,  elements[i].GetVertex(1) + value);
		elements[i].SetVertex(2,  elements[i].GetVertex(2) + value);
	}	
}

Ray ModelSTL::interaction(Ray ray)
//bool ModelSTL::intersection( float3& origin,  float3& direction, float3& oNormal, float3& oPoint, Color& color)
{
	Triangle temp;
	bool isIntersection = false;
	float3 point;
	float distance;
	float3 oNormal;
	float3 oPoint;
	
	
	for(int i = 0; i < elements.size(); i++)
	{
	 	if(elements[i].intersection(ray.origin, ray.direction, oNormal, oPoint))
		{
			//std::cout << "intersection" << std::endl;
			if(isIntersection == false) 
			{
				//std::cout << "if(isIntersection == false)" << std::endl;
				point = oPoint;
				isIntersection = true;
				temp = elements[i];
				float3 v = ray.origin - point; 
				distance = v.length();
			}
			else 
			{
				//std::cout << "if(isIntersection == true)" << std::endl;
				float3 v = ray. origin - oPoint;
				if(distance > v.length())
				{
					temp = elements[i];
					point = oPoint;
					distance = v.length();					
				}
			}
		}
	}
	
	
	
	//std::cout << "isIntersection: " << isIntersection << std::endl;
	if(isIntersection)
	{
		Ray nextRay;
		
	float3 normal = temp.GetNormal();
	
	float3 p = point + ray.direction;
	float t = dot(ray.direction * -1.f , normal);
	float3 pp = p + normal * 2.f * t;
	nextRay.direction = pp - point;
		
		//nextRay.direction = temp.GetNormal();
		nextRay.origin = point;
		nextRay.color = temp.GetColor();
		nextRay.isEnd = false;
		return nextRay;
		//std::cout << "oNormal: " << oNormal << std::endl;
		//std::cout << "oPoint: " << oPoint << std::endl;
		//std::cout << "Color: " << color.r << " " << color.g << " " << color.b << std::endl;
	}
	
return Ray();	
}


bool ModelSTL::intersection( float3& origin,  float3& direction, float3& oNormal, float3& oPoint, Color& color)
{
	Triangle temp;
	bool isIntersection = false;
	float3 point;
	float distance;
	
	for(int i = 0; i < elements.size(); i++)
	{
	 	if(elements[i].intersection(origin, direction, oNormal, oPoint))
		{
			//std::cout << "intersection" << std::endl;
			if(isIntersection == false) 
			{
				//std::cout << "if(isIntersection == false)" << std::endl;
				point = oPoint;
				isIntersection = true;
				temp = elements[i];
				float3 v = origin - point; 
				distance = v.length();
			}
			else 
			{
				//std::cout << "if(isIntersection == true)" << std::endl;
				float3 v = origin - oPoint;
				if(distance > v.length())
				{
					temp = elements[i];
					point = oPoint;
					distance = v.length();					
				}
			}
		}
	}
	
	//std::cout << "isIntersection: " << isIntersection << std::endl;
	if(isIntersection)
	{
		oNormal = temp.GetNormal();
		oPoint = point;
		color = temp.GetColor();
		//std::cout << "oNormal: " << oNormal << std::endl;
		//std::cout << "oPoint: " << oPoint << std::endl;
		//std::cout << "Color: " << color.r << " " << color.g << " " << color.b << std::endl;
	}
	
return isIntersection;	
}

void ModelSTL::rotate(float phi, float psi, float tetha)
{
	float M[3][3];
	M[0][0] = cos(phi) * cos(psi) - sin(phi) * sin(psi) * cos(tetha);
	M[0][1] = sin(phi) * cos(psi) + cos(phi) * sin(psi) * cos(tetha);
	M[0][2] = sin(psi) * sin(tetha);
	
	M[1][0] = -cos(phi) * sin(psi) - sin(phi) * cos(psi) * cos(tetha);
	M[1][1] = -sin(phi) * sin(psi) + cos(phi) * cos(psi) * cos(tetha);
	M[1][2] = cos(psi) * sin(tetha);
		
	M[2][0] = sin(phi) * sin(tetha);
	M[2][1] = -cos(phi) * sin(tetha);
	M[2][2] = cos(tetha);
	
	for(int i = 0; i < elements.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float x = elements[i].GetVertex(j).x;
			float y = elements[i].GetVertex(j).y;
			float z = elements[i].GetVertex(j).z;
			
			float _x = M[0][0] * x + M[0][1] * y + M[0][2] * z;
			float _y = M[1][0] * x + M[1][1] * y + M[1][2] * z;
			float _z = M[2][0] * x + M[2][1] * y + M[2][2] * z;
			
			elements[i].SetVertex(j, float3(_x, _y, _z));
		}
			float x = elements[i].GetNormal().x;
			float y = elements[i].GetNormal().y;
			float z = elements[i].GetNormal().z;
						
			float _x = M[0][0] * x + M[0][1] * y + M[0][2] * z;
			float _y = M[1][0] * x + M[1][1] * y + M[1][2] * z;
			float _z = M[2][0] * x + M[2][1] * y + M[2][2] * z;
						
			elements[i].SetNormal(float3(_x, _y, _z));
			
	}
}

