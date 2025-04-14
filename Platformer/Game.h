#pragma once
#include "Texts.h"
#include "Times.h"
#include "Entity.h"
#include "Player.h"
#include "StaticObject.h"
#include "Platform.h"
#include "GameStateManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <string.h>

class Game
{
private:
    unsigned int width;
    unsigned int height;
    std::string title;
    sf::VideoMode vm;
    sf::RenderWindow *window;
    Times times;
    GameStateManager gsm;

    void initWindow();
    void pollEvents();
    void updating();
    void rendering();

public:
    Game();
    ~Game();

    void running();
};
