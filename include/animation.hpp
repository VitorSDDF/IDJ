#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <iostream>
#include "gameobject.hpp"
#include "timer.hpp"
#include "sprite.hpp"

#ifndef SPRITE_CLASS
class Sprite;
#endif

class Animation : public GameObject{

	public:

		Animation(float x,float y,float rotation,std::string sprite,int frameCount,float frameTime,bool ends);

		void Update(float);
		void Render();
		bool IsDead();
		void NotifyCollision(GameObject& other);
		bool Is(std::string type);

	private:

		Timer endTimer;
		float timeLimit;
		bool oneTimeOnly;
		Sprite *sp;
		
};

#endif