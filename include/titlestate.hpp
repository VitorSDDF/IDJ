#ifndef TITLE_STATE_HPP
#define TITLE_STATE_HPP

#include "state.hpp"
#include "stagestate.hpp"
#include "sprite.hpp"
#include "text.hpp"

class TitleState : public State{

	public:

		TitleState();
		void Update();
		void Render();
		void Pause();
		void Resume();
		void LoadAssets();

	private:

		Sprite bg;
		Text msg;

};

#endif