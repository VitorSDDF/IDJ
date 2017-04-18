
#ifndef ALIEN_HPP
#define ALIEN_HPP

#define INITIAL_ALIEN_HP 5

#ifndef SPRITE_CLASS
class Sprite;
#endif

#include "inputmanager.hpp"
#include "gameobject.hpp"
#include "sprite.hpp"

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
		std::queue<Action> taskQueue;
		//std::vector<Minion> minionArray;

};

#endif