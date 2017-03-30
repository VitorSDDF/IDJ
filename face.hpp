#ifndef RECT_HPP
#define RECT_HPP

#define PENGUIN_RADIX 10

#include "sprite.hpp"
#include "GameObject.hpp"
#include "Rect.hpp"

class Rect;

class Face : public GameObject{

	public:

		Face(float x ,float y);
		
		void Damage(int damage);
		void Update(float dt );
		void Render();
		bool IsDead();

	private:

		int hitpoints;
		Sprite	sp;
};

#endif