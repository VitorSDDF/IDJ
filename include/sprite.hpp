#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "game.hpp"
#include "resources.hpp"

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
		void Render(int x,int y,float angle = 0);
		int GetWidth();
		int GetHeight();
		bool IsOpen();
		void SetScaleX(float scale);
		void SetScaleY(float scale);

	private:

		SDL_Texture *texture;
		int width;
		int height;
		SDL_Rect clipRect;

		float scaleX;
		float scaleY;

};

#endif