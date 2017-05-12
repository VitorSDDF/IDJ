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
		//Centrar a camera na tela
		pos = (focus->box->Center()* (-1.0)) + (Game::GetInstance()->GetWindowDimensions()*0.5);

	}
	else{

		if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){

			pos.SetX(pos.GetX() + CAMERA_MOVE_SPEED * dt);
			
		}
		if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){

			pos.SetX(pos.GetX() - CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){

			pos.SetY(pos.GetY() + CAMERA_MOVE_SPEED * dt);

		}
		if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){

			pos.SetY(pos.GetY() - CAMERA_MOVE_SPEED * dt);

		}
	}

}
