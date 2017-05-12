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

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)){

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

	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

State *Game::GetState(){

	return(this->state);

}

SDL_Renderer *Game::GetRenderer(){

	return(this->renderer);

}

void Game::SetState(State* state){

	this->state = state;

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

	state = new State();

	while(!state->QuitRequested()){

		CalculateDeltaTime();

		state->LoadAssets();

		InputManager::GetInstance().Update();

		state->Update();
		
		state->Render();

		SDL_RenderPresent(this->renderer);

	}

}





