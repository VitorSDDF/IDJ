#include "resources.hpp"

std::unordered_map<std::string,SDL_Texture*> Resources::imageTable;

SDL_Texture* Resources::GetImage(std::string file){
	
	std::unordered_map<std::string,SDL_Texture*>::const_iterator it;

	it = imageTable.find(file);

	if(it != imageTable.end()){ return(it->second); }
	else{

		std::cout <<"it == imageTable.end()" << std::endl;

		SDL_Renderer *renderer = Game::GetInstance()->GetRenderer();
		SDL_Texture* texture = IMG_LoadTexture(renderer,file.c_str());
		
		std::cout <<"Carregou textura" << std::endl;		
		if(texture == nullptr){

			SDL_Log("Unable to load texture in SDL: %s\n", SDL_GetError());
			exit(1);

		}

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