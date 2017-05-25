#include "endstate.hpp"

EndState::EndState(StateData stateData){

	if(stateData.playerVictory){

		bg.Open(std::string("img/win.jpg"));
		music = Music("audio/endStateWin.ogg");
    
	}
	else{

		bg.Open(std::string("img/lose.jpg"));
		music = Music("audio/endStateWin.ogg");
	}

	music.Play(-1);
	instruction = Text("font/Call me maybe.ttf",10,Text::BLENDED,std::string("Pressione ESC para ir ao menu, ou espaço para tentar de novo"),{255, 255, 255, 255},0,0);
	Vec2 pos = Game::GetInstance()->GetWindowDimensions();
	instruction.SetPos(0, pos.GetY() - instruction.GetSize().GetY(), true);
	
}
void EndState::Update(){

	if(InputManager::GetInstance().QuitRequested()){

        quitRequested = true;

    }
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){

    	Game::GetInstance()->Push(new StageState());

    }
    if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){

    	popRequested = true;

    }
		

}
void EndState::Render(){

	bg.Render(0,0);
	instruction.Render(0,0);

}
void EndState::Pause(){}
void EndState::Resume(){}