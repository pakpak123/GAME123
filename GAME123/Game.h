#pragma once
#include "AssetManager.h"
#include "State.h"
#include <map>
#include <sstream>

class Game
{
private:
	//window
	sf::RenderWindow* window;
	//player
	Player* player;

	//State
	float spawnTimer;
	float spawnTimerMax;

	std::vector<State*> enemies;
	std::vector<State*> items;

	//item recover
	float spawnTimerItem;
	float spawnTimerItemMax;

	std::map<std::string, sf::Texture*> texture;
	
	//G U I
	sf::Font font;
	sf::Text pointText;
	sf::Text GameOver;

	//system
	unsigned point;
	//player gui
	sf::RectangleShape playHPBar;
	sf::RectangleShape playHPBarBack;
	//player G U I
	sf::Texture wordBackground_t;
	sf::Sprite wordBackground_s;

	void iniWorld();
	void iniWindow();
	void iniTexture();
	void iniGui();
	void inisystem();
	void iniPlayer();
	void iniEnemies();
	void iniItem();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();
	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateEnemy();
	void updateitem();
	void update();
	
	void renderGUI();
	void render();
	void renderWorld();

};

