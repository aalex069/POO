#include "LevelState.h"
#include "Platform.h"
#include "GameStateManager.h"

LevelState::LevelState(sf::RenderWindow &win, GameStateManager &gsmRef, int level)
    : window(win), gsm(gsmRef), player(sf::Vector2f(100.f, 100.f)), levelIndex(level)
{
    if (level == 1)
    {
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(300.f, 40.f), sf::Vector2f(200.f, 900.f)));
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 900.f)));
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 900.f)));
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1400.f, 900.f)));
    }
    else if (level == 2)
    {
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(400.f, 700.f)));
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(900.f, 600.f)));
    }

    levelText = std::make_unique<Texts>("Level " + std::to_string(level), "Fonts/Roboto-Black.ttf");
    levelText->setCharacterSize(24);
    levelText->setFillColor(sf::Color::White);
    levelText->setPosition({10.f, 10.f});
}

void LevelState::update(float dt)
{
    player.setOnGround(false);
    player.handleCollision(platforms);
    player.update(dt);
    player.checkFallOutOfBounds(static_cast<float>(window.getSize().y));

    if (levelIndex == 1 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        gsm.change(std::make_unique<LevelState>(window, gsm, 2));
    }
}

void LevelState::render(sf::RenderWindow &window)
{
    for (const auto &platform : platforms)
        platform->render(window);

    player.render(window);
    window.draw(*levelText);
}