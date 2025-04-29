#pragma once
#include "GameState.h"
#include "Button.h"
#include "Fonts.h"
#include "GameStateManager.h"
#include "LevelState.h"
#include <vector>

// Meniul prinipal
class MenuState : public GameState
{
private:
    sf::RenderWindow &window;
    GameStateManager &gsm;
    Fonts font;
    std::vector<Button> buttons;
    int hoveredOption = -1;

public:
    MenuState(sf::RenderWindow &window, GameStateManager &gsm);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
};
