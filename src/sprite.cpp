#include "sprite.hpp"

Sprite::Sprite(){

	this->texture = nullptr;
	scaleX = 1.0;
	scaleY = 1.0;

}

Sprite::Sprite(std::string file){

	this->texture = nullptr;
	scaleX = 1.0;
	scaleY = 1.0;
	Open(file);	

}

Sprite::~Sprite(){

	

}

void Sprite::Open(std::string file){

	texture = Resources::GetImage(file);
	SDL_QueryTexture(texture,nullptr,nullptr,&width,&height);
	Sprite::SetClip(0,0,width,height);

}

void Sprite::SetClip (int x,int y,int w,int h){

	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;

}

void Sprite::SetScaleX(float scale){

	this->scaleX = scale;

}
void Sprite::SetScaleY(float scale){

	this->scaleY = scale;

}


void Sprite::Render(int x,int y,float angle){

	SDL_Rect dstrect;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w * scaleX;
	dstrect.h = clipRect.h * scaleY;
	
	if(Game::GetInstance()->GetRenderer() == nullptr){printf( "%s\t%d\t\n", __FILE__, __LINE__ );exit(1);}
	if(texture == nullptr){printf( "%s\t%d\t\n", __FILE__, __LINE__ );exit(1);}

	//SDL_RenderCopy(Game::GetInstance()->GetRenderer(),texture,&clipRect,&dstrect);
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), texture, &clipRect, &dstrect, angle,NULL, SDL_FLIP_NONE);

}

int Sprite::GetWidth(){

	return(width * scaleX);

}

int Sprite::GetHeight(){

	return(height * scaleY);

}

bool Sprite::IsOpen(){

	if(texture == nullptr){return(false);}

	return(true);

}
