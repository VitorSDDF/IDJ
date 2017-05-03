#include "penguins.hpp"

Penguins::Penguins(float x,float y){

	this->player = this;

	bodySp = Sprite(std::string("penguin.png"));
	cannonSp = Sprite(std::string("cubngun.png"));

	box = new Rect(x,y,bodySp.GetWidth(),bodySp.GetHeight());
	rotation = CANNON_INITIAL_ROTATION;
	speed = Vec2(PENGUIN_LINEAR_SPEED,0);
	linearSpeed = PENGUIN_LINEAR_SPEED;
	cannonAngle = CANNON_INITIAL_ANGLE;
	hp = PENGUIN_INITIAL_HP;

}

Penguins::~Penguins(){

	player = nullptr;

}

void Penguins::Update(float dt){

		if(InputManager::GetInstance().IsKeyDown('w')){

			if(speed.GetY() >= PENGUIN_MAX_LINEAR_SPEED){

				
				speed.SetY(PENGUIN_MAX_LINEAR_SPEED);

			}
			else{

				speed.SetY(speed.GetY() + PENGUIN_ACCELERATION);

			}

		}
		if(InputManager::GetInstance().IsKeyDown('s')){

			if(speed.GetY() <= PENGUIN_MIN_LINEAR_SPEED){

				
				speed.SetY(PENGUIN_MIN_LINEAR_SPEED);

			}
			else{

				speed.SetY(speed.GetY() - PENGUIN_ACCELERATION);

			}

		}
		if(InputManager::GetInstance().IsKeyDown('a')){

			speed.SetX(-PENGUIN_MIN_LINEAR_SPEED);

		}
		if(InputManager::GetInstance().IsKeyDown('d')){

			speed.SetX(PENGUIN_MIN_LINEAR_SPEED);

		}
		if(!InputManager::GetInstance().IsKeyDown('d') && !InputManager::GetInstance().IsKeyDown('a')){

			speed.SetX(0);

		}
		if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){

			Shoot();

		}
		//Atualiza posicao
		box->SetX(box->Center().GetX() + (speed * dt).GetX() - box->GetW()/2);
		box->SetY(box->Center().GetY() + (speed * dt).GetY() - box->GetH()/2);

		Vec2 mousePos(InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY());
		cannonAngle = std::atan2(box->Center().Distance(mousePos).GetY(),box->Center().Distance(mousePos).GetX());
		rotation = std::atan2(speed.GetY(),speed.GetX());


}
void Penguins::Render(){

	bodySp.Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),rotation);
	Vec2 cannonPos = box->Center() - Vec2(cannonSp.GetWidth()/2,cannonSp.GetHeight()/2);
	cannonSp.Render(cannonPos.GetX() + Camera::pos.GetX(),cannonPos.GetY() + Camera::pos.GetY(),cannonAngle);

}
bool Penguins::IsDead(){

	return (hp <= 0);

}
void Penguins::Shoot(){

	Bullet* bullet = new Bullet(box->GetX(),box->GetY(),cannonAngle,BULLET_VEL,BULLET_REACH,std::string("img/minionbullet2.png"),3);
	Game::GetInstance()->GetState()->AddObject(bullet);

}