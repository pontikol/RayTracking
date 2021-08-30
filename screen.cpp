#include "screen.h"
#include "readerBMP.h"

Screen::Screen(int I, int J, float X, float Y, float z): matrixSize(I, J), screenSize(X, Y, z)
{
	matrix.resize(I);
	for(int i = 0; i < I; i++)
	{
		matrix[i].resize(J);
	}
}

float3 Screen::pixel2point(const int i, const int j)
{
	const float x = 2.f * screenSize.x * i / matrixSize.x - screenSize.x;
	const float y = -2.f * screenSize.y * j / matrixSize.y + screenSize.y;
	return float3(x, y, screenSize.z);
}

int2 Screen::point2pixel(const float x, const float y)
{
	const int i = matrixSize.x * x / (2.f * screenSize.x) + matrixSize.x * 0.5f; 
	const int j = -matrixSize.y * y / (2.f * screenSize.y) - matrixSize.y * 0.5f;
	return int2 (i, j);
	
}

void Screen::save(const char* name)
{
std::cout << "Save" << std::endl;
int J = matrixSize.y;
int I = matrixSize.x;
unsigned char* image = new unsigned char[J * I * BYTES_PER_PIXEL];// [J] [I] [BYTES_PER_PIXEL] ;



int JK = (J - 1) * (I - 1);



for (int j = 0; j < J; j++)
{
for (int i = 0; i < I; i++)
{



image[j * BYTES_PER_PIXEL * I + i * BYTES_PER_PIXEL + 0] = matrix[i][j].b * 255.f;
image[j * BYTES_PER_PIXEL * I + i * BYTES_PER_PIXEL + 1] = matrix[i][j].g * 255.f;
image[j * BYTES_PER_PIXEL * I + i * BYTES_PER_PIXEL + 2] = matrix[i][j].r * 255.f;
}
}
saveImage((unsigned char*)image, J, I, (char*)name);



delete[] image;



std::cout << "Image generated!!" << std::endl;
}
