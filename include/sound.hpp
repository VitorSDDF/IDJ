#ifndef SOUND_HPP
#define SOUND_HPP

#include <iostream>
#include "SDL2/SDL_mixer.h"
#include "resources.hpp"

class Sound{

	public:

		Sound();
		Sound(std::string file);
		void Play(int times);
		void Stop();
		void Open(std::string file);
		bool IsOpen();

	private:

		Mix_Chunk* chunk;
		int channel;

};

#endif