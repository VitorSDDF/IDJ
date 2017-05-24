#ifndef GAME
#define GAME

#include "game.hpp"
#include "state.hpp"
#include "stagestate.hpp"

#endif

int main (int argc, char** argv){

	Game::GetInstance(std::string("Vitor Silva de Deus - 11/0143574"),1024,600);

	Game::GetInstance()->Push(new StageState());

	Game::GetInstance()->Run();
	
	Game::DeleteInstance();
}
