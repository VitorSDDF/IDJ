#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "game.hpp"

#include <unordered_map>

class Resources{

	public:
		
		static SDL_Texture* GetImage(std::string file);
		static void ClearImages();
		static Mix_Music* GetMusic(std::string file);
		static void ClearMusic();
		static void ClearSound();
		static Mix_Chunk* GetSound(std::string file);

	private:

		static std::unordered_map<std::string,SDL_Texture*> imageTable;
		static std::unordered_map<std::string,Mix_Music*> musicTable;
		static std::unordered_map<std::string,Mix_Chunk*> soundTable;
		Resources();

};
#endif