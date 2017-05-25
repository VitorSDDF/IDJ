#include "text.hpp"

Text::Text(){}

Text::Text(std::string fontFile,int fontSize,TextStyle style,std::string text,SDL_Color color,int x,int y){

	this->texture = nullptr;
	this->text = text;
	this->style = style;
	this->fontSize = fontSize;
	this->color = color;
	box.SetX(x);
	box.SetY(y);
	font = Resources::GetFont(fontFile,fontSize);
	RemakeTexture();

}

Text::~Text(){

	if(texture != nullptr){SDL_DestroyTexture(texture);}

}

void Text::Render(int cameraX,int cameraY){

	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = cameraX;
	srcrect.y = cameraY;
	srcrect.w = box.GetW();
	srcrect.h = box.GetH();

	dstrect.x = box.GetX();
	dstrect.y = box.GetY();
	dstrect.w = box.GetW();
	dstrect.h = box.GetH();

	//std::cout << box.GetX() << " " <<box.GetY() << " " <<box.GetW() << " "<< box.GetH() << " " << std::endl;

	SDL_RenderCopy(Game::GetInstance()->GetRenderer(),texture,&srcrect,&dstrect);
	if(texture == nullptr){printf( "%s\t%d\t\n", __FILE__, __LINE__ );exit(1);}
}

void Text::SetPos(int x,int y,bool centerX,bool centerY){

	Vec2 window = Game::GetInstance()->GetWindowDimensions();
	
	if(centerX){box.SetX((window.GetX() - box.GetW())*0.5);}
	else{box.SetX(x);}

	if(centerY){box.SetY((window.GetY() - box.GetH())*0.5);}
	else{box.SetY(y);}

}
void Text::SetText(std::string text){

	this->text = text;
	RemakeTexture();

}
void Text::SetColor(SDL_Color color){

	this->color = color;
	RemakeTexture();

}
void Text::SetStyle(TextStyle style){

	this->text = style;
	RemakeTexture();

}
void Text::SetFontSize(int fontSize){

	this->fontSize = fontSize;
	RemakeTexture();

}
Vec2 Text::GetSize(){

	return(Vec2(box.GetW(),box.GetH()));

}

void Text::RemakeTexture(){
	int w,h;

	if(texture != nullptr){SDL_DestroyTexture(texture);}
	SDL_Surface* surface = TTF_RenderText_Blended(font,text.c_str(),color);
	if(surface == nullptr){SDL_Log("Unable to create surface in SDL: %s\n", SDL_GetError());}
	texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(),surface);
	if(surface == nullptr){SDL_Log("Unable to create texture from surface in SDL: %s\n", SDL_GetError());}
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture,nullptr,nullptr,&w,&h);
	box.SetW(w);
	box.SetH(h);

}