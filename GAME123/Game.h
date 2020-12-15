#pragma once
#include "AssetManager.h"
#include "State.h"
#include <map>
#include <sstream>
#include"EndGame.h"

class Game
{
private:
	//window
	sf::RenderWindow* window;
	//player
	Player* player;
	EndGame* highscore;

	//State
	float spawnTimer;
	float spawnTimerMax;

	std::vector<State*> enemies;
	std::vector<State*> items;
	std::vector<State*> items2;

	//item recover
	float spawnTimerItem;
	float spawnTimerItemMax;

	float spawnTimerItem2;
	float spawnTimerItemMax2;

	std::map<std::string, sf::Texture*> texture;
	
	//G U I
	sf::Font font;
	sf::Text pointText;
	sf::Text GameOver;

	//system
	unsigned point;
	unsigned Hightscore;
	unsigned count = 0;

	//player gui
	sf::RectangleShape playHPBar;
	sf::RectangleShape playHPBarBack;
	//world
	sf::Texture wordBackground_t;
	sf::Texture wordBackground_T;
	//Background
	sf::Sprite wordBackground_s;
	sf::Sprite wordBackground_1;
	sf::Sprite wordBackground_2;

	//Time
	sf::Clock clock;//ใช้ Clock นับเวลาที่เปลี่ยนไป deltaTime
	float speed = 50.f;// ความเร็วของการเลื่อน 50
	float deltaTime=0.0f;
	
	void iniWorld();
	void iniWindow();
	void iniTexture();
	void iniGui();
	void inisystem();
	void inisystemHightscore();
	void iniPlayer();
	void iniEnemies();
	void iniItem1();
	void iniItem2();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();
	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updatebBackground();
	void updateCollision();
	void updateHightscore();
	void updateEnemy();
	void updateitem1();
	void updateitem2();
	void updateCombat();
	void update();
	
	void renderGUI();
	void render();
	void renderWorld();
	void renderHightscore();
};

