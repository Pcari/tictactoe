#include "InputManager.hpp"

namespace Cari {
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(button)) {
			//check if it collided with particular sprite
			//see if it contains mouse
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, 
				object.getGlobalBounds().height);

			//if it contains particular vector, getposition on particular window
			if (tempRect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}
		}
		//Sprite is not being clicked
		return false;
	}

	sf::Vector2i GetMousePosition(sf::RenderWindow &window) {
		return sf::Mouse::getPosition(window);
	}
}