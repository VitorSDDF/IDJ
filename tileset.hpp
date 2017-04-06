#ifndef TILESET_HPP
#define TILESET_HPP

#include "sprite.hpp"

#ifndef SPRITE_CLASS
class Sprite;
#endif

#define TILESET_CLASS
class TileSet{

	public:

		TileSet(int tileWidth,int tileHeight,std::string file);
		void Render(unsigned int index,float x,float y);
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