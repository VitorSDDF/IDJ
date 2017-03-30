#ifndef RECT_HPP
#define RECT_HPP

class Rect{

	public:

		Rect(float x,float y,float w,float h);
		float getX();
		float getY();
		
		float x,y,w,h;
		bool IsInside(float x,float y);

};

#endif
