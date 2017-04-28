#ifndef BULLET_HPP
#define BULLET_HPP

#include <string>

#include "gameobject.hpp"
#include "sprite.hpp"

class Bullet : public GameObject{

	public:

		Bullet(float x,float y,float angle,float speed,float maxDistance,std::string sprite);
		void Update(float dt);
		void Render();
		bool IsDead();

	private:

		Sprite *sp;
		Vec2 speed;
		float distanceLeft;

};
#endif