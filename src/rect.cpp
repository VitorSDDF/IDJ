#include "rect.hpp"

Rect::Rect(){}

Rect::Rect(float x,float y,float w,float h){

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

}

float Rect::GetX() const{

	return(this->x);

}

float Rect::GetY() const{

	return(this->y);
	
}

float Rect::GetW() const{

	return(this->w);

}

float Rect::GetH() const{

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