#include "Game.hpp"
#include "SplashState.hpp"

namespace Cari {
	Game::Game(int width, int height, std::string title) {
		//called from main
		data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		//load splashstate of the first state
		data->machine.AddState(StateRef(new SplashState(this->data)));
		//need first state for game

		//runs the game
		this->Run();

	}
	void Game::Run() {
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->data->window.isOpen()) {
			this->data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			//frametime how long it took each frame
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				this->data->machine.GetActiveState()->HandleInput();
				this->data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}