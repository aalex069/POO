#pragma once
#include <SFML/Graphics.hpp>

class GameState
{
public:
    virtual ~GameState() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

    virtual void handleEvent(const sf::Event &event) {}
    virtual void onEnter() {}
    virtual void onExit() {}
};
