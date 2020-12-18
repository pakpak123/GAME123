#pragma once
#include"SFML/Graphics.hpp"
#include<fstream>
#include<sstream>
#include"Game.h"


class EndGame
{
private:
	sf::Font font;
	sf::Text hightscoreText;

	sf::Text pointtText;

	sf::Text pointtText1;
	sf::Text pointtText2;
	sf::Text pointtText3;
	sf::Text pointtText4;
	sf::Text pointtText5;

	int score;

	int temp;

	int score_[5];



	sf::Texture bg;
	sf::Sprite bgg;

	void iniText(sf::RenderWindow* window, sf::Text pointt);
	void iniTextBackground(sf::RenderWindow* window);


public:

	EndGame(int score, unsigned hightscore, sf::RenderWindow* window, sf::Text pointt);
	virtual ~EndGame();
	void update(int Hightscore, int point, unsigned c);
	void render(sf::RenderTarget* target);
};