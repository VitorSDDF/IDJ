#include "sound.hpp"

Sound::Sound(){

	chunk = nullptr;

}
Sound::Sound(std::string file){

	Open(file);

}
void Sound::Play(int times){

	channel = Mix_PlayChannel(-1,chunk,times);

}
void Sound::Stop(){

	Mix_HaltChannel(channel);

}
void Sound::Open(std::string file){

	chunk = Resources::GetSound(file);

}
bool Sound::IsOpen(){

	return(chunk != nullptr);
}