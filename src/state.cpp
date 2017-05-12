#include "state.hpp"

State::State(){

	bg = new Sprite();

    tileSet = new TileSet(64,64,std::string("img/tileset.png"));
    tileMap = new TileMap(std::string("map/tileMap.txt"),tileSet);

    Alien* alien = new Alien(512,300,4);
    objectArray.emplace_back(alien);

    Penguins* penguins = new Penguins(704,640);
    objectArray.emplace_back(penguins);
    Camera::Follow(penguins);

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

        if((objectArray[i].get())->IsDead()){

            std::vector<std::unique_ptr<GameObject>>::iterator it = objectArray.begin() + i;
            objectArray.erase(it);

        }

    }

    Camera::Update(Game::GetInstance()->GetDeltaTime());

    for(unsigned int i = 0;i < objectArray.size();i ++){

        if(!objectArray[i].get()->Is(std::string("Animation"))){
        
            for(unsigned int j = i + 1 ;j < objectArray.size();j ++){

                if(!objectArray[j].get()->Is(std::string("Animation"))){
                
                    if(Collision::IsColliding(*objectArray[i].get()->box,*objectArray[j].get()->box,objectArray[i].get()->rotation,objectArray[j].get()->rotation)){

                        objectArray[i].get()->NotifyCollision(*objectArray[j].get());

                    }
                }
            }
        }
    }
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