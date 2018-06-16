#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Cari {
	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	public:
		Game(int width, int height, std::string title);

	private:
		//framerate 60 times per second
		const float dt = 1.0f / 60.0;
		//to handle framerate
		sf::Clock _clock;

		GameDataRef data = std::make_shared<GameData>();

		void Run();

	};
}