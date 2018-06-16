#pragma once

namespace Cari {
	class State {
	public: 
		//initialize state
		virtual void Init() = 0;
		//handle all input on that particular state
		virtual void HandleInput() = 0;
		// update variables, update received inputs
		virtual void Update(float dt) = 0;
		//draw application dt = delta, 
		virtual void Draw(float dt) = 0;

		virtual void Pause() {}
		virtual void Resume() {}
	};
}
