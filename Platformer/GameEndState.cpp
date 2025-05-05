#include "GameEndState.h"

GameEndState::GameEndState(sf::RenderWindow &win, GameStateManager &gsmRef, const std::string &message, sf::Color color, int fin, int diff, int time)
    : window(win), gsm(gsmRef), finalScore(fin), difficulty(diff), finalTime(time), font("Fonts/Roboto-Black.ttf")
{
    endText = std::make_unique<Texts>(message, font);
    endText->setCharacterSize(48);
    endText->setFillColor(color);
    endText->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    endText->setOrigin(endText->getGlobalBounds().size / 2.f);
    if (difficulty != 2)
    {
        scoreText = std::make_unique<Texts>("Final Score: " + std::to_string(finalScore), font);
    }
    else
    {
        scoreText = std::make_unique<Texts>("Seconds Spent: " + std::to_string(finalTime), font);
    }
    scoreText->setCharacterSize(32);
    scoreText->setFillColor(color);
    scoreText->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f + 50.f});
    scoreText->setOrigin(scoreText->getGlobalBounds().size / 2.f);
}

void GameEndState::update(float dt) {}

void GameEndState::render(sf::RenderWindow &target)
{
    target.draw(*endText);
    target.draw(*scoreText);
}

void GameEndState::handleEvent(const sf::Event &event)
{
    if (const auto *key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Escape)
        {
            window.close();
        }
    }
}
