#include "bullet.hpp"

Bullet::Bullet(float x,float y,float angle,float speed,float maxDistance,std::string sprite,bool targetsPlayer,float frameCount,float frameTime){

	this->sp = new Sprite(sprite,frameCount,frameTime);
	this->box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());
	this->speed = Vec2(speed,0).Rotate(angle);
	this->distanceLeft = maxDistance;
	this->rotation = (angle * 180)/PI;//Converte para graus
	this-> targetsPlayer = targetsPlayer;

}

void Bullet::Update(float dt){

	sp->Update(dt);

	box->SetX(box->GetX() + speed.GetX() * dt);
	box->SetY(box->GetY() + speed.GetY() * dt);

	distanceLeft -= speed.Magnitude() * dt;

	std::cout <<distanceLeft <<std::endl;

}

void Bullet::Render(){

	sp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),rotation);

}
bool Bullet::IsDead(){

	return(distanceLeft <= 0);

}

void Bullet::NotifyCollision(GameObject& other){

	if((other.Is("Penguins") && targetsPlayer) || (other.Is("Alien") && !targetsPlayer) || (other.Is("Minion") && !targetsPlayer)){

		distanceLeft = 0;

	}

}

bool Bullet::Is(std::string type){

	return(type == "Bullet");

}
bool Bullet::TargetsPlayer(){

	return(targetsPlayer);

}