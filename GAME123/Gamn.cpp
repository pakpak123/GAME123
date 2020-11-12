#include <SFML/Graphics.hpp>

#include <iostream>

#define SCREEN_WIDTH 1024
#define SREEN-HEIGHT 1024

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),"Awesome Game");

	while (windoe.isOpen())
	{
		//handle events
		
		// update game logic
		//draw
		
		// draw SFML objects
		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}