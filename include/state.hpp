#ifndef STATE_HPP
#define STATE_HPP

#include "gameobject.hpp"

#include <cstdlib>
#include <memory>
#include <vector>

class State{

	public:

		State();
		virtual ~State();

		virtual void LoadAssets();
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;
		bool PopRequested();
		bool QuitRequested();
		virtual void AddObject(GameObject* ptr);

	protected:

		virtual void UpdateArray(float dt);
		virtual void RenderArray();

		bool popRequested;
		bool quitRequested;
		
		std::vector<std::unique_ptr<GameObject>> objectArray;

};

#endif
