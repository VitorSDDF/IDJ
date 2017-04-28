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

		if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY) || InputManager::GetInstance().IsKeyDown('a')){

			pos.SetX(pos.GetX() + CAMERA_MOVE_SPEED * dt);
			
		}
		if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)|| InputManager::GetInstance().IsKeyDown('d')){

			pos.SetX(pos.GetX() - CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)|| InputManager::GetInstance().IsKeyDown('w')){

			pos.SetY(pos.GetY() + CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)|| InputManager::GetInstance().IsKeyDown('s')){

			pos.SetY(pos.GetY() - CAMERA_MOVE_SPEED * dt);

		}
	}

}
