#include "face.hpp"

Face::Face(float x,float y){

	sp = new Sprite();
	sp->Open(std::string("img/penguinface.png"));

	hitpoints = PENGUIN_INITIAL_HITPOINTS;
	box = new Rect(x,y,2*PENGUIN_RADIX,2*PENGUIN_RADIX);

}

void Face::Damage(int damage){

	hitpoints -= damage;

}

int Face::getHitpoints(){

	return(hitpoints);

}

void Face::Update(float dt){

	// Se o houver clique...
    if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){

    		float x = InputManager::GetInstance().GetMouseX();
    		float y = InputManager::GetInstance().GetMouseY();

            if(box->IsInside(x,y)){Damage(rand() % 10 + 10);}
           
    
    }

}

void Face::Render(){

	sp->Render(box->getX(),box->getY());

}

bool Face::IsDead(){

	if(hitpoints <= 0){return (true);}

	return(false);

}