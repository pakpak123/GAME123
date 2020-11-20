#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>

class Player
{
private:

	sf::Sprite sprite;
	sf::Texture texture;

	float MoveSpeed;

	int hp;
	int hpMax;
	
	float attackCooldown;
	float attackCooldownMax;

	//Functions
	void iniVariable();
	void iniTexture();
	void iniSprite();
	void setupHp(const int hp);
	void loseHp(const int value);

public:
	Player();
	virtual ~Player();

	//pos player
	const sf::Vector2f& getpos() const;
	//pos state
	const sf::FloatRect getBound() const;
	const int& getHP() const;
	const int& getHPMAX() const;
	void setHP(const int HP);
	void loseHP(const int Value);
	void FillHP(const int Value);
	void Speedup(const int Value);

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);

	//animation
	float speedMove;
	float A_x;
	float A_y;
	float P_x = 0;
	//Fuctions
	void move(sf::RenderWindow* window);

	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};
/*#include <map>

#include <SFML/Graphics.hpp>

namespace Sonar
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}*/