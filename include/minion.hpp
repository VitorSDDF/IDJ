#define PI 3.14

#ifndef MINION_HPP
#define MINION_HPP

#define PI 3.14
#define MINION_DISTANCE_FROM_CENTER 500
#include "gameobject.hpp"
#include "vec2.hpp"
#include "sprite.hpp"

#define MINION_CLASS

class Minion : public GameObject{
	
	public:
		
		Minion(GameObject* minionCenter,float arcOffset = 0);
		void Update(float dt);
		void Render();
		bool IsDead();
		void Shoot(Vec2 pos);

		static constexpr float minionVel = PI/2;

	private:

		GameObject* center;
		Sprite* sp;
		float arc;

};

#endif