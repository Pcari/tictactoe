#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

//handle the loop of the game
int main() {
	Cari::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe");
	return EXIT_SUCCESS;
}


/*
#include <SFML\Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main() {
//sf -> sfml namespace accessing something within sfml
//window is what users see and where we render objects
sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tic Tac Toe");

while (window.isOpen()) {

//handles event such as closing application
sf::Event event;

//while polling event
while (window.pollEvent(event)) {
//check what event has occured
switch (event.type) {
//if user tries to close application
case sf::Event::Closed:
window.close();
break;
}
}
//clear the screen every single frame
window.clear();

//all objects to draw
window.display();
}

}*/