#include "stagestate.hpp"

StageState::~StageState(){

	//objectArray.clear();

}

StageState::StageState(){

	bg = new Sprite();

    tileSet = new TileSet(64,64,std::string("img/tileset.png"));
    tileMap = new TileMap(std::string("map/tileMap.txt"),tileSet);

    music = Music("audio/stageState.ogg");
    music.Play(-1);
    Alien* alien = new Alien(512,300,4);
    objectArray.emplace_back(alien);

    Penguins* penguins = new Penguins(704,640);
    objectArray.emplace_back(penguins);
    Camera::Follow(penguins);

}

void StageState::Update(){

    Camera::Update(Game::GetInstance()->GetDeltaTime());
    UpdateArray(Game::GetInstance()->GetDeltaTime());

    if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){

    	popRequested = true;

    }
}

void StageState::Render(){

    tileMap->RenderLayer(0,Camera::pos.GetX(),Camera::pos.GetY());
    RenderArray();
    tileMap->RenderLayer(1,Camera::pos.GetX(),Camera::pos.GetY());

    for(unsigned int i = 0;i < objectArray.size();i ++){

        if(!objectArray[i].get()->Is(std::string("Animation"))){
        
            for(unsigned int j = i + 1 ;j < objectArray.size();j ++){

                if(!objectArray[j].get()->Is(std::string("Animation"))){
                
                    if(Collision::IsColliding(*objectArray[i].get()->box,*objectArray[j].get()->box,objectArray[i].get()->rotation,objectArray[j].get()->rotation)){

                        objectArray[i].get()->NotifyCollision(*objectArray[j].get());
                        objectArray[j].get()->NotifyCollision(*objectArray[i].get());

                    }
                }
            }
        }
    }

}

void StageState::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));
	bg->Open(std::string("img/title.jpg"));

}

void StageState::Pause(){}
void StageState::Resume(){}