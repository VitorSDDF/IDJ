#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "state.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class State;

class Game{

	public:

   		static Game *GetInstance(std::string title,int witdh,int height);
   		static void DeleteInstance();
		~Game();
		void Run();
		SDL_Renderer *GetRenderer();
		State *GetState();
		static Game *GetInstance();
		void SetState(State* state);

	private:

		Game(std::string title,int witdh,int height);

   		Game& operator=(Game const&);

   		static Game *m_pInstance;
		SDL_Window *window;
		SDL_Renderer *renderer;
		State *state;

};

#endif
