#include "vec2.hpp"

Vec2::Vec2(){}

Vec2::Vec2(float x,float y){

	this->x = x; 
	this->y = y;

}

void Vec2::SetX(float x){

	this-> x = x;

}
void Vec2::SetY(float y){

	this->y = y;

}

float Vec2::GetX(){

	return(x);

}
float Vec2::GetY(){

	return(y);
	
}

Vec2 Vec2::operator+(Vec2 const &b)const{

	return Vec2(x+b.x, y+b.y);

}

Vec2 Vec2::operator-(Vec2 const &b) const{

	return Vec2(x-b.x, y-b.y);

}

Vec2 Vec2::operator*(float b) const{

	return Vec2(x*b, y*b);//esse aqui zoa a magnetude

}