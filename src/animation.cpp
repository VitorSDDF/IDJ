#include "animation.hpp"

Animation::Animation(float x,float y,float rotation,std::string sprite,int frameCount,float frameTime,bool ends){

	this->sp = new Sprite(sprite,frameCount,frameTime);
	this->box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());
	this->rotation = rotation;//Converte para graus
	this->oneTimeOnly = ends;
	this->timeLimit = frameCount * frameTime;

}

void Animation::Update(float dt){

	sp->Update(dt);
	endTimer.Update(dt);

}
void Animation::Render(){

	sp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),rotation);

}
bool Animation::IsDead(){

	return(oneTimeOnly && endTimer.Get() > timeLimit);

}
void Animation::NotifyCollision(GameObject& other){ 

	oneTimeOnly = true;

}

bool Animation::Is(std::string type){

	return(type == "Animation");

}
