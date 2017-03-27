#ifndef STATE_HPP
#define STATE_HPP

#include "sprite.hpp"

#include <stdlib.h>

#ifndef SPRITE_CLASS
class Sprite;
#endif

class State{

	public:

		State();
		bool QuitRequested();
		void LoadAssets();
		void Update();
		void Render();

	private:

		Sprite *bg;
		bool quitRequested;

};

#endif
