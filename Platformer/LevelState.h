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
    std::unique_ptr<Texts> scoreText;
    std::unique_ptr<Texts> levelScoreText;
    std::unique_ptr<Texts> timeText;
    int levelIndex;
    GameStateManager &gsm;
    Fonts font;
    sf::Clock levelClock;
    int finalScore;
    const float maxTime = 120.f;
    int totalScore;
    int difficulty;
    int accumulatedTime;
    static sf::Texture backgroundTexture;
    sf::Sprite background;

public:
    LevelState(sf::RenderWindow &win, GameStateManager &gsm, int level, int time, int score = 0, int diff = 0);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};