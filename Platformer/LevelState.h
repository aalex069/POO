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
#include "ObjectFactory.h"
#include <vector>
#include <memory>

class FallPenaltyStrategy;

// Contine toate nivelurile si logica care schimba intre diferite niveluri si GameEndState
class LevelState : public GameState
{
private:
    sf::RenderWindow &window;
    Player player;
    std::vector<std::unique_ptr<StaticObject>> platforms;
    std::unique_ptr<Texts<std::string>> levelText;
    std::unique_ptr<Texts<std::string>> healthText;
    std::unique_ptr<Texts<std::string>> scoreText;
    std::unique_ptr<Texts<std::string>> levelScoreText;
    std::unique_ptr<Texts<std::string>> timeText;
    std::unique_ptr<FallPenaltyStrategy> fallStrategy;
    int levelIndex;
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
    LevelState(sf::RenderWindow &win, int level, int time, int score = 0, int diff = 0);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};