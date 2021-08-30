#include "float3.h"
#include "camera.h"
#include <iostream>
#include "screen.h"
#include "modelSTL.h"

int main ()
{
	
	Screen screen(500, 500, 1.f, 1.f, -1.f);

	Camera camera(screen);
	camera.Render("output1.bmp"); 
	
	return 0; 
}



