#include "gameobject.hpp"
#include "sprite.hpp"

#define PENGUIN_INITIAL_HP 30
#define PENGUIN_ACCELERATION 20
#define PENGUIN_LINEAR_SPEED 30
#define PENGUIN_MAX_LINEAR_SPEED 30
#define PENGUIN_MIN_LINEAR_SPEED 30
#define PENGUIN_ANGULAR_SPEED 20
#define CANNON_INITIAL_ROTATION 0
#define CANNON_INITIAL_ANGLE 0

class Penguins : public GameObject{

	public:

		Penguins(float x,float y);
		~Penguins();

		void Update(float dt);
		void Render();
		bool IsDead();
		void Shoot();
		Penguins* player;

	private:

		Sprite bodySp;
		Sprite cannonSp;
		Vec2 speed;
		float linearSpeed;
		float cannonAngle;
		int hp;

};