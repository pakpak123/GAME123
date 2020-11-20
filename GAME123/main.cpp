#include "Game.h"
#include <time.h>

using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 800), "Neo ??", sf::Style::Close | sf::Style::Default);
	std::srand(static_cast<unsigned>(time(NULL)));

	Game game;

	game.run();
	//Sonar::Game(768, 1024, "GogGag!!!");
}

