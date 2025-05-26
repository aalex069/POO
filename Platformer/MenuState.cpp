#include "MenuState.h"
#include "DifficultyState.h"
MenuState::MenuState(sf::RenderWindow &win, int diff)
    : window(win), difficulty(diff), font("Fonts/Roboto-Black.ttf")
{
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 200.f), "New Game", font);
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 300.f), "Help", font);
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 400.f), "Difficulty", font);
    buttons.emplace_back(sf::Vector2f(300.f, 60.f), sf::Vector2f(window.getSize().x / 2.f, 500.f), "Exit", font);
}

void MenuState::update(float dt)
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

void MenuState::render(sf::RenderWindow &target)
{
    for (auto &button : buttons)
        button.render(target);
}

void MenuState::handleEvent(const sf::Event &event)
{
    if (const auto *mouseClick = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseClick->button == sf::Mouse::Button::Left)
        {
            for (unsigned int i = 0; i < buttons.size(); ++i)
            {
                if (buttons[i].isHovered(window))
                {
                    switch (i)
                    {
                    case 0: // New Game
                        GameStateManager::getInstance().change(std::make_unique<LevelState>(window, -1, 0, 0, difficulty));
                        return;
                    case 1: // Help
                        GameStateManager::getInstance().push(std::make_unique<HelpState>(window, difficulty));
                        return;
                    case 2: // Difficulty
                        GameStateManager::getInstance().push(std::make_unique<DifficultyState>(window, *this));
                        return;
                    case 3: // Exit
                        window.close();
                        break;
                    }
                }
            }
        }
    }
}

void MenuState::setDifficulty(int diff)
{
    difficulty = diff;
}