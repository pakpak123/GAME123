#pragma once
#ifndef SsTATE_H
#define SsTATE_H
#include "SFML/Graphics.hpp"

class Sstate
{
private:

protected:

	unsigned pointConut;

	sf::Sprite enemy[2];
	sf::Sprite enemies;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;

	sf::Sprite item;
	sf::Sprite item1;
	sf::Sprite item2;

	int type;
	int typeEnemy;
	int typeItem1;
	int typeItem2;

	float speed;

	int hp;
	int hpmax;
	int recover;
	int damage;
	int point;
	int addpoint;
	void iniVariation();
	void iniTexture(sf::Sprite sprite);

public:


	Sstate(float pos_x, float pos_y, int i);
	virtual ~Sstate();

	void Item1(int i);
	void Item2(int i);

	const sf::FloatRect getBound() const;
	const sf::FloatRect getBoundItem1() const;
	const sf::FloatRect getBoundItem2() const;
	const sf::Vector2f& getpos() const;
	const sf::Vector2f& getposItem1() const;
	const sf::Vector2f& getposItem2() const;

	const int& getPoint() const;
	const int& getDamage() const;
	const int& getRecover() const;
	const int& Addpoint() const;

	void update();
	void updateItem1();
	void updateItem2();

	void render(sf::RenderTarget* target);
	//void renderitem1(sf::RenderTarget* target);
	void renderitem2(sf::RenderTarget* target);
};
#endif


