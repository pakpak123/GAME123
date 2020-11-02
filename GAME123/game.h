#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

/*
class that acts as the game engins
Wrapper class
*/ 



class game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Clock dtClock;
	float dt;

	//object



	//Private Fuctions
	void initVariables();
	void initwindow();

public:
	//Constructors / destructors
	game();
	virtual  ~game();

	//Accessors
	const bool running() const;


	//Fuctions
	void updaetDt();
	void pollEvents();
	void update();
	void render();
	void run();
}

