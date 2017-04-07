#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "tileset.hpp"
#include <stdio.h>

#ifndef TILESET_CLASS

class TileSet;

#endif

#define TILEMAP_CLASS

class TileMap{

	public:

		TileMap(std::string file, TileSet* tileSet);

		void Load(std::string file);
		void SetTileSet(TileSet* tileSet);
	    int& At(int x,int y,int z);
		void Render(int cameraX,int cameraY);
		void RenderLayer(int layer,int cameraX,int cameraY);
		int GetWidth();
		int GetHeight();
		int GetDepth ();

	private:

		std::vector<int> tileMatrix;
		TileSet* tileSet;
		int mapWidth;
		int mapHeight;
		int mapDepth;

};

#endif