#ifndef _screen_h_
#define _screen_h_
#include "float3.h"
#include "color.h"
#include <vector>

class int2
{
	public:
		int2(int x, int y): x(x), y(y){}
	int x, y;	
};

class Screen
{
	int2 pixelSize;
	float3 screenSize;
//	std::vector<std::vector<Color>> matrix;
	public:
	
	void save(const char* name);
	
	std::vector<std::vector<Color>> matrix;
	Screen(int I, int J, float X, float Y, float z);
	float3 pixel2point(const int i, const int j);
	int2 point2pixel(const float x, const float y);
};


#endif
