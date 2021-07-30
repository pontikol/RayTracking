#ifndef _color_h_
#define _color_h_

class Color 
{
	public:
	
	float r;
	float g;
	float b;
	float a;
	Color();

	Color(float R, float G, float B, float A):r(R), g(G), b(B), a(A) {} 
};

#endif
