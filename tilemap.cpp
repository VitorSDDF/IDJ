#include "tilemap.hpp"

TileMap::TileMap(std::string file, TileSet* tileSet){

	Load(file);
	this->tileSet = tileSet;

}

void TileMap::SetTileSet(TileSet* tileSet){

	this-> tileSet = tileSet;

}

int& TileMap::At(int x,int y,int z){

	int index = (z * mapWidth * mapHeight) + (x * mapWidth + y);

	return tileMatrix.at(index);

}

void TileMap::RenderLayer(int layer,int cameraX,int cameraY){

	unsigned int dx,dy;

	for(int x = 0;x < mapWidth; x++){

		for(int y = 0;y < mapHeight; y++){

			dx = tileSet->GetTileWidth() * x;
			dy = tileSet->GetTileHeight() * y;
		
			tileSet->Render(At(x,y,layer),dx,dy);

		}

	}

}

void TileMap::Render(int cameraX,int cameraY){

	for(int layer = 0;layer < mapDepth; layer++){

		RenderLayer(layer,0,0);

	}

}

void TileMap::Load(std::string file){

	FILE *fp;
	int tileAux;

	fp = fopen(file.c_str(),"r");

	fscanf(fp,"%d,%d,%d,", &mapWidth,&mapHeight,&mapDepth);
	std::cout << mapWidth <<' ' << mapHeight <<' ' << mapDepth<< std::endl;
	for(int i = 0;i < mapDepth;i ++){

		for(int j = 0;j < mapHeight;j ++){

			for(int k = 0;k < mapWidth;k ++){

				fscanf(fp,"%d,",&tileAux);
				tileMatrix.push_back(tileAux - 1);
				std::cout << tileAux <<'\t';
			}
			std::cout <<std::endl;

		}
		std::cout <<std::endl;
		
	}

}

int TileMap::GetWidth(){

	return(mapWidth);

}

int TileMap::GetHeight(){

	return(mapHeight);
	
}

int TileMap::GetDepth(){

	return(mapDepth);
	
}