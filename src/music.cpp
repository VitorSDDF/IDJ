#include "music.hpp"

Music::Music(){

	music = nullptr;

}
Music::Music(std::string file){

	Open(file);
	
}

void Music::Play(int times){

	Mix_PlayMusic(music,times);

}

void Music::Stop(){

	Mix_FadeOutMusic(MUSIC_FADE_DOWN_TIME);
	
}

void Music::Open(std::string file){

	music = Resources::GetMusic(file);

}

bool Music::IsOpen(){

	return(music != nullptr);
	
}