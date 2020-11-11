#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <chrono>
using namespace std;


int main()
{
	bool judg = true;
	int i = 0, t = 10, m = 0, n = 0;
	sf::RenderWindow window(sf::VideoMode(600, 480), "Game from scratch!");

	//backGround
	sf::Texture backGround;
	if (!backGround.loadFromFile("C:/Users/tp/source/repos/GAME123/01.png"))
	{
		std::cout << "Disable to open this file" << std::endl;
	}

	backGround.setSmooth(true);

	sf::Sprite ground;
	ground.setTexture(backGround);
	ground.setPosition(sf::Vector2f(0.f, 0.f));
	ground.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Font font;
	if (!font.loadFromFile("C:/Users/tp/source/repos/GAME123/Whale.ttf"))
	{
		std::cout << "ERROR" << std::endl;
		system("pause");
	}




	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("C:/Users/tp/source/repos/GAME123/12.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	////// Sprite
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);

	int spriteSizeX = playerTexture.getSize().x / 3;
	int spriteSizeY = playerTexture.getSize().y / 4;

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	int animationFrame = 0;

	while (window.isOpen())
	{

		window.draw(ground);
		window.draw(shapeSprite);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(0.f, -.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(0.f, .1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;

		if (animationFrame >= 2) {
			animationFrame = 0;
		}
		window.clear();
	}

	return 0;

}
