#include "State.h"

void State::iniVariation()
{
	this->pointConut = rand() % 5 +3; //min=3 and max=7
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this ->pointConut);
	this->damage = this->pointConut;
	this->recover = this->pointConut;
	this->point = this->pointConut;
	this->addpoint = this->pointConut;
}

void State::iniTexture(sf::Sprite enemies)
{
	 enemies = this->enemies;

	 if (!this->texture1.loadFromFile("C:/Users/tp/source/repos/GAME123/B1.png"))
	 {
		 printf("Not Enemy 1-5");
	 }
	 if (!this->texture2.loadFromFile("C:/Users/tp/source/repos/GAME123/B8.png"))
	 {
		 printf("Not Enemy 1-5");
	 }
	 

	 this->typeEnemy = rand() % 2;
	 
	 if (this->typeEnemy == 0)
	 {
		 this->enemy[0].setTexture(this->texture1);
		 this->enemies = this->enemy[0];
		 this->speed = static_cast<float>(this->pointConut / 2+2.5);
		 this->enemies.setScale(0.35f, 0.35f);
	 }

	 if (this->typeEnemy == 1)
	 {
		 this->enemy[1].setTexture(this->texture2);
		 this->enemies = this->enemy[1];
		 this->speed = static_cast<float>(this->pointConut / 2+3);
		 this->enemies.setScale(0.5f, 0.5f);

	 }
	 
	
	 
}


State::State(float pos_x, float pos_y,int i)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item1(i);
	this->Item2(i);
	this->enemies.setPosition(pos_x, pos_y);
	this->item1.setPosition(pos_x, pos_y);
	this->item2.setPosition(pos_x, pos_y);
}

State::~State()
{
}

void State::Item1(int i)
{
	this->typeItem1 = rand() % i;

	if (this->typeItem1 == 0)
	{
		this->item.setTexture(this->texture4);
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item.setScale(.7f, .7f);
	}
}

void State::Item2(int i)
{
	this->typeItem2 = rand() % i;

	if (this->typeItem2 == 0)
	{
		this->item2.setTexture(this->texture5);
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item2.setScale(.7f, .7f);
	}
}

const sf::FloatRect State::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect State::getBoundItem1() const
{
	return this->item1.getGlobalBounds();
}

const sf::FloatRect State::getBoundItem2() const
{
	return this->item2.getGlobalBounds();
}

const sf::Vector2f& State::getpos() const
{
	// TODO: insert return statement here
	return this->enemies.getPosition();
}

const sf::Vector2f& State::getposItem1() const
{
	// TODO: insert return statement here
	return this->item1.getPosition();
}

const sf::Vector2f& State::getposItem2() const
{
	// TODO: insert return statement here
	return this->item2.getPosition();
}


const int& State::getPoint() const
{
	// TODO: insert return statement here
	return this->point;
}

const int& State::getDamage() const
{
	// TODO: insert return statement here
	return this->damage;
}

const int& State::getRecover() const
{
	// TODO: insert return statement here
	return this->recover;
}

const int& State::Addpoint() const
{
	// TODO: insert return statement here
	return this->addpoint;
}

void State::update()
{
	this->enemies.move(0.f, this->speed);
}

void State::updateItem1()
{
	this->item1.move(0.f, this->speed);
}

void State::updateItem2()
{
	this->item2.move(0.f, this->speed);
}

void State::render(sf::RenderTarget* target)
{
	target->draw(this->enemies);
}

void State::renderitem1(sf::RenderTarget* target)
{
	target->draw(this->item1);
}

void State::renderitem2(sf::RenderTarget* target)
{
	target->draw(this->item2);
}


