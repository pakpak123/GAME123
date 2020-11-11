#include<stdio.h>
#include<iostream>
#include <fstream>
#include<ctime>
#include<cstdlib>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include <SFML\Audio\Music.hpp>
using namespace sf;


class object
{
public:
	void position();
	void picture();
private:
	float x;
	float y;
}

main()
{
	bool judg = true;
	int i = 0, t = 10, m = 0, n = 0;
	sf::RenderWindow window(sf::VideoMode(600, 380), "Woww");

	sf::Music music;
	if (!music.openFromFile("C:/Users/tp/source/repos/GAME123/MianMusic.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	music.play();

	sf::Font font;
	if (!font.loadFromFile("C:/Users/tp/source/repos/GAME123/Whale.ttf"))
	{
		std::cout << "ERROR" << std::endl;
		system("pause");
	}

	sf::Text text;
	text.setFont(font);
	int a = 0, b = 0, c = 0;
	//text.setString("Hello World!!");
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Style::Underlined);
	text.setPosition(sf::Vector2f(250.f, 0.f));
	text.setOutlineColor(sf::Color::Yellow);
	text.setOutlineThickness(-2);

	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(18);
	score.setColor(sf::Color::Red);
	score.setPosition(sf::Vector2f(0.f, 0.f));

	sf::Clock clock;

	sf::Text time;
	time.setFont(font);
	time.setCharacterSize(18);
	time.setColor(sf::Color::Red);
	time.setPosition(sf::Vector2f(250.f, 250.f));

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

	sf::Texture gameOver;
	if (!gameOver.loadFromFile("C:/Users/tp/source/repos/GAME123/02.png"))
	{
		std::cout << "Do you have this file" << std::endl;
	}

	gameOver.setSmooth(true);
	sf::Sprite over;
	over.setTexture(gameOver);
	over.setPosition(sf::Vector2f(200.f, 200.f));
	over.setScale(sf::Vector2f(0.5f, 0.5f));

	sf::Texture woodBox;
	if (!gameOver.loadFromFile("C:/Users/tp/source/repos/GAME123/04.png"))
	{
		std::cout << "Do you have this file" << std::endl;
	}

	woodBox.setSmooth(true);
	sf::Sprite box;
	box.setTexture(woodBox);
	box.setPosition(sf::Vector2f(500.f, 200.f));
	box.setScale(sf::Vector2f(0.5f, 0.5f));
	box.move(300, 300);

	sf::Sprite box1;
	box1.setTexture(woodBox);
	box1.setPosition(sf::Vector2f(100.f, 230.f));
	box1.setScale(sf::Vector2f(0.5f, 0.5f));

	sf::Sprite box2;
	box2.setTexture(woodBox);
	box2.setPosition(sf::Vector2f(490.f, 170.f));
	box2.setScale(sf::Vector2f(0.5f, 0.5f));

	sf::Texture superMario;
	if (!superMario.loadFromFile("C:/Users/tp/source/repos/GAME123/12.png"))
	{
		std::cout << "It is fail to open this file" << std::endl;
	}

	superMario.setSmooth(true);
	sf::Sprite mario;
	mario.setTexture(superMario);
	mario.setPosition(sf::Vector2f(100.f, 290.f));
	mario.setScale(sf::Vector2f(0.5f, 0.5f));


	while (window.isOpen())
	{
		sf::Event event;
		//handle all events
		while (judg)
		{
			if (i >= 39)
			{
				i = 0;
				box.setPosition(sf::Vector2f(500.f, 290.f));
				a++;
			}
			if (m >= 16)
			{
				m = 0;
				box1.setPosition(sf::Vector2f(100.f, 230.f));
				b++;
			}
			if (n >= 13)
			{
				n = 0;
				box2.setPosition(sf::Vector2f(100.f, 230.f));
				c++;
			}

			box.move(-10, 0);
			box1.move(30, 0);
			box2.move(-30, 0);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			stringstream ss;
			ss << a + b + c;
			text.setString("SCORE: " + ss.str());
			ss.clear();
			ss.ignore();

			ifstream readFile;
			readFile.open("score.txx");
			if (readFile.fail())
			{
				std::cout << "unable to open TXT file" << std::endl;
			}
			string line;
			getline(readFile, line);

			if (line >= ss.str())
			{
				score.setString("RECORD: " + ss.str());
			}
			else if (line >= ss.str())
			{
				score.setString("RECORD: " + line);
			}
			else
			{
				std::cout << "the record has question." << std::endl;
			}
			readFile.close();

			window.clear();
			window.draw(ground);
			window.draw(text);
			window.draw(score);
			window.draw(mario);
			window.draw(box);
			window.draw(box1);
			window.draw(box2);
			window.display();
			sf::sleep(sf::seconds(0.1));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				std::cout << "jump-up!" << std::endl;
				/**for(int i=0;i<=10;i++)
				{
				int y =10*sin(3.1415926 *i/10;
				mario.move(i,-y);
				window.clear();
				sleep(seconds(0.01));
				}**/
				mario.move(30, -30);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				std::cout << "Up!" << std::endl;
				mario.move(0, -30);
				mario.setRotation(0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				std::cout << "turn Left!" << std::endl;
				mario.move(-30, 0);
				mario.setRotation(-90);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				std::cout << "turn Right!" << std::endl;
				mario.move(30, 0);
				mario.setRotation(90);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				std::cout << "jump down!" << std::endl;
				mario.move(0, 30);
				mario.setRotation(-180);
			}
			if (mario.getPosition() == box.getPosition() ||
				mario.getPosition() == box1.getPosition() ||
				mario.getPosition() == box2.getPosition())
			{
				std::cout << "game is over,countdown 10 seconds to close the window!" << std::endl;

				ifstream readFile;
				ofstream writeFile;
				readFile.open("score.txt");
				if (readFile.fail())
				{
					std::cout << "unable to open TXT file" << std::endl;
				}
				writeFile.open("temp.txt");
				if (writeFile.fail())
				{
					std::cout << " unable to open temp file" << std::endl;
				}
			}
			return 0;

		}
	}