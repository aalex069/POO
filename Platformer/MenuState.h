#pragma once
#include "GameState.h"
#include "Button.h"
#include "Fonts.h"
#include "GameStateManager.h"
#include "LevelState.h"
#include "HelpState.h"
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
    int difficulty = 0;

public:
    MenuState(sf::RenderWindow &window, GameStateManager &gsm, int diff);

    void setDifficulty(int diff);
    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
};
