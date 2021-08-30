#ifndef _object3d_h_
#define _object3d_h_
#include "ray.h"

class Object3d 
{
	protected:
		Color color;
	public:
		virtual Ray interaction(Ray ray) = 0;
		Color GetColor(){return color;}
		void SetColor(Color c){color = c;}
		
};



#endif

