#ifndef RECT_HPP
#define RECT_HPP

#include "vec2.hpp"

class Rect{

	public:

		Rect(float x,float y,float w,float h);
		float GetX();
		float GetY();		
		float GetW();
		float GetH();		
		bool IsInside(float x,float y);
		void SetX(float x);
		void SetY(float x);

		Vec2 Center();

	private:

		float x,y,w,h;



};

#endif
