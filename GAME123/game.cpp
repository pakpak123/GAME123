#include "game.h"
void game::initVariables()
{
	this->window = nullptr;
}

void game::updaetDt()
{
	this->dt = this->dtClock.getElapsedTime().asSeconds();
}
void game::initwindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 720;

	this->window = new sf::RenderWindow(this->videoMode, "Where is Baipul!", sf::Style::Titlebar |::Style::Close);
}
//Constructors / Destructors
game::game()
{
	this->initVariables();
	this->initwindow();

}

game::~game()
{
	delete this->window;
}

//Accessors
const bool game::running() const
{
	return this->window->isOpen();
}

//Functions
void game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case  sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void game::update()
{
	this->pollEvents(); 
 }

void game::render()
{
	/*
	 @return void
	- clear old frame
	- render objects
	- display frame in window
	Render the game objects.
	*/
	this->window->clear();

	//Draw game objects
	this->window->display();

}

void game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}