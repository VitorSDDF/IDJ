#define PI 3.14159

#ifndef BULLET_HPP
#define BULLET_HPP

#define BULLET_VEL 100
#define BULLET_REACH 1000

#include <string>

#include "gameobject.hpp"
#include "sprite.hpp"
#include "camera.hpp"

class Bullet : public GameObject{

	public:

		Bullet(float x,float y,float angle,float speed,float maxDistance,std::string sprite,bool targetsPlayer ,float frameCount = 1,float frameTime = 1);
		void Update(float dt);
		void Render();
		bool IsDead();
		void NotifyCollision(GameObject& other);
		bool Is(std::string type);
		bool TargetsPlayer();

	private:

		Sprite *sp;
		Vec2 speed;
		float distanceLeft;
		bool targetsPlayer;

};
#endif