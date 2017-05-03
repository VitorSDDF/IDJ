#define PI 3.14159

#ifndef MINION_HPP
#define MINION_HPP

#define MINION_DISTANCE_FROM_CENTER 100
#define BULLET_VEL 100
#define BULLET_REACH 300

#include "gameobject.hpp"
#include "vec2.hpp"
#include "sprite.hpp"
#include "bullet.hpp"
#include "camera.hpp"

#define MINION_VEL 1.57
#define MINION_CLASS

class Minion : public GameObject{
	
	public:
		
		Minion(GameObject* minionCenter,float arcOffset = 0);
		void Update(float dt);
		void Render();
		bool IsDead();
		void Shoot(Vec2 pos);

	private:

		GameObject* center;
		Sprite* sp;
		float arc;

};

#endif