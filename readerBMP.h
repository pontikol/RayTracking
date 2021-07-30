#pragma
#include <stdio.h>
#define BYTES_PER_PIXEL  3 /// red, green, & blue
#define FILE_HEADER_SIZE  14
#define INFO_HEADER_SIZE  40

void saveImage(unsigned char* image, int height, int width, char* imageFileName);
unsigned char* createBitmapFileHeader(int height, int stride);
unsigned char* createBitmapInfoHeader(int height, int width);

