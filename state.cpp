#include "state.hpp"

State::State(){

	bg = new Sprite();
	quitRequested = false;

}

void State::Update(){

	if(SDL_QuitRequested()){quitRequested = true;}

}

void State::Render(){

	bg->Render(0,0);

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));

}


