#include "face.hpp"

Face::Face(float x,float y){

	sp = new Sprite();
	sp->Open(std::string("img/penguinface.png"));

	hitpoints = PENGUIN_INITIAL_HITPOINTS;
	//std::cout << "X-face" <<x << " Y-face" <<y <<std::endl;
	box = new Rect(x,y,2*PENGUIN_RADIX,2*PENGUIN_RADIX);

}

void Face::Damage(int damage){

	hitpoints -= damage;

}

int Face::getHitpoints(){

	return(hitpoints);

}

void Face::Update(float dt){}

void Face::Render(){

	//std::cout << "X-Render" <<box->getX() << " Y-Render" <<box->getY()<< std::endl;
	sp->Render(box->getX(),box->getY());

}

bool Face::IsDead(){

	if(hitpoints <= 0){return (true);}

	return(false);

}