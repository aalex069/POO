#include "LevelState.h"

// Creez nivelul precizat
LevelState::LevelState(sf::RenderWindow &win, GameStateManager &gsmRef, int level)
    : window(win), gsm(gsmRef), player(sf::Vector2f(100.f, 100.f)), levelIndex(level), font("Fonts/Roboto-Black.ttf")
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
        platforms.push_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(1500.f, 500.f)));
    }
    else
    {
        throw LevelLoadException(level);
    }

    levelText = std::make_unique<Texts>("Level " + std::to_string(level), font);
    levelText->setCharacterSize(24);
    levelText->setFillColor(sf::Color::White);
    levelText->setPosition({10.f, 10.f});
    healthText = std::make_unique<Texts>("Health: ", font);
    healthText->setCharacterSize(24);
    healthText->setFillColor(sf::Color::White);
    healthText->setPosition({10.f, 50.f});
}

// Daca ies din ecran in partea dreapta, trec la urmatorul nivel
void LevelState::update(float dt)
{
    player.setOnGround(false);
    player.handleCollision(platforms);
    player.update(dt);
    player.checkFallOutOfBounds(static_cast<float>(window.getSize().y));
    healthText->streamText("Health: ", player.getHealth(), {10.f, 50.f});

    if (levelIndex == 1 && player.getBounds().position.x > window.getSize().x - 100.f)
    {

        gsm.change(std::make_unique<LevelState>(window, gsm, 2));
    }
    else if (levelIndex == 2 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        gsm.change(std::make_unique<GameEndState>(window, gsm, "YOU WIN", sf::Color::Green));
    }

    if (player.getHealth() <= 0)
    {
        gsm.change(std::make_unique<GameEndState>(window, gsm, "GAME OVER", sf::Color::Red));
    }
}

void LevelState::render(sf::RenderWindow &window)
{
    for (const auto &platform : platforms)
        platform->render(window);

    player.render(window);
    window.draw(*levelText);
    window.draw(*healthText);
}