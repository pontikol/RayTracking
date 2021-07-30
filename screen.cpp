#include "screen.h"
#include "readerBMP.h"

Screen::Screen(int I, int J, float X, float Y, float z): pixelSize(I, J), screenSize(X, Y, z)
{
	matrix.resize(I);
	for(int i = 0; i < I; i++)
	{
		matrix[i].resize(J);
	}
}

float3 Screen::pixel2point(const int i, const int j)
{
	const float x = 2.f * screenSize.x * i / pixelSize.x - screenSize.x;
	const float y = -2.f * screenSize.y * j / pixelSize.y + screenSize.y;
	return float3(x, y, screenSize.z);
}

int2 Screen::point2pixel(const float x, const float y)
{
	const int i = pixelSize.x * x / (2.f * screenSize.x) + pixelSize.x * 0.5f; 
	const int j = -pixelSize.y * y / (2.f * screenSize.y) - pixelSize.y * 0.5f;
	return int2 (i, j);
	
}

void Screen::save(const char* name)
{
		std::cout << "Save" << std::endl;	
	int J = pixelSize.y;
	int I = pixelSize.x;
		unsigned char image[J][I][BYTES_PER_PIXEL];
		std::cout << "Save" << std::endl;	
	for(int j = 0; j < J; j++ )
	{
		for(int i = 0; i < I; i++ )
		{
			image[j][i][2] = matrix[i][j].r * 255.f;
            image[j][i][1] = matrix[i][j].g * 255.f;
            image[j][i][0] = matrix[i][j].b * 255.f; 
		}
	}
	saveImage((unsigned char*) image, J, I, (char*) name);	
	std::cout << "Save" << std::endl;	
    std::cout << "Image generated!!" << std::endl;	
}
