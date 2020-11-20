#include "State.h"

void State::iniVariation()
{
	this->pointConut = rand() % 5 + 3; //min=3 and max=7
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointConut);
	this->damage = this->pointConut;
	this->recover = this->pointConut;
	this->point = this->pointConut;
}

void State::iniTexture(sf::Sprite sprite)
{
	 enemies = this->enemies;

	 if (!this->texture1.loadFromFile("C:/Users/tp/source/repos/GAME123/04.png"))
	 {
		 printf("Not Enemy 1-5");
	 }
	 if (!this->texture2.loadFromFile("C:/Users/tp/source/repos/GAME123/04.png"))
	 {
		 printf("Not Enemy 1-5");
	 }
	 if (!this->texture3.loadFromFile("C:/Users/tp/source/repos/GAME123/04.png"))
	 {
		 printf("Not Enemy 1-5");
	 }
	 if (!this->texture4.loadFromFile("C:/Users/tp/source/repos/GAME123/04.png"))
	 {
		 printf("Not Enemy 1-5");
	 }

	 this->typeEnemy = rand() % 4;
	 //Green
	 if (this->typeEnemy == 3)
	 {
		 this->enemy[3].setTexture(this->texture4);
		 this->enemies = this->enemy[3];
		 this->speed = static_cast<float>(this->pointConut / 2);
		 this->enemies.setScale(0.5f, 0.5f);

	 }
	 //Red
	 if (this->typeEnemy == 2)
	 {
		 this->enemy[3].setTexture(this->texture3);
		 this->enemies = this->enemy[2];
		 this->speed = static_cast<float>(this->pointConut / 2);
		 this->enemies.setScale(0.5f, 0.5f);

	 }
	 //yellow
	 if (this->typeEnemy == 1)
	 {
		 this->enemy[1].setTexture(this->texture4);
		 this->enemies = this->enemy[3];
		 this->speed = static_cast<float>(this->pointConut / 2+3);
		 this->enemies.setScale(0.5f, 0.5f);

	 }
	 //
	 if (this->typeEnemy == 0)
	 {
		 
	 }
}

State::State(float pos_x, float pos_y)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item();
	this->enemies.setPosition(pos_x, pos_y);
	this->item.setPosition(pos_x, pos_y);
}

State::~State()
{
}

void State::Item()
{
	this->typeItem = rand() % 100;

	if (this->typeItem == 99)
	{
		this->item.setTexture(this->texture1);
		this->speed = static_cast<float>(this->pointConut / 2 + 1);

	}
}

const sf::FloatRect State::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect State::getBoundItem() const
{
	return this->item.getGlobalBounds();
}

const sf::Vector2f& State::getpos() const
{
	// TODO: insert return statement here
	return this->enemies.getPosition();
}

const sf::Vector2f& State::getposItem() const
{
	// TODO: insert return statement here
	return this->item.getPosition();
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

void State::update()
{
	this->enemies.move(0.f, this->speed);
}

void State::updateItem()
{
	this->item.move(0.f, this->speed);
}

void State::render(sf::RenderTarget* target)
{
	target->draw(this->enemies);
}

void State::renderitem(sf::RenderTarget* target)
{
	target->draw(this->item);
}
