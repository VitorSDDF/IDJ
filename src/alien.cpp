#include "alien.hpp"

Alien::Alien(float x,float y,int nMinions){

	sp = new Sprite("img/alien.png");

	box = new Rect(x,y,sp->GetWidth(),sp->GetHeight());

	hp = INITIAL_ALIEN_HP;
	//3)Popular array de minions quando o alien estiver funcional
}

Alien::~Alien(){}

void Alien::Update(float dt){

	if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){

		//Cria e enfileira ação de tiro registrando a posicao do mouse
		taskQueue.push(Action(Action::SHOOT,InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY()));

	}
	if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){

		//Cria e enfilera ação de movimento registrando a posicao do mouse
		std::cout <<"MOVE" << std::endl;
		taskQueue.push(Action(Action::MOVE,InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY()));
		std::cout << taskQueue.size() << std::endl;
		//Trata movimentacao da camera

	}
	if(!taskQueue.empty()){

		Action action = taskQueue.front();
		float lastDistance = (action.pos - box->Center()).Magnitude();

		if(action.type == Action::MOVE){

			speed =  box->Center().Distance(action.pos) * (1.0/(dt));

			//std::cout << "SpeedX: "<< speed.GetX() << std::endl;
			//std::cout << "SpeedY: "<< speed.GetY() << std::endl;

			if((speed * (dt)).Magnitude() > lastDistance){

				box->SetX(action.pos.GetX() - (box->GetW()/2));
				box->SetY(action.pos.GetY() - (box->GetH()/2));
				taskQueue.pop();
				std::cout <<"Retirou" << std::endl;

			}
			else{

				box->SetX((box->Center() + (speed * dt)).GetX() - (box->GetH()/2));
				box->SetY((box->Center() + (speed * dt)).GetY() - (box->GetH()/2));

			}

		}
		else if(action.type == Action::SHOOT){
		
			taskQueue.pop();

		}

	}
}

void Alien::Render(){

	//Tratar movimentacao da camera
	sp->Render(box->GetX(),box->GetY());
	//Chamar a renderização de cada Minion.

}
bool Alien::IsDead(){

	return (hp <= 0);

}

Alien::Action::Action(ActionType type,float x,float y){

	this->type = type;
	pos = Vec2(x,y);

}