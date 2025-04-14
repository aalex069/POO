#pragma once
#include "GameState.h"
#include "Player.h"
#include "StaticObject.h"
#include "GameStateManager.h"
#include <vector>
#include <memory>
#include "Texts.h"

class LevelState : public GameState
{
private:
    sf::RenderWindow &window;
    Player player;
    std::vector<std::unique_ptr<StaticObject>> platforms;
    std::unique_ptr<Texts> levelText;
    int levelIndex;
    GameStateManager &gsm;

public:
    LevelState(sf::RenderWindow &win, GameStateManager &gsm, int level);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};