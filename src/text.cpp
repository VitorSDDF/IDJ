#include "text.hpp"

Text::Text(std::string fontFile,int fontSize,TextStyle style,std::string text,SDL_Color color,int x,int y){}

Text::~Text(){}
void Text::Render(int cameraX,int cameraY){}
void Text::SetPos(int x,int y,bool centerX,bool centerY){}
void Text::SetText(std::string text){}
void Text::SetColor(SDL_Color color){}
void Text::SetStyle(TextStyle style){}
void Text::SetFontSize(int fontSize){}

void Text::RemakeTexture(){}