#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Cari {
	SplashState::SplashState(GameDataRef data) : data(data) {

	}

	void SplashState::Init() {
		this->data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		background.setTexture(this->data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput() {
		sf::Event event;

		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();

			}
		}
	}

	void SplashState::Update(float dt) {
		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			//switch to the main menu
			std::cout << "Go to Main Menu" << std::endl;
		}
	}

	void SplashState::Draw(float dt) {
		this->data->window.clear(sf::Color::Red);
		this->data->window.draw(this->background);
		this->data->window.display();
	}
}