#include "state.hpp"

State::State(){

	bg = new Sprite();
    tileSet = new TileSet(64,64,std::string("img/tileset.png"));
    tileMap = new TileMap(std::string("map/tileMap.txt"),tileSet);

	quitRequested = false;
	
}

State::~State(){

	objectArray.clear();

}

void State::Update(){

    Camera::Update(Game::GetInstance()->GetDeltaTime());
    
    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){

        quitRequested = true;

    }
    //Cria face ao se apertar espaço
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){

        //x’=x*cosθ ‐y*sinθ
        //y’=y*cosθ +x*sinθ

        float angle = (rand() % 6 + 1) ;

        float faceX = HIPOTENUSA * std::cos(angle);
        float faceY = HIPOTENUSA * std::sin(angle);

        AddObject(InputManager::GetInstance().GetMouseX() + faceX + PENGUIN_RADIX/2,
                  InputManager::GetInstance().GetMouseY() + faceY + PENGUIN_RADIX/2);

    }

	for(unsigned int i = 0; i < objectArray.size();i++){

        ((Face*) objectArray[i].get())->Update(Game::GetInstance()->GetDeltaTime());

		if(((Face *)objectArray[i].get())->IsDead()){

			std::vector<std::unique_ptr<GameObject>>::iterator it = objectArray.begin() + i;
			objectArray.erase(it);

		}


	}

}

void State::Render(){

	bg->Render(0,0);

    std::cout << Camera::pos.GetX() << " " << Camera::pos.GetY()<< std::endl;

    tileMap->Render(Camera::pos.GetX(),Camera::pos.GetY());
	for(unsigned int i = 0; i < objectArray.size();i++){

		((Face*) objectArray[i].get())->Render();

	}

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));

}

void State::AddObject(float x,float y){

	Face *face = new Face(x,y);
	objectArray.emplace_back(face);

}