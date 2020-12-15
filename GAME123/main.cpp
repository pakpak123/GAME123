#include <SFML/Audio.hpp>
#include "Game.h"
#include <iostream>
//#include "Menu.h"
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 600), "Neo ??", sf::Style::Close | sf::Style::Default);

	//sound
	sf::SoundBuffer Sound1;
	if (!Sound1.loadFromFile("C:/Users/tp/source/repos/GAME123/01234.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	sf::Sound Sound;
	Sound.setBuffer(Sound1);
	Sound.setLoop(true);
	Sound.play();

	//Menu menu(window.getSize().x,window.getSize().y);

	//menu.draw(window);

	std::srand(static_cast<unsigned>(time(NULL)));
	
	Game game;


	game.run();


}

