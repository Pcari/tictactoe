#pragma once

#include <sstream>
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>


namespace Sonar {
	GameOverState::GameOverState(GameDataRef data) : _data(data) {

	}

	void GameOverState::Init() {

		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		//overwrite asset if it already exists
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_retryButton.setPosition((this->_data->window.getSize().x / 2) -
			(this->_retryButton.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3) - (this->_retryButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->window.getSize().x / 2) -
			(this->_homeButton.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
		//3*2 move down by one
	}

	void GameOverState::HandleInput() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window)) {
				//std::cout << "Go To Game Screen" << std::endl;
				//remove current state to continue the game
				//this->_data->machine.RemoveState();
				//replace the current gamestate
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window)) {
				//remove pause state then replace gameState with MainMenuState
				//this->_data->machine.RemoveState();

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt) {}

	void GameOverState::Draw(float dt) {
		//clearing background color
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}