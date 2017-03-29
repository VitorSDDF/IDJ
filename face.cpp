#include "face.hpp"

Face::Face(float x,float y){

	sp.Open(std::string("img/penguinface.png"));

	box.x = x;
	box.y = y;

}

void Face::Damage(int damage){

	hitpoints -= damage;

}

void Face::Update(){}

void Face::Render(){

	sp->Render(box.x,box.y);
}

bool Face::isDead(){

	hitpoints <= 0 ? return true : return false;

}