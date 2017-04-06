#include "tilemap.h"

TileMap::TileMap(string file, TileSet* tileSet){

	Load(file);
	this->tileSet = tileSet;

}

void TileMap::SetTileSet(TileSet* tileSet){

	this-> tileSet = tileSet;

}

int& TileMap::At(int x,int y,int z){

	unsigned int index = (z * mapWidth * mapHeight) + (x * mapWidth + y);

	return &tileMatrix[index];

}

void TileMap::RenderLayer(int layer,int cameraX,int cameraY){

	int dx,dy,layerIndex;
	
	layerLenght = mapWidth * mapHeight;
	layerIndex = 0;

	for(unsigneg int i = (layer * layerLenght );i < ((layer * layerLenght) + layerLenght); i++){

		dx = (tileSet.getTileWidth() / mapWidth )* (i % mapWidth);
		dy = (tileSet.getTileHeight() / mapHeight ) * (i / mapHeight);
		
		tileSet->Render(i,dx,dy);

	}

}

void TileMap::Render(int cameraX,int cameraY){

	int dx,dy;

	for(unsigneg int i = 0;i < tileMatrix.size(); i++){

		dx = (tileSet.getTileWidth() / mapWidth )* (i % mapWidth) % tileSet.getTileWidth();
		dy = (tileSet.getTileHeight() / mapHeight ) * (i / mapHeight) % tileSet.getTileHeight();
		
		tileSet->Render(i,dx,dy);

	}

}

void TileMap::Load(string file){

	FILE *fp;
	tileAux

	fp = fopen(file.c_str(),"r");

	scanf("%d,%d,%d,\n\n", mapWidth,mapHeight,mapDepth);

	for(unsigned int i = 0;i < mapDepth;i ++){

		for(unsigned int j = 0;j < mapHeight;j ++){

			for(unsigned int k = 0;j < mapWidth;k ++){

				scanf("%d,", tileAux);
				tileMatrix.push_back(tileAux - 1);

			}

			fgetc(fp);

		}

		fgetc(fp);
		fgetc(fp);
		
	}

}

int TileMap::GetWidth(){

	return(mapWidth);

}

int TileMap::getHeight(){

	return(mapHeight);
	
}

int TileMap::GetDepth(){

	return(mapDepth);
	
}