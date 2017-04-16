#include "rect.hpp"

Rect::Rect(float x,float y,float w,float h){

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

}

float Rect::getX(){

	return this->x;

}

float Rect::getY(){

	return this->y;
	
}

bool Rect::IsInside(float x,float y){

	return((x <= this->x + w)&&(x >= this->x)&&(y <= this->y + h)&&(y >= this->y));

}

Vec2 Rect::Center(){

	return(Vec2(x + w/2,y + h/2));

}