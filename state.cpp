#include "state.hpp"

State::State(){

	bg = new Sprite();
	quitRequested = false;
	
}

State::~State(){

	objectArray.clear();

}

void State::Update(){

	if(SDL_QuitRequested()){quitRequested = true;}

	State::Input();

	for(unsigned int i = 0; i < objectArray.size();i++){

		if(objectArray[i].isDead()){

			iterator it = objectArray.begin() + i;
			objectArray.erase(it);

		}


	}

}

void State::Render(){

	bg->Render(0,0);

	for(unsigned int i = 0; i < objectArray.size();i++){

		objectArray[i].Render();

	}

}

bool State::QuitRequested(){return(quitRequested);}

void State::LoadAssets(){
	
	bg->Open(std::string("img/ocean.jpg"));

}

void State::AddObject(float X,float Y){

	Face *face = new Face(x,y);


}

void State::Input() {

    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

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

                if((Face*) objectArray[i]->box.IsInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    (Face*) objectArray[i]->Damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
            }
        }
        if(event.type == SDL_KEYDOWN) {
            // Se a tecla for ESC, setar a flag de quit
            if(event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                
                	float angle = rand() % 2 * PI;

					faceX = mouseX + (std::sin(angle) * HIPOTENUSA);
					faceY = mouseY + (std::cos(angle) * HIPOTENUSA);
	
					AddObject(float faceX,float faceY);

            }
        }
    }
}


