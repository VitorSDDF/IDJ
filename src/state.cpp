#include "state.hpp"

State::State(){

	bg = new Sprite();

    tileSet = TileSet::TileSet(64,64,std::string("img/tileset.png"));
    tileMap = TileMap::TileMap(std::string("map/tileMap.txt",&tileSet));

	quitRequested = false;
	
}

State::~State(){

	objectArray.clear();

}

void State::Update(){

	if(SDL_QuitRequested()){quitRequested = true;}

	State::Input();

	for(unsigned int i = 0; i < objectArray.size();i++){

		//std::cout <<"Damage:" << ((Face *)objectArray[i].get())->getHitpoints() << std::endl;

		if(((Face *)objectArray[i].get())->IsDead()){

			std::cout << objectArray.size() << std::endl;
			std::vector<std::unique_ptr<GameObject>>::iterator it = objectArray.begin() + i;
			objectArray.erase(it);
			std::cout <<"Entrou is dead" << std::endl;
			std::cout << objectArray.size() << std::endl;

		}


	}

}

void State::Render(){

	bg->Render(0,0);

    TileMap.Render(0,0);

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

void State::Input() {

    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);
    //std::cout <<"Mouse" << mouseX << ' ' << mouseY <<std::endl;

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            quitRequested = true;
        }
        
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {

                if(((Face*) objectArray[i].get())->box->IsInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    ((Face*) objectArray[i].get())->Damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    std::cout <<"Entrou damage" << std::endl;
                    std::cout <<"Mouse " << mouseX << ' ' << mouseY <<std::endl;
                    std::cout <<"Box " << ((Face*)objectArray[i].get())->box->x << ' ' << ((Face*)objectArray[i].get())->box->y <<std::endl;

                    break;
                }
            }
        }
        if(event.type == SDL_KEYDOWN){

            // Se a tecla for ESC, setar a flag de quit
            if(event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                	
                	//x’=x*cosθ ‐y*sinθ
					//y’=y*cosθ +x*sinθ

                	float angle = (rand() % 6 + 1) ;

					float faceX = HIPOTENUSA * std::cos(angle);
            		float faceY = HIPOTENUSA * std::sin(angle);

					//std::cout <<"Mouse" << mouseX << ' ' << mouseY <<std::endl;
					//std::cout <<"Face" <<faceX << ' ' << faceY <<std::endl;
	
					AddObject(mouseX + faceX + PENGUIN_RADIX/2,mouseY + faceY + PENGUIN_RADIX/2);

            }
        }
    }
}


