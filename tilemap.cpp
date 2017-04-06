#include "tilemap.hpp"

TileMap::TileMap(std::string file, TileSet* tileSet){

	Load(file);
	this->tileSet = tileSet;

}

void TileMap::SetTileSet(TileSet* tileSet){

	this-> tileSet = tileSet;

}

int& TileMap::At(int x,int y,int z){

	unsigned int index = (z * mapWidth * mapHeight) + (x * mapWidth + y);

	return tileMatrix.at(index);

}

void TileMap::RenderLayer(int layer,int cameraX,int cameraY){

	unsigned int dx,dy;
	
	unsigned int layerLenght = mapWidth * mapHeight;

	for(unsigned int i = (layer * layerLenght );i < ((layer * layerLenght) + layerLenght); i++){

		dx = (tileSet->GetTileWidth() / mapWidth )* (i % mapWidth);
		dy = (tileSet->GetTileHeight() / mapHeight ) * (i / mapHeight);
		
		tileSet->Render(i,dx,dy);

	}

}

void TileMap::Render(int cameraX,int cameraY){

	int dx,dy;

	for(unsigned int i = 0;i < tileMatrix.size(); i++){

		dx = (tileSet->GetTileWidth() / mapWidth )* (i % mapWidth) % tileSet->GetTileWidth();
		dy = (tileSet->GetTileHeight() / mapHeight ) * (i / mapHeight) % tileSet->GetTileHeight();
		
		tileSet->Render(i,dx,dy);

	}

}

void TileMap::Load(std::string file){

	FILE *fp;
	int tileAux;

	fp = fopen(file.c_str(),"r");

	scanf("%d,%d,%d,\n\n", &mapWidth,&mapHeight,&mapDepth);

	for(unsigned int i = 0;i < mapDepth;i ++){

		for(unsigned int j = 0;j < mapHeight;j ++){

			for(unsigned int k = 0;j < mapWidth;k ++){

				scanf("%d,",&tileAux);
				tileMatrix.push_back(tileAux - 1);

			}

			fgetc(fp);

		}

		fgetc(fp);
		fgetc(fp);
		
	}

}

unsigned int TileMap::GetWidth(){

	return(mapWidth);

}

unsigned int TileMap::GetHeight(){

	return(mapHeight);
	
}

unsigned int TileMap::GetDepth(){

	return(mapDepth);
	
}