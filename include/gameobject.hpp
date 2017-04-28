#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP

#include "rect.hpp"

class Rect;

class GameObject{

	public:
	
		//virtual ~GameObject();
		GameObject();
		~GameObject();
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual bool IsDead() = 0;
		float rotation;
		Rect *box;

};

#endif