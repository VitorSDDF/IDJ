#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "state.hpp"
#include <string>

class Game{

	public:

   		static Game *GetInstance(char title[],int witdh,int height);
		~Game();
		void Run();
		SDL_Renderer *GetRenderer();
		State *GetState();
		static Game *GetInstance();

	private:

		Game(char title[],int witdh,int height);

   		Game& operator=(Game const&);

   		static Game *m_pInstance;
		SDL_Window *window;
		SDL_Renderer *renderer;
		State *state;

};

