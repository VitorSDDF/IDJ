#include "Rect.hpp"

Rect::Rect(float x,float y,float w,float h){

	this->x = x;
	this->y = y;

}

float Rect::getX(){

	return this->x;

}

float Rect::getY(){

	return this->x;
	
}

bool Rect::IsInside(float x,float y){

	return((x <= this->x + w)&&(x >= this->x)&&(y <= this->x + w)&&(y <= this->y));

}