#include "inputmanager.hpp"

InputManager::InputManager(){

	for(unsigned int i = 0;i < 6;i ++){

		mouseState[i] = false;
		mouseUpdate[i] = 0;

	}
	
	quitRequested = false;
	updateCounter = 0;
	mouseX = 0;
	mouseY = 0;

}

InputManager::~InputManager(){}

InputManager& InputManager::GetInstance(){

	static InputManager instance;

	return(instance);

}



void InputManager::Update(){

	SDL_Event event;

    updateCounter ++;
    quitRequested = false;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)){

        // Se o evento for quit, setar a flag para terminação

        if(event.type == SDL_QUIT){

            quitRequested = true;

        }
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN){

        	 mouseState[event.button.button] = true;
        	 mouseUpdate[event.button.button] = updateCounter;
            
        }
        if(event.type == SDL_MOUSEBUTTONUP ) {
            
            mouseState[event.button.button] = false;

        }
        if(event.type == SDL_KEYDOWN){

			keyState[event.key.keysym.sym] = true;
	        keyUpdate[event.key.keysym.sym] = updateCounter;

        }
        if(event.type == SDL_KEYUP){

        	keyState[event.key.keysym.sym] = false;

        }
    }
}

bool InputManager::KeyPress(int key){

  try{return(keyUpdate.at(key) == updateCounter);}
  catch (const std::out_of_range& oor){}
  return false;

}

bool InputManager::KeyRelease(int key){

	try{return(keyUpdate.at(key) != updateCounter);}
  	catch (const std::out_of_range& oor){}
  	return false;
	

}

bool InputManager::IsKeyDown(int key){

	return(keyState.at(key) == true);

}

bool InputManager::MousePress(int button){

	return(mouseUpdate[button] == updateCounter);

}

bool InputManager::MouseRelease(int button){

	return(mouseUpdate[button] != updateCounter);

}
bool InputManager::IsMouseDown(int button){

	return(mouseState[button] == true);

}

int InputManager::GetMouseX(){

	return(mouseX);

}
int InputManager::GetMouseY(){

	return(mouseY);

}
bool InputManager::QuitRequested(){

	return(quitRequested);

}


