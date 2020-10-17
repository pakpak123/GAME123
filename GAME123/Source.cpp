#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Where is Baipul!");
	
	sf::CircleShape collision(100.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(sf::Color::Magenta);

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("C:/Users/tp/source/repos/GAME123/12.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Music music;
	if (!music.openFromFile("C:/Users/tp/source/repos/GAME123/MainMusic.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	music.play();

	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);

	int spriteSizeX = playerTexture.getSize().x / 3;
	int spriteSizeY = playerTexture.getSize().y / 4;

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	int animationFrame = 0;

	sf::Vector2f spawnPoint = { 0.f, 0.f };
	shapeSprite.setPosition(spawnPoint);

	while (window.isOpen())
	{
		window.draw(shapeSprite);
		window.draw(collision);
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

		if (animationFrame >= 2) 
		{
			animationFrame = 0;
		}
		
		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds()))
		{
			shapeSprite.setPosition(spawnPoint);
		}

		window.clear();
	}
	return 0;
}





