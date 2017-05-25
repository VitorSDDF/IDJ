#ifndef TEXT_HPP
#define TEXT_HPP

#include "SDL2/SDL_ttf.h"
#include "resources.hpp"
#include "rect.hpp"
#include "SDL2/SDL.h"
#include <iostream>

class Text{

	public:

		enum TextStyle{SOLID,SHADED,BLENDED} textStyle;
		Text();
		Text(std::string fontFile,int fontSize,TextStyle style,std::string text,SDL_Color color,int x = 0,int y = 0);

		~Text();
		void Render(int cameraX = 0,int cameraY = 0);
		void SetPos(int x,int y,bool centerX = false,bool centerY = false);
		void SetText(std::string text);
		void SetColor(SDL_Color color);
		void SetStyle(TextStyle style);
		void SetFontSize(int fontSize);
		Vec2 GetSize();

	private:

		void RemakeTexture();
		TTF_Font* font;
		SDL_Texture* texture;
		std::string text;
		TextStyle style;
		int fontSize;
		SDL_Color color;
		Rect box;

};

#endif