#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "state.hpp"
#include "inputmanager.hpp"
#include "vec2.hpp"
#include "resources.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

class State;

class Game{

	public:

   		static Game *GetInstance(std::string title,int witdh,int height);
   		static void DeleteInstance();
		~Game();
		void Run();
		SDL_Renderer *GetRenderer();
		State& GetCurrentState();
		static Game *GetInstance();
		void Push(State* state);
		float GetDeltaTime();
		Vec2 GetWindowDimensions(void);

	private:

		Game(std::string title,int witdh,int height);

   		Game& operator=(Game const&);

   		void CalculateDeltaTime();

   		static Game *m_pInstance;
		SDL_Window *window;
		SDL_Renderer *renderer;
		State* storedState;
		std::stack<std::unique_ptr<State>> stateStack;

		int frameStart;
		float dt;

};

#endif