#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Cari {
	//inherit state
	class SplashState : public State {
	public:
		SplashState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		
		//to check how long the app was running for
		sf::Clock clock;

		sf::Sprite background;
	};
}