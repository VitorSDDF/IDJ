#ifndef ALIEN_HPP
#define ALIEN_HPP

#define INITIAL_ALIEN_HP 5

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef MINION_CLASS
class Minion;
#endif

#define ALIEN_VEL 100
#define ALIEN_ROTATION_VEL 10

#include "inputmanager.hpp"
#include "gameobject.hpp"
#include "sprite.hpp"
#include "minion.hpp"

#include <queue>
#include <vector>

class Alien : public GameObject{

	public:

		Alien(float x,float y,int nMinions);
		~Alien();

		void Update(float dt);
		void Render();
		bool IsDead();

	private:

		class Action{
			public:

				enum ActionType{MOVE,SHOOT};

				Action(ActionType type,float x,float y);
				ActionType type;
				Vec2 pos;
			
		};

		Sprite *sp;
		Vec2 speed;
		int hp;
		float arc;
		std::queue<Action> taskQueue;
		std::vector<Minion> minionArray;

};

#endif