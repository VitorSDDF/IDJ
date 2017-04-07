#include "tileset.hpp"

class TileMap{

	public:

		TileMap(string file, TileSet* tileSet);

		void Load(string file);
		void SetTileSet(TileSet* tileSet);
	    int& At(int x,int y,int z);
		void Render(int cameraX,int cameraY);
		void RenderLayer(int layer,int cameraX,int cameraY);
		int GetWidth();
		int GetHeight();
		int GetDepth ();

	private:

	­    std::vector<int> tileMatrix;
	­    TileSet* tileSet;
	­    int mapWidth;
	­    int mapHeight;
	­    int mapDepth;

};