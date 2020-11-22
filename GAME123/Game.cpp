#include "Game.h"

void Game::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 600), "Neo ??", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::iniWorld()
{
	if (!this->wordBackground_t.loadFromFile("C:/Users/tp/source/repos/GAME123/A1.png"))
	{
		printf("Not Load Background");
	}
	this->wordBackground_s.setTexture(this->wordBackground_t);
	this->wordBackground_s.setTextureRect(sf::IntRect(0, 0, 960, 600));
}

void Game::iniTexture()
{
}

void Game::iniGui()
{
	//Load Font
	if (!this->font.loadFromFile("C:/Users/tp/source/repos/GAME123/Whale.ttf"))
			printf("Not Load Font");

	//inipoint
	this->pointText.setFont(font);
	this->pointText.setCharacterSize(50);
	this->pointText.setPosition(this->window->getSize().x - 200, 0);
	this->pointText.setString("POINT");

	//update player
	this->playHPBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playHPBar.setFillColor(sf::Color::Red);
	this->playHPBar.setPosition(sf::Vector2f(0, 50));

	this->playHPBarBack = this->playHPBar;
	this->playHPBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	
	this->GameOver.setFont(font);
	this->GameOver.setFillColor(sf::Color::Red);
	this->GameOver.setCharacterSize(60);
	this->GameOver.setPosition(this->window->getSize().x / 2.5f - this->GameOver.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - -this->GameOver.getGlobalBounds().height / 2.f);
	this->GameOver.setString("GAME OVER!!!");
	
}

void Game::inisystem()
{
	this->point = 0;
}

void Game::iniPlayer()
{
	this->player = new Player();
}

void Game::iniEnemies()
{
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::iniItem()
{
	this->spawnTimerItemMax = 500.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}

Game::Game()
{
	this->iniWindow();

	this->iniWorld();
	this->iniGui();
	this->inisystem();
	this->iniPlayer();
	this->iniEnemies();
	//this->iniItem();
	//this->iniTexture();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	//delete enemy
	for (auto* i : this->enemies)
	{
		delete i;
	}

	for (auto* i : this->items)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		if (this->player->getHP() > 0)
			this->update();

		this->render();
	}
}

void Game::updatePollEvent()
{
	//ใช้ปุ่มปิดหน้าต่างของ window
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		//ปุ่ม
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	//move player
	this->player->move(this->window);
	
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Point :" << this->point;
	this->pointText.setString(ss.str());

	//update player
	float hpPercent = static_cast<float>(this->player->getHP()) / this->player->getHPMAX() * 100;
	this->playHPBar.setSize(sf::Vector2f(4.f * hpPercent, this->playHPBar.getSize().y));

}

void Game::updateWorld()
{
}

void Game::updateCollision()
{
	//set not move over screen
	//turn left
	if (this->player->getBound().left < 120.f)
	{
		this->player->setPosition(120.f, this->player->getBound().top);
	}
	//top
	if (this->player->getBound().top < 0.f)
	{
		this->player->setPosition(this->player->getBound().left, this->player->getBound().top>0);
	}
	//right
	if (this->player->getBound().left + this->player->getBound().width>=this->window->getSize().x-120.f)
	{
		this->player->setPosition(this->window->getSize().x-120.f- this->player->getBound().width, this->player->getBound().top);
	}
	//down
	if (this->player->getBound().top + this->player->getBound().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBound().left, this->player->getBound().top <=550);
	}
}

void Game::updateEnemy()
{
	//spawn
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
	float randomX = rand() % this->window->getSize().x;
		if (randomX >= 150 && randomX < -600)
		{
			this->enemies.push_back(new State(randomX, -100.f));
			this->spawnTimer = 0.f;
		}
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//เลยหน้าจอ
		if (enemy->getBound().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			this->point += 10;
		}
		//player collision
		else if (enemy->getBound().intersects(this->player->getBound()))
		{
			this->player->loseHP(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			//hp
		}
		counter++;
	}
}

void Game::updateitem()
{
	//spawn
	this->spawnTimerItem += .25f;
	if (this->spawnTimerItem >= this->spawnTimerItemMax)
	{
		this->items.push_back(new State(rand() % this->window->getSize().x - 100, -100.f));
		this->spawnTimerItem = 0.f;
	}
	
	//update
	unsigned   counter = 0;
	for (auto* enemy1 : this->items)
	{
		enemy1->updateItem();

		//เลยหน้าจอ
		if (enemy1->getBoundItem().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		//player collosion
		else if (enemy1->getBoundItem().intersects(this->player->getBound()))
		{
			this->player->FillHP(this->items.at(counter)->getRecover());
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
			//hp
		}
		counter++;
	} 

}

void Game::update()
{
	this->updateInput();
	this->player->update();
	this->updateCollision();
	this->updateEnemy();
	this->updateGUI();
	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playHPBarBack);
	this->window->draw(this->playHPBar);
}

void Game::render()
{
	this->window->clear();

	//draw world
	this->renderWorld();

	//draw stuff
	this->player->render(*this->window);
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* enemy1 : this->items)
	{
		enemy1->renderitem(this->window);
	}
	this->renderGUI();
	//Gamr over
	if (this->player->getHP() <= 0)this->window->draw(this->GameOver);
	this->window->display();
}

void Game::renderWorld()
{
	this->window->draw(this->wordBackground_s);
}











/*#include "SplashState.h"
namespace Sonar
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height),
			title, sf::Style::Close | sf::Style::Titlebar);


		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds(
			);

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(
				interpolation);
		}
	}
}*/