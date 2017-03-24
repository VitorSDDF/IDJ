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
	
	texture = IMG_LoadTexture(Game::GetInstance->GetRenderer(), const char* path);
	if(texture == nullptr){SDL_Log("Unable to load texture in SDL: %s\n", SDL_GetError());}

	SDL_QueryTexture(texture,nullptr,nullptr,&width,&height);
	setClip(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,widht,height);

}

void Sprite::SetClip (int x,int y,int w,int h){

	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;

	}

void Sprite::Render(int x,int y){

	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w;
	dstrect.h = clipRect.h;
	
	SDL_RenderCopy(Game::GetInstance->GetRenderer(),texture,srcrect,&dstrect);

}

int Sprite::GetWidth(){

	return(widht);
}

int Sprite::GetHeight(){

	return(height);

}

bool Sprite::IsOpen(){

	texture == nullptr ? return(false):return(true);

}
