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

Vec2 Vec2::distance(Vec2 destino){

	float dx,dy;
	//Calcula x
	if(x >= 0.0 && destino.GetX() >= 0.0){dx = destino.GetX() - x;}
	else if(destino.GetX() > x){

		if(destino.GetX() >= 0.0 && x <= 0.0){dx = destino.GetX() - x;}
		else{dx = std::abs(destino.GetX() - x);}//(c0 < ZERO_DOUBLE && c1 < ZERO_DOUBLE)
	
	}
	else{//(c0 > c1)

		if(x >= 0.0 && destino.GetX() <= 0.0){dx = -(x - destino.GetX());}
		else{dx = x - destino.GetX();}//(c0 < ZERO_DOUBLE && c1 < ZERO_DOUBLE)

	}
	//Calcula y
	if(y >= 0.0 && destino.GetY() >= 0.0){dy = destino.GetY() - y;}
	else if(destino.GetY() > y){

		if(destino.GetY() >= 0.0 && y <= 0.0){dy = destino.GetY() - y;}
		else{dy = std::abs(destino.GetY() - y);}//(c0 < ZERO_DOUBLE && c1 < ZERO_DOUBLE)
	
	}
	else{//(c0 > c1)

		if(y >= 0.0 && destino.GetY() <= 0.0){dy = -(y - destino.GetY());}
		else{dy = y - destino.GetY();}//(c0 < ZERO_DOUBLE && c1 < ZERO_DOUBLE)

	}

	return(Vec2(dx,dy));

}