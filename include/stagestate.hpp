#ifndef STAGE_STATE_HPP
#define STAGE_STATE_HPP

#include "state.hpp"
#include "tileset.hpp"
#include "tilemap.hpp"
#include "penguins.hpp"
#include "collision.h"
#include "sprite.hpp"
#include "inputmanager.hpp"
#include "camera.hpp"
#include "alien.hpp"
#include "music.hpp"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iterator>

#ifndef SPRITE_CLASS
class Sprite;
#endif

#ifndef TILEMAP_CLASS
class TileMap;
#endif

#ifndef TILESET_CLASS
class TileSet;
#endif

class StageState : public State{

	public:
		
		~StageState();
		StageState();
		void Update();
		void Render();
		void Pause();
		void Resume();
		void LoadAssets();

	private:

		Sprite *bg;
		TileSet *tileSet;
		TileMap *tileMap;
		Music music;
		
};

#endif
