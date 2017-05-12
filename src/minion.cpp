#include "minion.hpp"

Minion::Minion(GameObject* minionCenter,float arcOffset){
	
	sp = new Sprite("img/minion.png");
	float scale =((float)(rand() % 6 + 10)) / 10;
	sp->SetScaleX(scale);
	sp->SetScaleY(scale);

	arc = arcOffset;
	Vec2 offsetFromOrigin = Vec2(0,MINION_DISTANCE_FROM_CENTER).Rotate(arc);
	center = minionCenter;
	Vec2 newPos = center->box->Center() + offsetFromOrigin;
	box = new Rect(newPos.GetX(),newPos.GetX(),sp->GetWidth(),sp->GetHeight());

}

void Minion::Update(float dt){
	
	arc += MINION_VEL * dt;
	Vec2 offsetFromOrigin = Vec2(0,MINION_DISTANCE_FROM_CENTER).Rotate(arc);
	Vec2 newPos = center->box->Center() - Vec2(box->GetW()/2,box->GetH()/2) + offsetFromOrigin;			

	box->SetX(newPos.GetX());
	box->SetY(newPos.GetY());

}

void Minion::Render(){

	sp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),(arc * 180)/PI);

}

bool Minion::IsDead(){

	return(false);

}
void Minion::Shoot(Vec2 pos){

	float angle = std::atan2((box->Center() + Camera::pos).Distance(pos).GetY(),(box->Center() + Camera::pos).Distance(pos).GetX());
	Bullet* bullet = new Bullet(box->Center().GetX(),box->Center().GetY(),angle,BULLET_VEL,BULLET_REACH,std::string("img/minionbullet2.png"),true,3,0.1);
	Game::GetInstance()->GetState()->AddObject(bullet);

}

void Minion::NotifyCollision(GameObject& other){


	if(other.Is(std::string("Bullet")) && !(((Bullet&)other).TargetsPlayer())){

		((Alien*)center)->sumHP(-1);

	}

}

bool Minion::Is(std::string type){

	return(type == "Minion");

}