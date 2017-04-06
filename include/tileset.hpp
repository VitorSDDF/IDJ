#include "sprite.hpp"

class TileSet{

	public:

		TileSet(int tileWidth,int tileHeight,string file);
		void Render(unsigned int index,float x,float y);
		int GetTileWidth();
		int GetTileHeight();

	private:

­        Sprite tileSet;
­        int rows;
­        int columns;
­        int tileWidth;
­        int tileHeight;

};