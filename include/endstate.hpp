#ifndef END_STATE_HPP
#define END_STATE_HPP

#include "state.hpp"
#include "statedata.hpp"
#include "sprite.hpp"
#include "text.hpp"
#include "music.hpp"
#include "stagestate.hpp"

class EndState : public State{

	public:
		
		EndState(StateData stateData);
		void Update();
		void Render();
		void Pause();
		void Resume();

	private:

		Sprite bg;
		Music music;
		Text instruction;

};

#endif