#ifndef STATE_HPP
#define STATE_HPP

#include "sprite.hpp"
#include "gameobject.hpp"
#include "inputmanager.hpp"
#include "camera.hpp"
#include "alien.hpp"

#include <cstdlib>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iterator>
#include "tileset.hpp"
#include "tilemap.hpp"
#include "penguins.hpp"
#include "collision.h"

#define HIPOTENUSA 200

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef TILEMAP_CLASS
class TileMap;
#endif

#ifndef TILESET_CLASS
class TileSet;
#endif

class State{

	public:

		State();
		~State();

		bool QuitRequested();
		void LoadAssets();
		void Update();
		void Render();
		void AddObject(GameObject* ptr);

	private:

		TileSet *tileSet;
		TileMap *tileMap;
		Sprite *bg;
		bool quitRequested;

		std::vector<std::unique_ptr<GameObject>> objectArray;

		void Input();
		void AddObject(float x,float y);

};

#endif
