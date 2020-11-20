#pragma once
#ifndef STATE_H
#define STATE_H
#include "SFML/Graphics.hpp"

class State
{
private:
	unsigned pointConut;

	sf::Sprite enemy[4];
	sf::Sprite enemies;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;

	sf::Sprite item;

	int type;
	int typeEnemy;
	int typeItem;

	float speed;

	int hp;
	int hpmax;
	int recover;
	int damage;
	int point;

	void iniVariation();
	void iniTexture(sf::Sprite sprite);

public:
	State(float pos_x, float pos_y);
	virtual ~State();

	void Item();

	const sf::FloatRect getBound() const;
	const sf::FloatRect getBoundItem() const;
	const sf::Vector2f& getpos() const;
	const sf::Vector2f& getposItem() const;

	const int& getPoint() const;
	const int& getDamage() const;
	const int& getRecover() const;

	void update();
	void updateItem();

	void render(sf::RenderTarget* target);
	void renderitem(sf::RenderTarget* target);
};

#endif //!STATE_H
/*namespace Sonar
{
	class State
	{
	public:
		virtual void Init( ) = 0;

		virtual void HandleInput( ) = 0;
		virtual void Update( float dt ) = 0;
		virtual void Draw(float dt) = 0;
	
		virtual void Pause( ) { }
		virtual void Resume( ) { }
	};
}*/



