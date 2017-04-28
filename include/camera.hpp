#ifndef CAMERA_HPP
#define CAMERA_HPP

#define CAMERA_MOVE_SPEED 10

#include "vec2.hpp"
#include "gameobject.hpp"
#include "game.hpp"

class Camera{
	
	public:

		static void Follow(GameObject* newFocus);
		static void Unfollow();
		static void Update(float dt);
		static Vec2 pos;
		static Vec2 speed;

	private:

		Camera();

		static GameObject* focus;

};

#endif