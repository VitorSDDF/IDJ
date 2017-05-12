#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP

#include "rect.hpp"

#include <iostream>

class Rect;

class GameObject{

	public:
	
		GameObject();
		~GameObject();
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual bool IsDead() = 0;
		virtual void NotifyCollision(GameObject& other) = 0;
		virtual bool Is(std::string type) = 0;
		float rotation;
		Rect *box;

};

#endif