#pragma once

#include <sstream>
#include "PauseState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>


namespace Sonar {
	PauseState::PauseState(GameDataRef data) : _data(data) {

	}

	void PauseState::Init() {

		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - 
			(this->_resumeButton.getLocalBounds().width / 2), 
			(this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->window.getSize().x / 2) -
			(this->_homeButton.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
		//3*2 move down by one
	}

	void PauseState::HandleInput() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window)) {
				//std::cout << "Go To Game Screen" << std::endl;
				//remove current state to continue the game
				this->_data->machine.RemoveState();
			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window)) {
				//remove pause state then replace gameState with MainMenuState
				this->_data->machine.RemoveState();

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void PauseState::Update(float dt) {}

	void PauseState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}