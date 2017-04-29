#include "state.hpp"

State::State(){

	bg = new Sprite();

    tileSet = new TileSet(64,64,std::string("img/tileset.png"));
    tileMap = new TileMap(std::string("map/tileMap.txt"),tileSet);

    Alien* alien = new Alien(512,300,4);
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
    
    for(unsigned int i = 0;i < objectArray.size();i ++){

        objectArray[i].get()->Update(Game::GetInstance()->GetDeltaTime());

    }

    Camera::Update(Game::GetInstance()->GetDeltaTime());

}

void State::Render(){

	bg->Render(0,0);

    tileMap->Render(Camera::pos.GetX(),Camera::pos.GetY());

    for(unsigned int i = 0;i < objectArray.size();i ++){
	   
       objectArray[i].get()->Render();

    }

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));

}

void State::AddObject(GameObject* ptr){

    objectArray.emplace_back(ptr);

}