#include "state.hpp"

State::~State(){

}
void State::LoadAssets(){

}

State::State(){

	quitRequested = false;
    popRequested = false;
	
}

bool State::QuitRequested(){return(quitRequested);}

bool State::PopRequested(){return(popRequested);}

void State::UpdateArray(float dt){

    for(unsigned int i = 0;i < objectArray.size();i ++){

        objectArray[i].get()->Update(dt);

        if((objectArray[i].get())->IsDead()){

            std::vector<std::unique_ptr<GameObject>>::iterator it = objectArray.begin() + i;
            objectArray.erase(it);

        }

    }

}

void State::RenderArray(){

    for(unsigned int i = 0;i < objectArray.size();i ++){
       
       objectArray[i].get()->Render();

    }

}

void State::AddObject(GameObject* ptr){

    objectArray.emplace_back(ptr);

}
