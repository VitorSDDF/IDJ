#ifndef ALIEN_HPP
#define ALIEN_HPP

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef MINION_CLASS
class Minion;
#endif

#define INITIAL_ALIEN_HP 30
#define ALIEN_VEL 80
#define ALIEN_ROTATION_VEL 10
#define ALIEN_COOLDOWN 3

#include "inputmanager.hpp"
#include "gameobject.hpp"
#include "sprite.hpp"
#include "minion.hpp"
#include "camera.hpp"
#include "animation.hpp"
#include "timer.hpp"
#include "sound.hpp"

#include <queue>
#include <vector>
#include <cmath>
#include <limits>

class Alien : public GameObject{

	public:

		Alien(float x,float y,int nMinions);
		~Alien();

		void Update(float dt);
		void Render();
		bool IsDead();
		void NotifyCollision(GameObject& other);
		bool Is(std::string type);
		void sumHP(int delta);

		static int alienCount;

	private:

		Sprite *sp;
		Vec2 speed;
		int hp;
		float arc;
		std::vector<Minion> minionArray;
		enum AlienState{MOVING,RESTING} alienState;
		AlienState state;
		Timer restTimer;
		Vec2 destination;

};

#endif
