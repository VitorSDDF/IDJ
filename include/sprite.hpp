#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "game.hpp"
class Game;

#include <string>

#define SPRITE_CLASS
class Sprite{

	public:

		Sprite();
		Sprite(std::string file);
		~Sprite();

		void Open(std::string file);
		void SetClip(int x,int y,int w,int h);
		void Render(int x,int y);
		int GetWidth();
		int GetHeight();
		bool IsOpen();

	private:

		SDL_Texture *texture;
		int width;
		int height;
		SDL_Rect clipRect;

};

#endif