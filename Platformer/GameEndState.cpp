#include "GameEndState.h"
#include "LevelState.h"

GameEndState::GameEndState(sf::RenderWindow &win, GameStateManager &gsmRef, const std::string &message, sf::Color color)
    : window(win), gsm(gsmRef), font("Fonts/Roboto-Black.ttf")
{
    endText = std::make_unique<Texts>(message, font);
    endText->setCharacterSize(48);
    endText->setFillColor(color);
    endText->setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
    endText->setOrigin(endText->getGlobalBounds().size / 2.f);
}

void GameEndState::update(float dt) {}

void GameEndState::render(sf::RenderWindow &target)
{
    target.draw(*endText);
}

void GameEndState::handleEvent(const sf::Event &event)
{
    if (const auto *key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Enter)
        {
            gsm.change(std::make_unique<LevelState>(window, gsm, 1)); // restart game
        }
        else if (key->scancode == sf::Keyboard::Scancode::Escape)
        {
            window.close();
        }
    }
}
