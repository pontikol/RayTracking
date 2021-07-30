#include "float3.h"
#include "camera.h"
#include <iostream>
#include "sphere.h"




int main ()
{
   /* int height = 361;
    int width = 867;
    unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName = (char*) "bitmapImage.bmp";

    int i, j;
    
    float dh = 255.f/(height-1.f);
    float dw = 255.f/(width-1.f);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            image[i][j][2] =255;//(unsigned char) ( (float) i * df );             ///   255* {0 - 1} = {0, 255}
            image[i][j][1] =(unsigned char) 
			( 0.25f * ( (float) j * dw) 
			+ 0.75f * ( (float) i * dh)); // (unsigned char) ( j * 255 / width );              ///green  222.7 -> 222
            image[i][j][0] =255; // (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue
        }
    }

    saveImage((unsigned char*) image, height, width, imageFileName);
    printf("Image generated!!");*/
    int I = 1000;
    int J = 500;
    
    float X = 1.f;
    float Y = 0.5f;
    float3 c(-0.4f, 0.f, 2.f);
    float3 c2(0.4f, 0.f, 1.f);
    float3 zero;
    float3 light(0.f, 0.f, -1.f);
	Screen screen(I, J, X, Y, -1.f);
	Sphere sphere(0.2f, c);
	Sphere sphere2(0.2f, c2);
	
	
//	unsigned char image[J+1][I+1][BYTES_PER_PIXEL];
//    char* imageFileName = (char*) "bitmapImage.bmp";
	
//	for(float x = -X; x <= X; x += 0.1f)
//		for(float y = -Y; y <= Y; y += 0.1f)
	std::cout << "Save" << std::endl;	
	for(int j = 0; j < J; j++ )
	{
		for(int i = 0; i < I; i++ )
		{
			//float3 n(0.f, 0.f, 1.f);
			float3 o = screen.pixel2point(i, j);
			float3 n = zero - o;
			
			// std::cout << n << std::endl;
			
			n = n.normalize();
			float3 output;
			if(sphere.intersection(o, n, output))			{
			float3 v = output - sphere.GetCenter();
			v = v.normalize();
			float alpha = dot(light, v);
			if(alpha < 0.f) alpha = 0.f;
//			image[j][i][2] = alpha * 255.f;//(unsigned char) ( (float) i * df );             ///   255* {0 - 1} = {0, 255}
//           image[j][i][1] = 0;
//            image[j][i][0] = 0; // (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue
            screen.matrix[i][j] = Color(alpha, 0.f, 0.f, 1.f);
			 }
			 
				else	if(sphere2.intersection(o, n, output))
			{
			float3 v = output - sphere2.GetCenter();
			v = v.normalize();
			float alpha = dot(light, v);
			if(alpha < 0.f) alpha = 0.f;
//			image[j][i][2] = 0;//(unsigned char) ( (float) i * df );             ///   255* {0 - 1} = {0, 255}
//            image[j][i][1] = alpha * 255.f;
//            image[j][i][0] = 0; // (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue
            screen.matrix[i][j] = Color(0.f, alpha, 0.f, 1.f);
			 }
			else
			{
//			image[j][i][2] = 0;//(unsigned char) ( (float) i * df );             ///   255* {0 - 1} = {0, 255}
//            image[j][i][1] = 0;
//            image[j][i][0] = 0; // (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue
            screen.matrix[i][j] = Color();
			 } 
		//	std::cout << i << ", " << j << "\t" << screen.pixel2point(i, j) << std::endl;
		}
	//	std::cout << std::endl;
	}
//	saveImage((unsigned char*) image, J+1, I+1, imageFileName);
//    std::cout << "Image generated!!" << std::endl;
screen.save("output.bmp");	
	return 0; 
}


