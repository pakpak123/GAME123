#include <SFML/Audio.hpp>
#include "Game.h"
#include <iostream>


#define _CRT_SECURE_NO_WARNINGS

#include"WINDOW.h"
#include<time.h>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>

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
	WINDOW window2;

	window2.run();


}


