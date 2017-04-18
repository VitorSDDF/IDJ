#include "state.hpp"

State::State(){

	bg = new Sprite();

    tileSet = new TileSet(64,64,std::string("img/tileset.png"));
    tileMap = new TileMap(std::string("map/tileMap.txt"),tileSet);

    Alien* alien = new Alien(512,300,0);
    objectArray.emplace_back(alien);

	quitRequested = false;
	
}

State::~State(){

	objectArray.clear();

}

void State::Update(){

    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){

        quitRequested = true;

    }

    Camera::Update(Game::GetInstance()->GetDeltaTime());
        
    ((Alien*) objectArray[0].get())->Update(Game::GetInstance()->GetDeltaTime());

}

void State::Render(){

	bg->Render(0,0);

    tileMap->Render(Camera::pos.GetX(),Camera::pos.GetY());
	((Alien*) objectArray[0].get())->Render();

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));

}