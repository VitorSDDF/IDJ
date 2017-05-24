#include "alien.hpp"

int Alien::alienCount = 0;

Alien::Alien(float x,float y,int nMinions){

	sp = new Sprite("img/alien.png");

	box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());

	hp = INITIAL_ALIEN_HP;
	alienCount ++;
	arc = 0;
	state = RESTING;
	restTimer = Timer();
	for(int i = 0;i < nMinions; i++ ){

		minionArray.push_back(Minion(this,((2*PI)/nMinions) * i));

	}

}

Alien::~Alien(){

	alienCount --;

}

void Alien::Update(float dt){

	arc -= ALIEN_ROTATION_VEL * dt;

	if(Penguins::player == nullptr){return;}
	else if(state == RESTING){

		restTimer.Update(dt);
		if(restTimer.Get() > ALIEN_COOLDOWN){

			destination = Penguins::player->box->Center();
			speed = box->Center().Distance(destination).Normalize() * ALIEN_VEL;
			state = MOVING;

		}

	}
	else if(state == MOVING){

		float lastDistance = box->Center().Distance(destination).Magnitude();

		speed = box->Center().Distance(destination).Normalize() * ALIEN_VEL;

		if((speed * dt).Magnitude() >= lastDistance){

			box->SetX(destination.GetX() - (box->GetW()/2));
			box->SetY(destination.GetY() - (box->GetH()/2));

			float min_distance = std::numeric_limits<float>::max();
			unsigned int minion;

			Vec2 target = Penguins::player->box->Center();

			for(unsigned int i = 0;i < minionArray.size();i++){

				if(min_distance > minionArray[i].box->Center().Distance(target).Magnitude()){

					min_distance = minionArray[i].box->Center().Distance(target).Magnitude();
					minion = i;

				}
			}

			minionArray[minion].Shoot(target);
			
			restTimer.Restart();
			state = RESTING;

		}
		else{

			box->SetX(box->Center().GetX() + (speed * dt).GetX() - box->GetW()/2);
			box->SetY(box->Center().GetY() + (speed * dt).GetY() - box->GetH()/2);

		}

	}

	for(unsigned int i = 0;i < minionArray.size();i++){

		minionArray[i].Update(dt);

	}
}

void Alien::Render(){

	sp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),arc);
	//Chamar a renderização de cada Minion.
	for(unsigned int i = 0;i < minionArray.size();i++){

		minionArray[i].Render();

	}

}
bool Alien::IsDead(){

	return (hp <= 0);

}

void Alien::NotifyCollision(GameObject& other){

	if(other.Is(std::string("Bullet")) && !(((Bullet&)other).TargetsPlayer())){

		hp --;

		if(IsDead()){

			Sound explosao = Sound("audio/boom.wav");
			explosao.Play(1);
			Game::GetInstance()->GetCurrentState().AddObject(new Animation(box->GetX(),box->GetY(),rotation * 180 / PI,"img/aliendeath.png",4,0.1,true));

		}

	}

}
bool Alien::Is(std::string type){

return(type == "Alien");

}

void Alien::sumHP(int delta){

	hp = hp + delta;

}

