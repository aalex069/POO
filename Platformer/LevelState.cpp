#include "LevelState.h"
#include "FallPenaltyStrategy.h"
#include "HardPenalty.h"

sf::Texture LevelState::backgroundTexture;

// Creez nivelul precizat
LevelState::LevelState(sf::RenderWindow &win, int level, int time, int score, int diff)
    : window(win), player(sf::Vector2f(100.f, 100.f)), levelIndex(level), totalScore(score), difficulty(diff), accumulatedTime(time), font("Fonts/Roboto-Black.ttf"), background(backgroundTexture)
{

    if (!backgroundTexture.loadFromFile("Assets/sky.png"))
    {
        throw ResourceLoadException("Assets/sky.png");
    }

    background.setTexture(backgroundTexture);
    background.setScale({static_cast<float>(window.getSize().x) / background.getLocalBounds().size.x, static_cast<float>(window.getSize().y) / background.getLocalBounds().size.y});
    if (level == -1)
    {
        GameStateManager::getInstance().change(std::make_unique<LevelState>(window, 1, 0, 0, difficulty));
    }
    else
    {
        platforms = ObjectFactory<StaticObject>::createObjectsForLevel(level);
    }

    switch (difficulty)
    {
    case 0:
        fallStrategy = std::make_unique<EasyPenalty>();
        break;
    case 1:
        fallStrategy = std::make_unique<MediumPenalty>();
        break;
    case 2:
        fallStrategy = std::make_unique<HardPenalty>();
        break;
    }

    // levelText = std::make_unique<Texts>("Level " + std::to_string(levelIndex), font);
    // levelText->setCharacterSize(24);
    // levelText->setFillColor(sf::Color::White);
    // levelText->setPosition({10.f, 10.f});

    // healthText = std::make_unique<Texts>("Health: ", font);
    // healthText->setCharacterSize(24);
    // healthText->setFillColor(sf::Color::White);
    // healthText->setPosition({10.f, 50.f});

    // levelScoreText = std::make_unique<Texts>("Level Score: ", font);
    // levelScoreText->setCharacterSize(24);
    // levelScoreText->setFillColor(sf::Color::White);
    // levelScoreText->setPosition({10.f, 90.f});

    // scoreText = std::make_unique<Texts>("Total Score: " + std::to_string(totalScore), font);
    // scoreText->setCharacterSize(24);
    // scoreText->setFillColor(sf::Color::White);
    // scoreText->setPosition({10.f, 130.f});

    // timeText = std::make_unique<Texts>("Time: " + std::to_string(accumulatedTime), font);
    // timeText->setCharacterSize(24);
    // timeText->setFillColor(sf::Color::White);
    // timeText->setPosition({10.f, 50.f});

    auto texts = ObjectFactory<Texts<std::string>>::createObjectsForLevel(levelIndex, totalScore, accumulatedTime, font);
    levelText = std::move(texts[0]);
    healthText = std::move(texts[1]);
    levelScoreText = std::move(texts[2]);
    scoreText = std::move(texts[3]);
    timeText = std::move(texts[4]);

    levelText->streamText(levelIndex, {10.f, 10.f});
    scoreText->streamText(totalScore, {10.f, 130.f});

    levelClock.restart();
}

// Daca ies din ecran in partea dreapta, trec la urmatorul nivel
// si se calculeaza si scorul dobandit pana acum in nivel si in
// tot jocul
void LevelState::update(float dt)
{
    if (levelIndex == -1)
    {
        GameStateManager::getInstance().change(std::make_unique<LevelState>(window, 1, 0, 0, difficulty));
        return;
    }
    player.setOnGround(false);
    player.handleCollision(platforms);
    player.update(dt);
    player.checkFallOutOfBounds(static_cast<float>(window.getSize().y));

    healthText->streamText(player.getHealth(), {10.f, 50.f});
    float timeSpent = levelClock.getElapsedTime().asSeconds();
    float totalTime = accumulatedTime + static_cast<int>(timeSpent);
    float score = std::max(0.f, maxTime - timeSpent);
    float healthMultiplier = player.getHealth() / 100.f;
    int levelScore = static_cast<int>(score * healthMultiplier);
    levelScoreText->streamText(levelScore, {10.f, 90.f});
    timeText->streamText(static_cast<int>(totalTime), {10.f, 50.f});

    if (player.getHasJustFallen())
    {
        fallStrategy->handleFall(player, levelIndex, totalScore, totalTime, window);
        player.resetFallState();
    }

    if (levelIndex != 3 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        totalScore += levelScore;
        GameStateManager::getInstance().change(std::make_unique<LevelState>(window, levelIndex + 1, totalTime, totalScore, difficulty));
    }
    else if (levelIndex == 3 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        totalScore += levelScore;
        GameStateManager::getInstance().change(std::make_unique<GameEndState>(window, "YOU WIN", sf::Color::Green, totalScore, difficulty, totalTime));
    }

    if (player.getHealth() <= 0)
    {
        totalScore += levelScore;
        GameStateManager::getInstance().change(std::make_unique<GameEndState>(window, "GAME OVER", sf::Color::Red, totalScore, difficulty, totalTime));
    }
}

void LevelState::render(sf::RenderWindow &window)
{
    window.draw(background);
    for (const auto &platform : platforms)
        platform->render(window);

    player.render(window);
    window.draw(*levelText);
    if (difficulty != 2)
    {
        window.draw(*healthText);
        window.draw(*levelScoreText);
        window.draw(*scoreText);
    }
    else
    {
        window.draw(*timeText);
    }
}