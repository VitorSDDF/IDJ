#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "game.hpp"

#include <unordered_map>

class Resources{

	public:
		
		static SDL_Texture* GetImage(std::string file);
		static void ClearImages();

	private:

		static std::unordered_map<std::string,SDL_Texture*> imageTable;

		Resources();

};
#endif