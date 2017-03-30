#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP

#include "Rect.hpp"

class Rect;

class GameObject{

	public:
	
		virtual ~GameObject();

		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual bool IsDead() = 0;
		Rect *box;

};

#endif