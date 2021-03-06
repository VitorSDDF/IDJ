#include "resources.hpp"

std::unordered_map<std::string,SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string,Mix_Music*> Resources::musicTable;
std::unordered_map<std::string,Mix_Chunk*> Resources::soundTable;
std::unordered_map<std::string,TTF_Font*> Resources::fontTable;

SDL_Texture* Resources::GetImage(std::string file){
	
	std::unordered_map<std::string,SDL_Texture*>::const_iterator it;

	it = imageTable.find(file);

	if(it != imageTable.end()){ return(it->second); }
	else{


		SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(),file.c_str());
		
		if(texture == nullptr){

			SDL_Log("Unable to load texture in SDL: %s\n", SDL_GetError());
			exit(1);

		}

		imageTable.emplace(file,texture);
		
		return(texture);
		
	}

}

void Resources::ClearImages(){

	std::unordered_map<std::string,SDL_Texture*>::const_iterator it;

	for(it = imageTable.begin();it != imageTable.end();it ++){

		SDL_DestroyTexture(it->second);

	}

	imageTable.clear();

}

Mix_Music* Resources::GetMusic(std::string file){

	std::unordered_map<std::string,Mix_Music*>::const_iterator it;

	it = musicTable.find(file);

	if(it != musicTable.end()){return(it->second);}
	else{

		Mix_Music* music = Mix_LoadMUS(file.c_str());

		if(music == nullptr){

			SDL_Log("Unable to load music in SDL: %s\n", SDL_GetError());
			exit(1);

		}

		musicTable.emplace(file,music);
		
		return(music);
		
	}

}

void Resources::ClearMusic(){

	std::unordered_map<std::string,Mix_Music*>::const_iterator it;

	for(it = musicTable.begin();it != musicTable.end();it ++){

		Mix_FreeMusic(it->second);

	}

	musicTable.clear();

}

Mix_Chunk* Resources::GetSound(std::string file){

	std::unordered_map<std::string,Mix_Chunk*>::const_iterator it;

	it = soundTable.find(file);

	if(it != soundTable.end()){return(it->second);}
	else{

		Mix_Chunk* sound = Mix_LoadWAV(file.c_str());

		if(sound == nullptr){

			SDL_Log("Unable to load music in SDL: %s\n", SDL_GetError());
			exit(1);

		}

		soundTable.emplace(file,sound);
		
		return(sound);
		
	}

}

void Resources::ClearSound(){

	std::unordered_map<std::string,Mix_Chunk*>::const_iterator it;

	for(it = soundTable.begin();it != soundTable.end();it ++){

		Mix_FreeChunk(it->second);

	}

	soundTable.clear();

}

void Resources::ClearFont(){

	std::unordered_map<std::string,TTF_Font*>::const_iterator it;

	for(it = fontTable.begin();it != fontTable.end();it ++){

		TTF_CloseFont(it->second);

	}

	fontTable.clear();

}

TTF_Font* Resources::GetFont(std::string file,int fontSize){

	std::unordered_map<std::string,TTF_Font*>::const_iterator it;

	it = fontTable.find(file + std::to_string(fontSize));

	if(it != fontTable.end()){return(it->second);}
	else{

		TTF_Font* font = TTF_OpenFont(file.c_str(),fontSize);

		if(font == nullptr){

			SDL_Log("Unable to load font in SDL: %s\n", SDL_GetError());
			exit(1);

		}

		fontTable.emplace(file + std::to_string(fontSize),font);
		
		return(font);
		
	}

}
