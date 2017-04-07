#include "tileset.hpp"

TileSet::TileSet(int tileWidth,int tileHeight,std::string file){

	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;

	tileSet = new Sprite(file);
	columns = tileSet->GetWidth()/tileWidth;
	rows = tileSet->GetHeight()/tileHeight;
}

void TileSet::Render(int index,float x,float y){

	if((index) >= 0 && (index < (rows * columns) - 1)){

		std:: cout << "indice:" <<index <<std::endl;
		std:: cout << "columns:" <<columns <<std::endl;

		int new_x = index % columns;
		int new_y = index / columns;

		tileSet->SetClip(new_x,new_y,tileWidth,tileHeight);
		tileSet->Render(x,y);
	}
}

int TileSet::GetTileWidth(){

	return(tileWidth);
}

int TileSet::GetTileHeight(){

	return(tileHeight);

}