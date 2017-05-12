#include "alien.hpp"

Alien::Alien(float x,float y,int nMinions){

	sp = new Sprite("img/alien.png");

	box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());

	hp = INITIAL_ALIEN_HP;
	arc = 0;
	moving = false;
	//Popular array de minions quando o alien estiver funcional
	for(int i = 0;i < nMinions; i++ ){

		minionArray.push_back(Minion(this,((2*PI)/nMinions) * i));

	}

}

Alien::~Alien(){}

void Alien::Update(float dt){

	arc -= ALIEN_ROTATION_VEL * dt;

	if(!moving){camera = Camera::pos;}

	if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){

		//Cria e enfileira ação de tiro registrando a posicao do mouse
		taskQueue.push(Action(Action::SHOOT,InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY()));

	}
	if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){

		//Cria e enfilera ação de movimento registrando a posicao do mouse
		taskQueue.push(Action(Action::MOVE,InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY()));
		//Trata movimentacao da camera

	}
	if(!taskQueue.empty()){

		Action action = taskQueue.front();
		float lastDistance = (camera + box->Center()).Distance(action.pos).Magnitude();

		if(action.type == Action::MOVE){

			speed = (box->Center() + camera).Distance(action.pos).Normalize() * ALIEN_VEL;

			if((speed * dt).Magnitude() >= lastDistance){

				box->SetX(action.pos.GetX() - camera.GetX() - (box->GetW()/2));
				box->SetY(action.pos.GetY() - camera.GetY() - (box->GetH()/2));
				moving = false;
				taskQueue.pop();

			}
			else{

				moving = true;
				box->SetX(box->Center().GetX() + (speed * dt).GetX() - box->GetW()/2);
				box->SetY(box->Center().GetY() + (speed * dt).GetY() - box->GetH()/2);

			}

		}
		else if(action.type == Action::SHOOT){

			float min_distance = std::numeric_limits<float>::max();
			unsigned int minion;

			for(unsigned int i = 0;i < minionArray.size();i++){

				if(min_distance > (minionArray[i].box->Center() + camera).Distance(action.pos).Magnitude()){

					min_distance = (minionArray[i].box->Center() + camera).Distance(action.pos).Magnitude();
					minion = i;

				}
			}

			minionArray[minion].Shoot(action.pos);
			taskQueue.pop();

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

Alien::Action::Action(ActionType type,float x,float y){

	this->type = type;
	pos = Vec2(x,y);

}

void Alien::NotifyCollision(GameObject& other){

	if(other.Is(std::string("Bullet")) && !(((Bullet&)other).TargetsPlayer())){

		hp --;

		if(IsDead()){

			Game::GetInstance()->GetState()->AddObject(new Animation(box->GetX(),box->GetY(),rotation * 180 / PI,"img/aliendeath.png",4,0.1,true));

		}

	}

}
bool Alien::Is(std::string type){

return(type == "Alien");

}

void Alien::sumHP(int delta){

	hp = hp + delta;

}

