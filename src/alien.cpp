#include "alien.hpp"

Alien::Alien(float x,float y,int nMinions){

	sp = Sprite();
	//1)Setar box.Que box?
	//2)Inicializar outras variáveis.Com o quê?
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
		taskQueue.push(Action(Action::MOVE,InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY()));
		//Trata movimentacao da camera

	}
	if(!taskQueue.empty()){

		Action action = taskQueue.front();

		if(action.type == Action::MOVE){

			//vx =  std::abs(pos.GetX()
		}
		taskQueue.pop();

	}
}

void Alien::Render(){}
bool Alien::IsDead(){}

Alien::Action::Action(ActionType type,float x,float y){}