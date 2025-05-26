#include "DifficultyState.h"
#include "MenuState.h"

DifficultyState::DifficultyState(sf::RenderWindow &win, MenuState &menuRef)
    : window(win), menu(menuRef), font("Fonts/Roboto-Black.ttf")
{
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 200.f), "Easy", font);
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 300.f), "Medium", font);
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 400.f), "Hard", font);
}

void DifficultyState::update(float dt)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    hoveredOption = -1;

    for (unsigned i = 0; i < buttons.size(); ++i)
    {
        if (buttons[i].isHovered(window))
        {
            hoveredOption = i;
            break;
        }
    }

    for (unsigned int i = 0; i < buttons.size(); ++i)
    {
        if (i == hoveredOption)
            buttons[i].setColor(sf::Color::Blue);
        else
            buttons[i].setColor(sf::Color::White);
    }
}

void DifficultyState::render(sf::RenderWindow &target)
{
    for (auto &button : buttons)
        button.render(target);
}

void DifficultyState::handleEvent(const sf::Event &event)
{
    if (const auto *mouseClick = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseClick->button == sf::Mouse::Button::Left)
        {
            for (unsigned int i = 0; i < buttons.size(); ++i)
            {
                if (buttons[i].isHovered(window))
                {
                    menu.setDifficulty(i);
                    GameStateManager::getInstance().pop();
                    return;
                }
            }
        }
    }
}
