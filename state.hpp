#include "sprite.hpp"

class State{

	public:
		State();
		bool QuitRequested();
		void LoadAssets();
		void Update(float dt);
		void Render();
	private:

		Sprite bg;
		bool quitRequested;

};
