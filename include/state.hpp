#ifndef STATE_HPP
#define STATE_HPP

#include "sprite.hpp"
#include "gameobject.hpp"
#include "face.hpp"

#include <cstdlib>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iterator>
#include "tileset.hpp"
#include "tilemap.hpp"

#define PI 3.14
#define HIPOTENUSA 200

#ifndef SPRITE_CLASS
class Sprite;
#endif

class State{

	public:

		State();
		~State();

		bool QuitRequested();
		void LoadAssets();
		void Update();
		void Render();

	private:

		TileSet tileSet;
		TileMap tileMap;
		Sprite *bg;
		bool quitRequested;

		std::vector<std::unique_ptr<GameObject>> objectArray;

		void Input();
		void AddObject(float x,float y);

};

#endif
