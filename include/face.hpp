#ifndef FACE_HPP
#define FACE_HPP

#define PENGUIN_RADIX 32
#define PENGUIN_INITIAL_HITPOINTS 1

#include "sprite.hpp"
#include "gameobject.hpp"
#include "rect.hpp"
#include <stdlib.h>

class Sprite;

class Face : public GameObject{

	public:

		Face(float x ,float y);
		
		void Damage(int damage);
		void Update(float dt );
		void Render();
		bool IsDead();
		int getHitpoints();

	private:

		int hitpoints;
		Sprite	*sp;
};

#endif