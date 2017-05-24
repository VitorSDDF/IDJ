#include "tilestate.hpp"

TitleState::TitleState(){

	bg = Sprite();

}
void TileState::Update(){

	if(InputManager::GetInstance().QuitRequested()){

        quitRequested = true;

    }
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){

    	Game::GetInstance()->Push(new StageState());

    }
}
void TileState::Render(){

	bg->Render(0,0);

}
void TileState::Render(){}
void TileState::Pause(){}
void TileState::Resume(){}