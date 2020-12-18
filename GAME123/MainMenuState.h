#pragma once
#include "State.h"
#include"GameState.h"



class MainMenuState :
    public State
{
private:

    //verible
    sf::Texture BG;
    sf::Sprite  background1;
    sf::Font font;

    std::map<std::string, Button*> button;

    sf::SoundBuffer soundload2;
    sf::Sound sound2;


    //Function
    void iniVariable();
    void iniSound();
    void iniBackground();
    void iniFont();
    void iniKeybind();
    void iniButton();

public:

    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state);
    virtual ~MainMenuState();

    //Function


    //void endState();

    void updateInput(const float& dt);
    void updateButton();
    void update(const float& dt);
    void renderButton(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};

