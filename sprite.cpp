#include "sprite.hpp"

Sprite::Sprite(){

	this->texture = nullptr;

}

Sprite::Sprite(std::string file){

	this->texture = nullptr;
	Open(file);	

}

Sprite::~Sprite(){

	SDL_DestroyTexture(this->texture);

}

void Sprite::Open(std::string file){

	if(texture != nullptr){
	
		 SDL_DestroyTexture(texture);

	}
	
	texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(),file.c_str());
	if(texture == nullptr){SDL_Log("Unable to load texture in SDL: %s\n", SDL_GetError());
							exit(1);}
	SDL_QueryTexture(texture,nullptr,nullptr,&width,&height);

	Sprite::SetClip(0,0,width,height);

}

void Sprite::SetClip (int x,int y,int w,int h){

	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;

	}

void Sprite::Render(int x,int y){

	SDL_Rect srcrect;
	SDL_Rect dstrect;

	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = width;
	dstrect.y = height;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w;
	dstrect.h = clipRect.h;
	
	if(Game::GetInstance()->GetRenderer() == nullptr){printf( "%s\t%d\t\n", __FILE__, __LINE__ );exit(1);}
	if(texture == nullptr){printf( "%s\t%d\t\n", __FILE__, __LINE__ );exit(1);}

	SDL_RenderCopy(Game::GetInstance()->GetRenderer(),texture,&srcrect,&dstrect);

}

int Sprite::GetWidth(){

	return(width);
}

int Sprite::GetHeight(){

	return(height);

}

bool Sprite::IsOpen(){

	if(texture == nullptr){return(false);}

	return(true);

}
