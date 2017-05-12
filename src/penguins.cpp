#include "penguins.hpp"

Penguins::Penguins(float x,float y){

	this->player = this;

	bodySp = new Sprite(std::string("img/penguin.png"));
	cannonSp = new Sprite(std::string("img/cubngun.png"));

	box = new Rect(x,y,bodySp->GetWidth(),bodySp->GetHeight());
	rotation = CANNON_INITIAL_ROTATION;
	speed = Vec2(PENGUIN_MIN_LINEAR_SPEED,0);
	linearSpeed = PENGUIN_LINEAR_SPEED;
	cannonAngle = CANNON_INITIAL_ANGLE;
	hp = PENGUIN_INITIAL_HP;
	bulletsCoolDown = Timer();

}

Penguins::~Penguins(){

	player = nullptr;

}

void Penguins::Update(float dt){

		if(InputManager::GetInstance().IsKeyDown('w')){

			if(linearSpeed >= PENGUIN_MAX_LINEAR_SPEED){

				linearSpeed = PENGUIN_MAX_LINEAR_SPEED;

			}
			else{

				linearSpeed += PENGUIN_ACCELERATION;

			}

		}
		if(InputManager::GetInstance().IsKeyDown('s')){

			if(linearSpeed <= PENGUIN_MIN_LINEAR_SPEED){

				
				linearSpeed = PENGUIN_MIN_LINEAR_SPEED;

			}
			else{

				linearSpeed -= PENGUIN_ACCELERATION;

			}

		}
		if(InputManager::GetInstance().IsKeyDown('a')){

			rotation -= PENGUIN_ANGULAR_SPEED * dt;

		}
		if(InputManager::GetInstance().IsKeyDown('d')){

			rotation += PENGUIN_ANGULAR_SPEED * dt;

		}
		if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){
			if(bulletsCoolDown.Get() > PENGUIN_MAX_BULLET_COOLDOWN){
				std::cout << "Entrou 2" <<std::endl;
				bulletsCoolDown.Restart();
				Shoot();

			}

		}

		//std::cout << bulletsCoolDown.Get() <<std::endl;

		speed = Vec2(linearSpeed,0).Rotate(rotation);

		//Atualiza posicao
		box->SetX(box->Center().GetX() + (speed * dt).GetX() - box->GetW()/2);
		box->SetY(box->Center().GetY() + (speed * dt).GetY() - box->GetH()/2);

		Vec2 mousePos(InputManager::GetInstance().GetMouseX(),InputManager::GetInstance().GetMouseY());
		Vec2 distance = (box->Center() + Camera::pos).Distance(mousePos);
		cannonAngle = std::atan2(distance.GetY(),distance.GetX());

		bulletsCoolDown.Update(dt);

}
void Penguins::Render(){

	bodySp->Render(box->GetX() + Camera::pos.GetX(),box->GetY() + Camera::pos.GetY(),rotation * 180 / PI);
	Vec2 cannonPos = box->Center() - Vec2(cannonSp->GetWidth()/2,cannonSp->GetHeight()/2);
	cannonSp->Render(cannonPos.GetX() + Camera::pos.GetX(),cannonPos.GetY() + Camera::pos.GetY(),cannonAngle * 180 / PI);

}
bool Penguins::IsDead(){

	return (hp <= 0);

}
void Penguins::Shoot(){

	//Falta fazer com que o tiro saia da ponta do canhão
	Bullet* bullet = new Bullet(box->GetX(),box->GetY(),cannonAngle,BULLET_VEL,BULLET_REACH,std::string("img/penguinbullet.png"),false,4,0.25);
	Game::GetInstance()->GetState()->AddObject(bullet);

}

void Penguins::NotifyCollision(GameObject& other){

	if(other.Is(std::string("Bullet")) && (((Bullet&)other).TargetsPlayer())){

		hp --;
		if(IsDead()){

			Game::GetInstance()->GetState()->AddObject(new Animation(box->GetX(),box->GetY(),rotation * 180 / PI,img/penguindeath.png,5,0.1,true));

		}

	}

	if(hp <= 0){Camera::Unfollow();}

}

bool Penguins::Is(std::string type){

	return(type == "Penguins");
	
}