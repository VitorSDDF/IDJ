#include "bullet.hpp"

Bullet::Bullet(float x,float y,float angle,float speed,float maxDistance,std::string sprite,float frameCount,float frameTime){

	this->sp = new Sprite(sprite,frameCount,frameTime);
	this->box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());
	this->speed = Vec2(speed,0).Rotate(angle);
	this->distanceLeft = maxDistance;
	this->rotation = (angle * 180)/PI;//Converte para graus

	std::cout <<rotation <<" : " << angle <<std::endl;

}

void Bullet::Update(float dt){

	sp->Update(dt);

	box->SetX(box->GetX() + speed.GetX() * dt);
	box->SetY(box->GetY() + speed.GetY() * dt);

	Vec2 distance(speed.GetX() * dt,speed.GetY() * dt);
	distanceLeft -= distance.Magnitude();

}

void Bullet::Render(){

	sp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),rotation);

}
bool Bullet::IsDead(){

	if(distanceLeft <= 0){return(0);}

}