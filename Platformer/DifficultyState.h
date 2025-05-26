#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"
#include "Fonts.h"
#include <vector>

class MenuState;
// Meniu in care se alege dificultatea
class DifficultyState : public GameState
{
private:
    sf::RenderWindow &window;
    MenuState &menu;
    std::vector<Button> buttons;
    Fonts font;
    int hoveredOption = -1;

public:
    DifficultyState(sf::RenderWindow &win, MenuState &menuRef);
    void update(float dt) override;
    void render(sf::RenderWindow &target) override;
    void handleEvent(const sf::Event &event) override;
};
