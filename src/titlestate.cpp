#include "titlestate.hpp"

TitleState::TitleState(){

	bg = Sprite();
	msg = Text("font/Call me maybe.ttf",10,Text::BLENDED,std::string("Press space to start game"),{255, 255, 255, 255},0,0);
	Vec2 pos = Game::GetInstance()->GetWindowDimensions();
	msg.SetPos(0, pos.GetY() - msg.GetSize().GetY(), true);

}
void TitleState::Update(){

	if(InputManager::GetInstance().QuitRequested()){

        quitRequested = true;

    }
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){

    	Game::GetInstance()->Push(new StageState());

    }
}

void TitleState::Render(){

	bg.Render(0,0);	
	msg.Render(0,0);

}

void TitleState::LoadAssets(){

	bg.Open(std::string("img/title.jpg"));

}

void TitleState::Pause(){}
void TitleState::Resume(){}