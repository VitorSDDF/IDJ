#include "resources.hpp"

SDL_Texture* Resources::GetImage(file:string){
	
	std::unordered_map<std::string,SDL_Texture*>::const_iterator it;

	it = imageTable.find(file);

	if(it != nullptr){ return(it->second); }
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