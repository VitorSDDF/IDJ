#include "tileset.hpp"

TileSet::TileSet(int tileWidth,int tileHeight,std::string file){

	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;

	tileSet->Open(file);
	std::cout <<"rodou tileSet->Open(file)" << std::endl;
	columns = tileSet->GetWidth()/tileWidth;
	rows = tileSet->GetHeight()/tileHeight;
}

void TileSet::Render(unsigned int index,float x,float y){

	if((index) >= 0 && (index < (rows * columns) - 1)){

		tileSet->SetClip(x,y,tileWidth,tileHeight);
	
	}
}

int TileSet::GetTileWidth(){

	return(tileWidth);
}

int TileSet::GetTileHeight(){

	return(tileHeight);

}