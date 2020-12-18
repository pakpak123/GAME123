#include "Sstate.h"

void Sstate::iniVariation()
{
	this->pointConut = rand() % 2 + 3;
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointConut);
	this->damage = this->pointConut + 2;
	this->recover = this->pointConut + 2;
	this->point = this->pointConut + 2;
	this->addpoint = this->pointConut + 2;
}

void Sstate::iniTexture(sf::Sprite enemies)
{
	enemies = this->enemies;

	if (!this->texture1.loadFromFile("C:/Users/tp/source/repos/GAME123/B1.png"))
	{
		printf("Not Enemy 1");
	}
	if (!this->texture2.loadFromFile("C:/Users/tp/source/repos/GAME123/B8.png"))
	{
		printf("Not Enemy 2");
	}
	if (!this->texture3.loadFromFile("C:/Users/tp/source/repos/GAME123/B5.png"))
	{
		printf("Not enemy3");
	}
	if (!this->texture4.loadFromFile("C:/Users/tp/source/repos/GAME123/A33.png"))
	{
		printf("Not item1");
	}
	if (!this->texture5.loadFromFile("C:/Users/tp/source/repos/GAME123/PP.png"))
	{
		printf("Not item2");
	}
	this->typeEnemy = rand() % 4;

	if (this->typeEnemy == 0)
	{
		this->enemy[0].setTexture(this->texture1);
		this->enemies = this->enemy[0];
		this->speed = static_cast<float>(this->pointConut / 2 + 2.5);
		this->enemies.setScale(0.2f, 0.2f);
	}

	if (this->typeEnemy == 1)
	{
		this->enemy[1].setTexture(this->texture2);
		this->enemies = this->enemy[1];
		this->speed = static_cast<float>(this->pointConut / 2 + 3);
		this->enemies.setScale(0.4f, 0.4f);

	}

	if (this->typeEnemy == 2)
	{
		this->enemy[2].setTexture(this->texture3);
		this->enemies = this->enemy[2];
		this->speed = static_cast<float>(this->pointConut / 2 + 3);
		this->enemies.setScale(0.4f, 0.4f);

	}
	if (this->typeEnemy == 3)
	{
		this->enemy[3].setTexture(this->texture5);
		this->enemies = this->enemy[3];
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->enemies.setScale(0.4f, 0.4f);

	}

}


Sstate::Sstate(float pos_x, float pos_y, int i)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item1(i);
	this->Item2(i);
	this->enemies.setPosition(pos_x, pos_y);
	this->item1.setPosition(pos_x, pos_y);
	this->item2.setPosition(pos_x, pos_y);
}

Sstate::~Sstate()
{
}

void Sstate::Item1(int i)
{
	this->typeItem1 = rand() % i;

	if (this->typeItem1 == 0)//HP+
	{
		this->item.setTexture(this->texture5);
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item.setScale(.1f, .1f);
	}
}

void Sstate::Item2(int i)//point
{
	this->typeItem2 = rand() % i;

	if (this->typeItem2 == 0)
	{
		this->item2.setTexture(this->texture4);
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item2.setScale(.5f, .5f);
	}
}

const sf::FloatRect Sstate::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect Sstate::getBoundItem1() const
{
	return this->item1.getGlobalBounds();
}

const sf::FloatRect Sstate::getBoundItem2() const
{
	return this->item2.getGlobalBounds();
}

const sf::Vector2f& Sstate::getpos() const
{
	// TODO: insert return statement here
	return this->enemies.getPosition();
}

const sf::Vector2f& Sstate::getposItem1() const
{
	// TODO: insert return statement here
	return this->item1.getPosition();
}

const sf::Vector2f& Sstate::getposItem2() const
{
	// TODO: insert return statement here
	return this->item2.getPosition();
}


const int& Sstate::getPoint() const
{
	// TODO: insert return statement here
	return this->point;
}

const int& Sstate::getDamage() const
{
	// TODO: insert return statement here
	return this->damage;
}

const int& Sstate::getRecover() const
{
	// TODO: insert return statement here
	return this->recover;
}

const int& Sstate::Addpoint() const
{
	// TODO: insert return statement here
	return this->addpoint;
}

void Sstate::update()
{
	this->enemies.move(0.f, this->speed);
}

void Sstate::updateItem1()
{
	this->item1.move(0.f, this->speed);
}

void Sstate::updateItem2()
{
	this->item2.move(0.f, this->speed);
}

void Sstate::render(sf::RenderTarget* target)
{
	target->draw(this->enemies);
}

/*void Sstate::renderitem1(sf::RenderTarget* target)
{
	target->draw(this->item1);
}*/

void Sstate::renderitem2(sf::RenderTarget* target)
{
	target->draw(this->item2);
}


