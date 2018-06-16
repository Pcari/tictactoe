#pragma once
#include <SFML/Graphics.hpp>

namespace Cari {
	class InputManager {
	public:
		InputManager() {}
		~InputManager() {}

		// actual sprite that we want to click, actual window events&items are on
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}