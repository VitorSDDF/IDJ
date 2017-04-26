#include "minion.hpp"

Minion::Minion(GameObject* minionCenter,float arcOffset){
	
	sp = new Sprite("img/minion.png");

	Vec2 offsetFromOrigin = Vec2(MINION_DISTANCE_FROM_CENTER,0).Rotate(arcOffset);
	center = minionCenter;
	Vec2 newPos = center->box->Center() + offsetFromOrigin - Vec2(sp->GetWidth()/2, sp->GetHeight()/2);
	box = new Rect(newPos.GetX(),newPos.GetX(),sp->GetWidth(),sp->GetHeight());


}

void Minion::Update(float dt){

	float dArch = minionVel * dt;
	this->arc = dArch;//É isso mesmo?

	float initial_orientation = std::atan2(box->GetX(),box->GetY());
	Vec2 offsetFromOrigin = Vec2(MINION_DISTANCE_FROM_CENTER,0).Rotate(dArch + initial_orientation);
	
	Vec2 newPos = center->box->Center() + offsetFromOrigin - Vec2(box->GetW()/2, box->GetH()/2);			

	box->SetX(newPos.GetX());
	box->SetY(newPos.GetY());

}

void Minion::Render(){

	//Levar em conta o posicionamento da camera
	sp->Render(box->GetX(),box->GetY(),arc);


}

bool Minion::IsDead(){

	return(false);

}
void Minion::Shoot(Vec2 pos){}