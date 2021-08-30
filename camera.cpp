#include "camera.h"
#include "sphere.h"
#include "triangle.h"
#include "modelSTL.h"
#define M_PI 3.14159265358979323846

void Camera::Render(std::string name)
{
	int I = screen.GetMatrixSize().x;
    int J = screen.GetMatrixSize().y;
    
   //std::vector<Object3d*> object3d;
   object3d.clear();
    
    float X = 1.f;
    float Y = 1.f;
    float3 zero;
    float3 light(1.f, 1.f, 1.f);
    light = light.normalize();
	Screen screen(I, J, X, Y, -4.f);
	
	Sphere sphere1(0.2f, float3(0.0f, 0.0f, 2.0f), Color(1.f, 1.f, 0.f, 1.f));
	Sphere sphere2(0.2f, float3(0.2f, 0.2f, 1.5f), Color(0.f, 1.f, 1.f, 1.f));
	Sphere sphere3(0.2f, float3(-0.1f, 0.3f, 1.7f), Color(1.f, 0.f, 1.f, 1.f));
	
	/*sphere1.SetColor(Color(1.f, 1.f, 0.f, 1.f));
	sphere2.SetColor(Color(0.f, 1.f, 1.f, 1.f));
	sphere1.SetColor(Color(1.f, 0.f, 1.f, 1.f));*/
	
	object3d.push_back(&sphere2);
	object3d.push_back(&sphere1);
	object3d.push_back(&sphere3);
	ModelSTL model;
	
	model.addTriangle(	Triangle(float3(-1, -1, 1), float3(-1, 1, 1), float3(1, 1, 1), Color(0.f, 0.f, 1.f, 1.f)));
	model.addTriangle(	Triangle(float3(-1, -1, 1), float3(1, 1, 1), float3(1, -1, 1), Color(0.f, 0.f, 1.f, 1.f)));
	
	model.addTriangle(	Triangle(float3(-1, -1, -1), float3(1, 1, -1), float3(-1, 1, -1), Color(1.f, 1.f, 0.f, 1.f)));
	model.addTriangle(	Triangle(float3(-1, -1, -1), float3(1, -1, -1), float3(1, 1, -1), Color(1.f, 1.f, 0.f, 1.f)));
	
	model.addTriangle(	Triangle(float3(-1, 1, 1), float3(-1, 1, -1), float3(1, 1, 1), Color(0.f, 1.f, 0.f, 1.f)));
	model.addTriangle(	Triangle(float3(1, 1, 1), float3(-1, 1, -1), float3(1, 1, -1), Color(0.f, 1.f, 0.f, 1.f)));
	
	model.addTriangle(	Triangle(float3(-1, -1, 1), float3(-1, -1, -1), float3(1, -1, 1), Color(1.f, 0.f, 1.f, 1.f)));
	model.addTriangle(	Triangle(float3(1, -1, 1), float3(-1, -1, -1), float3(1, -1, -1), Color(1.f, 0.f, 1.f, 1.f)));
	
	model.addTriangle(	Triangle(float3(1, 1, 1), float3(1, 1, -1), float3(1, -1, 1), Color(1.f, 0.f, 0.f, 1.f)));
	model.addTriangle(	Triangle(float3(1, -1, 1), float3(1, 1, -1), float3(1, -1, -1), Color(1.f, 0.f, 0.f, 1.f)));
	
	model.addTriangle(	Triangle(float3(-1, 1, 1), float3(-1, 1, -1), float3(-1, -1, 1), Color(0.f, 1.f, 1.f, 1.f)));
	model.addTriangle(	Triangle(float3(-1, -1, 1), float3(-1, 1, -1), float3(-1, -1, -1), Color(0.f, 1.f, 1.f, 1.f)));
	
	
	model.calSize();
	model.move(model.GetOrigin() * -1.f);
	float scale = std::max(model.GetSize().x, std::max(model.GetSize().y, model.GetSize().z));
	
	model.scale(0.25f/scale);
	model.rotate(30 * M_PI / 180, 30 * M_PI / 180.f, 30 * M_PI / 180.f);
	model.move(float3(-0.2f, -0.2f, 2.f));
	model.calSize();
	object3d.push_back(&model);
	
	ModelSTL model2;
	
	model2.read("D:\\RT\\STL\\Bear_low_poly_stl.stl");
	
	model2.calSize();
	model2.move(model.GetOrigin() * -1.f);
	float scale2 = std::max(model2.GetSize().x, std::max(model2.GetSize().y, model2.GetSize().z));
	
	model2.scale(0.25f/scale2);
	model2.rotate(30 * M_PI / 180, 30 * M_PI / 180.f, 30 * M_PI / 180.f);
	model2.move(float3(+0.2f, -0.2f, 2.f));
	model2.calSize();
	object3d.push_back(&model2);
	
	
			
	for(int i = 0; i < I; i++ )
	{
		for(int j = 0; j < J; j++ )
		{
			
			screen.matrix[i][j] = Color(0.f, 0.f, 0.f, 1.f);
			
			Ray ray;
			ray.origin = screen.pixel2point(i, j);
			ray.direction = normalize(zero - ray.origin); 
			
			ray.object = nullptr;
			
			Ray next = CalRay(ray, ray.object);
			
			
			std::vector<Ray> rays; 
			
			rays.push_back(next);
			
			for(int k = 0; k < 4; k++)
			{
				if(rays.back().isEnd) break;
				Ray temp = CalRay(rays.back(), rays.back().object);	
				rays.push_back(temp);
			}
			
			if(rays.size() > 0) 
			{
				float alpha = ( -dot(light, rays[0].direction));
				if(alpha < 0.f) alpha = 0.f;
				alpha = 0.25f + 0.75f * alpha;
				Color color1 = Color(alpha * rays[0].color.r, alpha * rays[0].color.g, alpha * rays[0].color.b, 1.f);
				
				//for(int k = rays.size() - 3; k >= 0; k--)
				for(int k = 1; k < rays.size() -1;k++)
				
				{
					
				float alpha = ( -dot(light, rays[k].direction));
				if(alpha < 0.f) alpha = 0.f;
				alpha = 0.25f + 0.75f * alpha;
				
				Color color2 = Color(alpha * rays[k].color.r, alpha * rays[k].color.g, alpha * rays[k].color.b, 1.f);

				float _a = 0.8f;
				float _b = 1.f - _a;
				float r = _a * color1.r + _b * color2.r;
				float g = _a * color1.g + _b * color2.g;				 
				float b = _a * color1.b + _b * color2.b;
				
				color1 = Color(r, g, b, 1.f);
				
				}
				screen.matrix[i][j] = color1;		
			}
			 
			/* 
			if( !next.isEnd)
			{
				float alpha = ( -dot(light, next.direction));
				if(alpha < 0.f) alpha = 0.f;
				alpha = 0.5f + 0.5f * alpha;
				Color c = Color(alpha * next.color.r, alpha * next.color.g, alpha * next.color.b, 1.f);

				screen.matrix[i][j] = c;
				
				if (rays.size() == 3) screen.matrix[i][j] = Color(1.f, 1.f, 1.f, 1.f);
				if (rays.size() == 4) screen.matrix[i][j] = Color(1.f, 0.f, 0.f, 1.f);
				if (rays.size() == 5) screen.matrix[i][j] = Color(0.f, 0.f, 1.f, 1.f);

				
				
				Ray next1 = CalRay(next, next.object);				
					if( !next1.isEnd) 
					{
						float alpha = ( -dot(light, next1.direction));
				if(alpha < 0.f) alpha = 0.f;
				alpha = 0.5f + 0.5f * alpha;
				Color c1 = Color(alpha * next1.color.r, alpha * next1.color.g, alpha * next1.color.b, 1.f);

				float _a = 0.8f;
				float _b = 1.f - _a;
				float r = _a * c.r + _b * c1.r;
				float g = _a * c.g + _b * c1.g;				 
				float b = _a * c.b + _b * c1.b;
				
				screen.matrix[i][j] = Color(r, g, b, 1.f);
		
					}//screen.matrix[i][j] = Color(1.f, 1.f, 1.f, 1.f);
				
				
			} */
			
			/*Ray nextRay = object3d[0]->interaction(ray);
			if(nextRay.isEnd == false)
			{
			            	
            	float alpha = ( -dot(light, nextRay.direction));
				if(alpha < 0.f) alpha = 0.f;
				alpha = 0.5f + 0.5f * alpha;
				Color c = nextRay.color;
				
				screen.matrix[i][j] = Color(alpha * c.r, alpha * c.g, alpha * c.b, 1.f);				
				
				Ray nextRay2 = object3d[1]->interaction(nextRay);
				if(nextRay2.isEnd == false)
				{
			            	
            		float alpha = ( -dot(light, nextRay.direction));
					if(alpha < 0.f) alpha = 0.f;
					alpha = 0.5f + 0.5f * alpha;
					alpha = 1.f;
					Color c1 = nextRay2.color;
					screen.matrix[i][j] = Color(alpha * c1.r, alpha * c1.g, alpha * c1.b, 1.f);
					//std::cout << "\nold ray: " << ray.direction << std::endl;
					//std::cout << i << " " << j << std::endl;
				
				}

			}*/
			
		
		}
	}	
	
screen.save(name.c_str());	
}

	Ray Camera::CalRay(Ray ray, Object3d* object)
	{						
			Ray temp;
			bool isInteraction = false;
			float3 point; 
			float distance;
		
			for(int k = 0; k < object3d.size(); k++ )
			{
				
				if(object == object3d[k]) continue;
				
				Ray nextRay = object3d[k]->interaction(ray);
				if(nextRay.isEnd == false)
			
				{
			         
					if(isInteraction == false)
					{
						point = nextRay.origin;
						isInteraction = true;					
						temp = nextRay;
						temp.object = object3d[k];
						float3 v = ray.origin - nextRay.origin;
						distance = v.length();
					}	
					else
					{
						float3 v = ray.origin - nextRay.origin;
						float d = v.length();
						if(d < distance)
						{
							temp = nextRay;
							temp.object = object3d[k];
							point = nextRay.origin;
							distance = d;
						}
					} 
					    	
            		
				}
					
			}
			if(isInteraction)
			{
				//std::cout << "temp: " << temp.object << std::endl;
				return temp;
			}
			
			return Ray();
	}

