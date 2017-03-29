#include "Sprite.hpp"
Class Face : public GameObject{

	public:

		Face(float x ,float y);
		
		void Damage(int damage);
		void Update(float dt );
		void Render();
		bool IsDead();

	private:

		int hitpoints;
		Sprite	sp;
}
