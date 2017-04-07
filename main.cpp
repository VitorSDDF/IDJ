#ifndef GAME
#define GAME

#include "game.hpp"
#include "state.hpp"

#endif

int main (int argc, char** argv){

	Game::GetInstance(std::string("Vitor Silva de Deus - 11/0143574"),1024,600);

	State* gameState = new State();

	Game::GetInstance()->SetState(gameState);

	Game::GetInstance()->Run();
	
	Game::DeleteInstance();
}
