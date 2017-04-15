void Camera::Follow(GameObject* newFocus){

	focus = newFocus;

}

void Camera::Unfollow(){

	focus = nullptr;

}

void Camera::Update(float dt){

	if(focus != nullptr){

		//centrar a câmera na tela
		pos.x = focus->box.Center().x- (Game::GetInstance().GetWindowDimensions()*0.5);

	}

}
