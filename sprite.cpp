#include "sprite.hpp"

Sprite(){

	this->texture = nullptr;

}

Sprite(String file){

	this->texture = nullptr;
	Open(file);	

}

~Sprite(){

	SDL_DestroyTexture(this->texture);

}

void Open(String file){

	if(texture != nullptr){
	
		 SDL_DestroyTexture(texture);

	}
	
	texture = IMG_LoadTexture(Game::GetInstance->GetRenderer(), const char* path);
	if(texture == nullptr){SDL_Log("Unable to load texture in SDL: %s\n", SDL_GetError());}

	SDL_QueryTexture(texture,nullptr,nullptr,&width,&height);
	setClip(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,widht,height);

}

void SetClip (int x,int y,int w,int h){

	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;

	}

void Render(int x,int y){

	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w;
	dstrect.h = clipRect.h;
	
	SDL_RenderCopy(Game::GetInstance->GetRenderer(),texture,srcrect,&dstrect);

}

int GetWidth(){

	return(widht);
}

int GetHeight(){

	return(height);

}

bool IsOpen(){

	texture == nullptr ? return(false):return(true);

}
