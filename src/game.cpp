#include "game.hpp"

Game* Game::m_pInstance;

Game *Game::GetInstance(std::string title,int witdh,int height){

	if (!m_pInstance){m_pInstance = new Game(title,witdh,height);}

		return m_pInstance;

}

Game *Game::GetInstance(){

	if(nullptr == m_pInstance){

			printf("Aqui %s|%s:%d\n",__FILE__, __func__,__LINE__);

		}

	return m_pInstance;

}

void Game::DeleteInstance(){

	delete m_pInstance;

}

Game::Game(std::string title,int witdh,int height){

	//inicializa variaveis de classe
	frameStart = (int)SDL_GetTicks();
	dt = 0;
	storedState = nullptr;

	if(TTF_Init()){

		SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Unable to initialize TTF: %s\n", SDL_GetError());		

	}

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)){

        	SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Unable to initialize SDL: %s\n", SDL_GetError());

    	}
	Mix_Init​(MIX_INIT_MP3);

	if(Mix_OpenAudio​(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)){

		SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Unable to initialize SDL: %s\n", SDL_GetError());
			
	}

	unsigned int bitmask = IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
	
	window =  SDL_CreateWindow(title.c_str() ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,witdh,height,0);

	if(window == nullptr){SDL_Log("Unable to create window in SDL: %s\n", SDL_GetError());}

	renderer = SDL_CreateRenderer(window,-1, 0);

	if(renderer == nullptr){SDL_Log("Unable to render window in SDL: %s\n", SDL_GetError());}

	//Cria semente para a função rand() baseado no tempo corrente
	srand((unsigned)time(NULL));
	
}

 Game::~Game(){

 	TTF_Quit()
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	delete storedState;

	while(!stateStack.empty()){stateStack.pop();}

 }


State& Game::GetCurrentState(){

	return(*stateStack.top());

}

void Game::Push(State* state){

	storedState = state;

}

SDL_Renderer *Game::GetRenderer(){

	return(this->renderer);

}

void Game::CalculateDeltaTime(){

	int aux_time = frameStart;
	frameStart = (int)SDL_GetTicks();
	//TRansformando de segundos para milisegundos
	dt = (((float)(frameStart - aux_time)) / 1000.0f);

}

float Game::GetDeltaTime(){

	return(dt);

}

Vec2 Game::GetWindowDimensions(void){

	int w,h;

	SDL_GetWindowSize(window,&w,&h);

	Vec2 ret((float)w,(float)h);

	//retorna  um vetor de dimensão dois na qual a primeira é a largura e a segunda é a altura
	return ret;

}

void Game::Run(){

	if(storedState == nullptr){return;}
	stateStack.push(std::unique_ptr<State>(storedState));
	storedState = nullptr;

	while(!stateStack.top()->QuitRequested() && !stateStack.empty()){

		CalculateDeltaTime();

		stateStack.top()->LoadAssets();

		InputManager::GetInstance().Update();

		stateStack.top()->Update();
		
		stateStack.top()->Render();

		SDL_RenderPresent(this->renderer);

		if(stateStack.top().get()->PopRequested()){

			stateStack.pop();
			stateStack.top().get()->Resume();

		}
		if(storedState != nullptr){

			stateStack.top().get()->Pause();
			stateStack.push(std::unique_ptr<State>(storedState));
			storedState = nullptr;

		}

		SDL_Delay(33);

	}

	Resources::ClearImages();

}





