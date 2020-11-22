#include "AssetManager.h"

void Player::iniVariable()
{
	this->MoveSpeed = 100.f;
	this->attackCooldownMax = 8.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
	this->P_x = 0;

}

void Player::iniTexture()
{
	//Load file
	if (!texture.loadFromFile("C:/Users/tp/source/repos/GAME123/12.png"))
	{
		printf("Not load player");
	}
}

void Player::iniSprite()
{
	this->A_x = texture.getSize().x / 3;
	this->A_y = texture.getSize().y / 4;

	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, A_x, A_y));
	this->sprite.setPosition(300, 200);
}

void Player::setupHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
}

Player::Player()
{
	this->iniVariable();
	this->MoveSpeed = 4.f;
	this->iniTexture();
	this->iniSprite();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getpos() const
{
	// TODO: insert return statement here
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBound() const
{
	return this->sprite.getGlobalBounds();
	//return sf::FloatRect();
}

const int& Player::getHP() const
{
	// TODO: insert return statement here
	return this->hp;
}

const int& Player::getHPMAX() const
{
	// TODO: insert return statement here
	return this->hpMax;
}

void Player::setHP(const int HP)
{
	this->hp = hp;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::loseHP(const int Value)
{
	this->hp -= Value;
}

void Player::FillHP(const int Value)
{
	if (this->hp <= 100)
	{
		this->hp += Value;
	}
}

void Player::Speedup(const int Value)
{
	int time = 0;
	int timemax = 2;

	do
	{
		this->MoveSpeed = 100;
		time++;
	} 
	while (time <= timemax);
	time = 0;
	this->MoveSpeed = 4;

}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::move(sf::RenderWindow* window)
{
	this->speedMove = 60;
	this->A_x = texture.getSize().x / 3;
	this->A_y = texture.getSize().y/4;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//turn right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			sprite.move(2.75f, 0.f);
			this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 2, this->A_x, this->A_y));

			this->P_x = P_x + 1;

			if (this->P_x * this->A_x >= this->A_x * 3)
			{
				this->P_x = 0;
			}
		}
		this->sprite.move(2.f, 0.f);
		window->setFramerateLimit(this->speedMove);
		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 2, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//turn left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			sprite.move(-2.75f, 0.f);
			this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 1, this->A_x, this->A_y));

			this->P_x = P_x + 1;

			if (this->P_x * this->A_x >= this->A_x * 3)
			{
				this->P_x = 0;
			}
		}
		this->sprite.move(-2.f, 0.f);
		window->setFramerateLimit(this->speedMove);
		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 1, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			sprite.move(0.f, 2.75f);
			window->setFramerateLimit(this->speedMove);
			this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 0, this->A_x, this->A_y));

			this->P_x = P_x + 1;

			if (this->P_x * this->A_x >= this->A_x * 3)
			{
				this->P_x = 0;
			}
		}
		this->sprite.move(0.f, 2.f);
		window->setFramerateLimit(this->speedMove);
		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 0, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			sprite.move(0.f, -2.75f);
			this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 3, this->A_x, this->A_y));

			this->P_x = P_x + 1;

			if (this->P_x * this->A_x >= this->A_x * 3)
			{
				this->P_x = 0;
			}
		}
		this->sprite.move(0.f, -2.f);
		window->setFramerateLimit(this->speedMove);
		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 3, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}
	else
	{
		window->setFramerateLimit(this->speedMove);
		this->sprite.setTextureRect(sf::IntRect(this->A_x * 1, this->A_y * 0, this->A_x, this->A_y));
	}
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return false;
	}
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.60f;
	}
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}





/*namespace Sonar
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		// TODO: insert return statement here
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		// TODO: insert return statement here
		return this->_fonts.at(name);
	}
}*/