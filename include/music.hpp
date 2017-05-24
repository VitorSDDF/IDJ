#ifndef MUSIC_HPP
#define MUSIC_HPP

#define MUSIC_FADE_DOWN_TIME 3000

#include <iostream>
#include "SDL2/SDL_mixer.h"
#include "resources.hpp"

class Music{

	public:

		Music();
		Music(std::string file);
		void Play(int times);
		void Stop();
		void Open(std::string file);
		bool IsOpen();

	private:

		Mix_Music* music;

};

#endif