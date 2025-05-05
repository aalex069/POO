#pragma once
#include "Fonts.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Texts.h"
#include "MenuState.h"

// Stare in care sunt explicate controalele si scorul jocului
class HelpState : public GameState
{
private:
    sf::RenderWindow &window;
    GameStateManager &gsm;
    std::unique_ptr<Texts> helpText;
    Fonts font;
    int difficulty;

public:
    HelpState(sf::RenderWindow &win, GameStateManager &gsm, int diff);
    void update(float dt) override;
    void render(sf::RenderWindow &target) override;
    void handleEvent(const sf::Event &event) override;
};
