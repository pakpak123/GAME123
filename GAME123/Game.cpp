#include "Game.h" 
#include "Sstate.h"

void Game::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 600), "Neo ??", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::iniWorld()
{
	if (!this->wordBackground_t.loadFromFile("C:/Users/tp/source/repos/GAME123/EE.png"))
	{
		printf("NOT LOAD BACKGROUND");
	}

	if (!this->wordBackground_T.loadFromFile("C:/Users/tp/source/repos/GAME123/EE.png"))
	{
		printf("NOT LOAD BACKGROUND");
	}

	this->wordBackground_1.setTexture(this->wordBackground_t);
	this->wordBackground_2.setTexture(this->wordBackground_T);

	this->wordBackground_1.setScale((float)this->window->getSize().x / this->wordBackground_t.getSize().x, (float)this->window->getSize().y / this->wordBackground_t.getSize().y);
	this->wordBackground_2.setScale((float)this->window->getSize().x / this->wordBackground_t.getSize().x, (float)this->window->getSize().y / this->wordBackground_t.getSize().y);
}

void Game::iniTexture()
{
}

void Game::iniFalling()
{
	//enermy
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;

	//hp+
	this->spawnTimerItemMax1 = 5.f;
	this->spawnTimerItem1 = this->spawnTimerItemMax1;

	//star
	this->spawnTimerItemMax2 = 5.f;
	this->spawnTimerItem2 = this->spawnTimerItemMax2;
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
	this->playHPBarBack.setFillColor(sf::Color(25, 25, 25, 250));


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

/*void Game::inisystemHightscore()
{
	this->highscore = new EndGame(this->point,this->Hightscore,this->window, this->pointText);
}*/

void Game::iniPlayer()
{
	this->player = new Player();
}

void Game::iniEnemies()
{
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::iniItem1()
{
	this->spawnTimerItemMax1 = 5.f;
	this->spawnTimerItem1 = this->spawnTimerItemMax1;
}

void Game::iniItem2()
{
	this->spawnTimerItemMax2 = 5.f;
	this->spawnTimerItem2 = this->spawnTimerItemMax2;
}

void Game::iniSound()
{
	if (!this->sound1.loadFromFile("C:/Users/tp/source/repos/GAME123/10.ogg"))
	{
		printf("NOT LOAD SOUND");
	}
	if (!this->sound2.loadFromFile("C:/Users/tp/source/repos/GAME123/20.ogg"))
	{
		printf("NOT LOAD SOUND");
	}

	this->soundeffect1.setBuffer(this->sound1);
	this->soundeffect1.setVolume(120);
	this->soundeffect2.setBuffer(this->sound2);
	this->soundeffect1.setVolume(120);
}

Game::Game()
{
	//this->inisystemHightscore();
	this->iniWindow();
	this->iniFalling();
	this->iniWorld();
	this->iniGui();
	this->inisystem();
	this->iniPlayer();
	this->iniEnemies();
	this->iniItem1();
	this->iniItem2();
	this->iniTexture();
	this->iniSound();
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

	for (auto* i : this->items1)
	{
		delete i;
	}
	for (auto* i : this->items2)
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

	std::ifstream readcount;
	readcount.open("score/scorecount.text");
	if (readcount.is_open())
	{
		while (!readcount.eof())
		{
			readcount >> this->count;
		}
	}
	readcount.close();

	this->count = this->count + 1;


	std::ofstream writecount("score/scorecount.text");
	if (writecount.is_open())
	{
		writecount << this->count;
	}
	writecount.close();

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
	ss << "Point : " << this->point;
	this->pointText.setString(ss.str());

	//update player
	float hpPercent = static_cast<float>(this->player->getHP()) / this->player->getHPMAX() * 70;
	this->playHPBar.setSize(sf::Vector2f(4.f * hpPercent, this->playHPBar.getSize().y));

}

void Game::updateWorld()
{
	this->window->draw(this->wordBackground_1);
	this->window->draw(this->wordBackground_2);
}

void Game::updatebBackground()
{
	this->wordBackground_2.setPosition(0, this->wordBackground_1.getPosition().y - 600);
	this->deltaTime = clock.restart().asSeconds();

	if (wordBackground_1.getPosition().y > 600)
		wordBackground_1.setPosition(0, wordBackground_2.getPosition().y);
	if (wordBackground_2.getPosition().y > 600)
		wordBackground_2.setPosition(0, wordBackground_1.getPosition().y);

	//ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป

	this->wordBackground_1.move(0, this->speed * this->deltaTime);
	this->wordBackground_2.move(0, this->speed * this->deltaTime);
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
		this->player->setPosition(this->player->getBound().left, this->player->getBound().top > 0);
	}
	//right
	if (this->player->getBound().left + this->player->getBound().width >= this->window->getSize().x - 120.f)
	{
		this->player->setPosition(this->window->getSize().x - 120.f - this->player->getBound().width, this->player->getBound().top);
	}
	//down
	if (this->player->getBound().top + this->player->getBound().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBound().left, this->player->getBound().top <= 550);
	}
}

//void Game::updateHightscore()
//{
//	this->highscore->update(this->Hightscore, this->point, this->count);
//}

void Game::updateEnemy()
{
	//spawn
	int c = 0;
	if (this->point >= 200)
	{
		this->spawnTimer += .8f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			float randomLane = rand() % 4;
			if (randomLane == 0)
			{
				this->enemies.push_back(new Sstate(175, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 1)
			{
				this->enemies.push_back(new Sstate(310, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 2)
			{
				this->enemies.push_back(new Sstate(440, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 3)
			{
				this->enemies.push_back(new Sstate(570, -100.f, 4));
				this->spawnTimer = 0.f;
			}
		}
	}
	if (this->point < 200)
	{
		this->spawnTimer += 0.5f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			float randomLane = rand() % 4;
			if (randomLane == 0)
			{
				this->enemies.push_back(new Sstate(175, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 1)
			{
				this->enemies.push_back(new Sstate(310, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 2)
			{
				this->enemies.push_back(new Sstate(440, -100.f, 4));
				this->spawnTimer = 0.f;
			}
			if (randomLane == 3)
			{
				this->enemies.push_back(new Sstate(570, -100.f, 4));
				this->spawnTimer = 0.f;
			}
		}
	}

	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		float randomX = rand() % this->window->getSize().x;
		if (randomX >= 120 && randomX < 840)
		{
			this->enemies.push_back(new Sstate(randomX, -100.f, 4));
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
			//this->player->FillHP(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			this->soundeffect2.play();
			//hp
		}
		counter++;
	}
}
void Game::updateitem1()
{
	//spawn
	this->spawnTimerItem1 += 0.01f;
	if (this->spawnTimerItem1 >= this->spawnTimerItemMax1)
	{
		float randomX = rand() % this->window->getSize().x;
		if (randomX >= 150 && randomX <= 600)
		{
			this->items1.push_back(new Sstate(randomX, -100.f, 1));
			this->spawnTimerItem1 = 0.f;
			this->soundeffect2.play();
		}

	}

	//update
	unsigned counter = 0;
	for (auto* enemy1 : this->items1)
	{
		enemy1->updateItem1();

		//เลย screen
		if (enemy1->getBoundItem1().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->items1.at(counter);
			this->items1.erase(this->items1.begin() + counter);
		}
		//player collision
		else if (enemy1->getBoundItem1().intersects(this->player->getBound()))
		{
			//this->player->FillHP(this->items1.at(counter)->getRecover());
			delete this->items1.at(counter);
			this->items1.erase(this->items1.begin() + counter);
			this->soundeffect1.play();
		}
		counter++;
	}
}

void Game::updateitem2()
{
	//spawn
	this->spawnTimerItem2 += 0.2f;
	if (this->spawnTimerItem2 >= this->spawnTimerItemMax2)
	{
		float randomX = rand() % this->window->getSize().x;
		if (randomX >= 150 && randomX <= 600)
		{
			
			this->items2.push_back(new Sstate(randomX, -100.f, 1));
			this->spawnTimerItem2 = 0.f;
		}

	}

	//update
	unsigned counter = 0;
	for (auto* enemy2 : this->items2)
	{
		enemy2->updateItem2();

		//เลย screen
		if (enemy2->getBoundItem2().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->items2.at(counter);
			this->items2.erase(this->items2.begin() + counter);
		}
		//player collision
		else if (enemy2->getBoundItem2().intersects(this->player->getBound()))
		{
			this->soundeffect1.play();
			this->player->FillHP(this->items2.at(counter)->getRecover());
			this->point += 5;
			delete this->items2.at(counter);
			this->items2.erase(this->items2.begin() + counter);
			//hp
		}
		counter++;
	}
}

void Game::updateCombat()
{
}



void Game::update()
{
	this->updateInput();
	if (this->point <= 0)
	{
		this->player->update();
	}
	this->updateCollision();
	this->updateEnemy();
	this->updateitem1();
	this->updateitem2();
	this->updateGUI();
	this->updateWorld();
	this->updatebBackground();
	this->updateFalling();
	//this->updateHightscore();
	//this->updateHightscore();
}

void Game::updateFalling()
{
	//spawn

	if (this->point % 40 == 0)
	{
		this->spawnTimer += .3f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->enemies.push_back(new Sstate(rand() % this->window->getSize().x - 120, -200.f, 100));
			this->spawnTimer = 0.f;
		}
	}
	else
	{
		this->spawnTimer += .1f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->enemies.push_back(new Sstate(rand() % this->window->getSize().x - 120, -200.f, 100));
			this->spawnTimer = 0.f;
		}
	}


	//update
	unsigned counter = 0;
	for (auto* Falling : this->enemies)
	{
		Falling->update();

		//เลย screen
		if (Falling->getBound().top > this->window->getSize().y)
		{
			//delete enemy   
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		//เช็คชนแล้วเลือดลด
		if (Falling->getBound().intersects(this->player->getBound()))
		{
			this->player->loseHP(this->enemies.at(counter)->getDamage());

			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			//hp
		}
		counter++;
	}
}

void Game::renderFalling()
{
	for (auto* Falling2 : this->items2)
	{
		Falling2->renderitem2(this->window);
	}

	for (auto* Falling : this->enemies)
	{
		Falling->render(this->window);
	}

	/*for (auto* Falling1 : this->items1)
	{
		Falling1->renderitem1(this->window);
	}*/
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

	/*for (auto* enemy1 : this->items1)
	{
		enemy1->renderitem1(this->window);
	}*/
	for (auto* enemy2 : this->items2)
	{
		enemy2->renderitem2(this->window);
	}

	this->renderGUI();
	//Gamr over
	if (this->player->getHP() <= 0)
	{
		this->window->draw(this->GameOver);
		//this->renderHightscore();
	}

	this->window->display();

}

void Game::renderWorld()
{
	this->window->draw(this->wordBackground_1);
	this->window->draw(this->wordBackground_2);

}

/*void Game::renderHightscore()
{
	this->highscore->render(this->window);
}*/











