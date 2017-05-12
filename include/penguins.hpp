#ifndef PENGUINS_HPP
#define PENGUINS_HPP

#include "gameobject.hpp"
#include "sprite.hpp"
#include "timer.hpp"
#include "animation.hpp"

#define PENGUIN_INITIAL_HP 30
#define PENGUIN_ACCELERATION 5
#define PENGUIN_LINEAR_SPEED 30
#define PENGUIN_MAX_LINEAR_SPEED 60
#define PENGUIN_MAX_BULLET_COOLDOWN 1
#define PENGUIN_MIN_LINEAR_SPEED 30
#define PENGUIN_ANGULAR_SPEED 4
#define CANNON_INITIAL_ROTATION 0
#define CANNON_INITIAL_ANGLE 0

#ifndef SPRITE_CLASS
class Sprite;
#endif

class Penguins : public GameObject{

	public:

		Penguins(float x,float y);
		~Penguins();

		void Update(float dt);
		void Render();
		bool IsDead();
		void Shoot();
		void NotifyCollision(GameObject& other);
		bool Is(std::string type);
		Penguins* player;

	private:

		Sprite* bodySp;
		Sprite* cannonSp;
		Vec2 speed;
		float linearSpeed;
		float cannonAngle;
		int hp;
		Timer bulletsCoolDown;

};

#endif