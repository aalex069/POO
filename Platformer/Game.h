#pragma once
#include "Texts.h"
#include "Times.h"
#include "Entity.h"
#include "Player.h"
#include "StaticObject.h"
#include "Platform.h"
#include "MenuState.h"
#include "GameStateManager.h"
#include "LevelState.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

// Aici sunt incluse toate clasele din proiect si este rulat jocul propriu zis
class Game
{
private:
    unsigned int width;
    unsigned int height;
    std::string title;
    sf::VideoMode vm;
    sf::RenderWindow *window;
    Times times;

    void initWindow();
    void pollEvents();
    void updating();
    void rendering();

public:
    Game();
    ~Game();

    void running();
};
