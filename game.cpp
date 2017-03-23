#include "game.hpp"

Game& Game::m_pInstance = NULL;

Game& Game::GetInstance(std::string title,int witdh,int height){

	if (!m_pInstance){m_pInstance = new Game(title,witdh,height);}

		return m_pInstance;

}

Game& Game::GetInstance(){

	return m_pInstance;

}

Game::Game(std::string title,int witdh,int height){

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)){

        	SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());

    	}
	
	unsigned int bitmask = IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
	
	window =  SDL_CreateWindow("Game" ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,witdh,height,0);

	if(window == nullptr){SDL_Log("Unable to create window in SDL: %s\n", SDL_GetError());}

	renderer = *SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	if(renderer == nullptr){SDL_Log("Unable to render window in SDL: %s\n", SDL_GetError());}


}

~Game(){

	IMG_Quit();
	SDL_DestroyRenderer();
	SDL_DestroyWindow();
	SDL_Quit();

}

State& GetState(){

	return(this->state);

}

SDL_Renderer *GetRenderer(){

	return(this->renderer);

}

void Run(){

	while(!state.QuitRequested()){

		state.Update();
		state.Render();

		SDL_RenderPresent(this.renderer);

		SDL_Delay(33);

	}

}





