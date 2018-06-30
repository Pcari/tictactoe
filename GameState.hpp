#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "AI.hpp"

namespace Sonar {
	class GameState : public State {
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		//creating gridpieces
		void InitGridPieces();

		void CheckAndPlacePiece();
		//check whenever player places a piece
		void CheckPlayerHasWon(int turn);

		//checking if particular row/column/diagonal line matches
		void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _pauseButton;

		sf::Sprite _gridSprite;
		//9 pieces placed on grid
		//Just need to change the colors if clicked
		sf::Sprite _gridPieces[3][3];

		//keeping track of whats in the grid
		int gridArray[3][3];

		//define whos turn
		int turn;
		//one of the states from DEFINITION
		int gameState;

		//create AI object
		AI *ai;


	};
}