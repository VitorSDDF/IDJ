#include "rect.hpp"

Rect::Rect(float x,float y,float w,float h){

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

}

float Rect::GetX(){

	return(this->x);

}

float Rect::GetY(){

	return(this->y);
	
}

float Rect::GetW(){

	return(this->w);

}

float Rect::GetH(){

	return(this->h);

}

bool Rect::IsInside(float x,float y){

	return((x <= this->x + w)&&(x >= this->x)&&(y <= this->y + h)&&(y >= this->y));

}

Vec2 Rect::Center(){

	return(Vec2(x + w/2,y + h/2));

}

void Rect::SetX(float x){

	this->x = x;

}

void Rect::SetY(float y){

	this->y = y;
}