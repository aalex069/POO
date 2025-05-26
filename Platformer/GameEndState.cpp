#include "GameEndState.h"

GameEndState::GameEndState(sf::RenderWindow &win, const std::string &message, sf::Color color, int fin, int diff, int time)
    : window(win), finalScore(fin), difficulty(diff), finalTime(time), font("Fonts/Roboto-Black.ttf")
{
    endText = std::make_unique<Texts<std::string>>(message, font);
    endText->setCharacterSize(48);
    endText->setString(message);
    endText->setFillColor(color);
    endText->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    endText->setOrigin(endText->getGlobalBounds().size / 2.f);
    if (difficulty != 2)
    {
        scoreText = std::make_unique<Texts<std::string>>("Final Score: ", font);
        scoreText->streamText(finalScore, {window.getSize().x / 2.f, window.getSize().y / 2.f + 50.f});
    }
    else
    {
        scoreText = std::make_unique<Texts<std::string>>("Seconds Spent: ", font);
        scoreText->streamText(finalTime, {window.getSize().x / 2.f, window.getSize().y / 2.f + 50.f});
    }
    scoreText->setCharacterSize(32);
    scoreText->setFillColor(color);
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
