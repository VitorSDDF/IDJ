#ifndef RECT_HPP
#define RECT_HPP

#include "vec2.hpp"

class Rect{

	public:

		Rect(float x,float y,float w,float h);
		float getX();
		float getY();
		
		float x,y,w,h;
		bool IsInside(float x,float y);
		Vec2 Center();

};

#endif
