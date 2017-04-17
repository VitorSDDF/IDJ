#include "camera.hpp"

GameObject* Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject* newFocus){

	focus = newFocus;

}

void Camera::Unfollow(){

	focus = nullptr;

}

void Camera::Update(float dt){

	if(focus != nullptr){

		//centrar a câmera na tela
		//pos = Game::GetInstance()->GetWindowDimensions()*0.5;

	}
	else{

		if(InputManager::GetInstance().KeyPress(LEFT_ARROW_KEY) || InputManager::GetInstance().KeyPress('a')){

			pos.SetX(pos.GetX() + CAMERA_MOVE_SPEED * dt);
			
		}
		if(InputManager::GetInstance().KeyPress(RIGHT_ARROW_KEY)|| InputManager::GetInstance().KeyPress('d')){

			pos.SetX(pos.GetX() - CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().KeyPress(UP_ARROW_KEY)|| InputManager::GetInstance().KeyPress('w')){

			pos.SetY(pos.GetY() + CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().KeyPress(DOWN_ARROW_KEY)|| InputManager::GetInstance().KeyPress('s')){

			pos.SetY(pos.GetY() - CAMERA_MOVE_SPEED * dt);

		}
	}

}
