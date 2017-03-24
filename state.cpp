#include "state.hpp"

State::State(){

}

void State::Update(){

	if(SDL_QuitRequested()){quitRequested = true;}

}

void State::Render(){

	bg.render();

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){}


