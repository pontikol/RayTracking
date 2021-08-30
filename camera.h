#ifndef _camera_h_
#define _camera_h_ 
#include "float3.h"
#include "screen.h"
#include <string>
#include "ray.h"
#include "object3d.h"
#include <vector>

class Camera
{
	Screen screen;
	float3 lens;
    std::vector<Object3d*> object3d;

	
	Ray CalRay(Ray ray, Object3d* object);
	
	public:
	
	Camera(Screen& screen):screen(screen){}
	
	void Render(std::string name);
	
	
};

#endif
