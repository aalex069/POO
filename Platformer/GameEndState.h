#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Fonts.h"
#include "Texts.h"
#include "LevelState.h"

// Reprezinta ecranul de final, care poate avea afisat orice mesaj dat ca parametru
class GameEndState : public GameState
{
private:
    sf::RenderWindow &window;
    GameStateManager &gsm;
    std::unique_ptr<Texts> endText;
    std::unique_ptr<Texts> scoreText;
    Fonts font;
    int finalScore;
    int difficulty;
    int finalTime;

public:
    GameEndState(sf::RenderWindow &window, GameStateManager &gsm, const std::string &message, sf::Color color, int fin, int diff, int time);
    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
};