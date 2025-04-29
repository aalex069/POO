#pragma once
#include "GameState.h"
#include "Player.h"
#include "StaticObject.h"
#include "GameStateManager.h"
#include "Texts.h"
#include "Fonts.h"
#include "Platform.h"
#include "GameEndState.h"
#include "GameStateManager.h"
#include "GameException.h"
#include <vector>
#include <memory>

// Contine toate nivelurile si logica care schimba intre diferite niveluri si GameEndState
class LevelState : public GameState
{
private:
    sf::RenderWindow &window;
    Player player;
    std::vector<std::unique_ptr<StaticObject>> platforms;
    std::unique_ptr<Texts> levelText;
    std::unique_ptr<Texts> healthText;
    int levelIndex;
    GameStateManager &gsm;
    Fonts font;

public:
    LevelState(sf::RenderWindow &win, GameStateManager &gsm, int level);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};