#include "face.hpp"

Face::Face(float x,float y){

	sp.Open(std::string("img/penguinface.png"));
	
	box = new Rect(x,y,PENGUIN_RADIX,PENGUIN_RADIX);

}

void Face::Damage(int damage){

	hitpoints -= damage;

}

void Face::Update(float dt){}

void Face::Render(){

	sp.Render(box->getX(),box->getY());

}

bool Face::IsDead(){

	if(hitpoints <= 0){return (true);}

	return(false);

}