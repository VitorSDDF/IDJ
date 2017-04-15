#ifndef TILESET_HPP
#define TILESET_HPP

#include "sprite.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#ifndef SPRITE_CLASS
class Sprite;
#endif

#define TILESET_CLASS
class TileSet{

	public:

		TileSet(int tileWidth,int tileHeight,std::string file);
		void Render(int index,float x,float y);
		int GetTileWidth();
		int GetTileHeight();

	private:

		Sprite *tileSet;
		
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;

};

#endif