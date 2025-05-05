#include "LevelState.h"

sf::Texture LevelState::backgroundTexture;

// Creez nivelul precizat
LevelState::LevelState(sf::RenderWindow &win, GameStateManager &gsmRef, int level, int time, int score, int diff)
    : window(win), gsm(gsmRef), player(sf::Vector2f(100.f, 100.f)), levelIndex(level), totalScore(score), difficulty(diff), accumulatedTime(time), font("Fonts/Roboto-Black.ttf"), background(backgroundTexture)
{
    if (!backgroundTexture.loadFromFile("Assets/sky.png"))
    {
        throw ResourceLoadException("Assets/sky.png");
    }

    background.setTexture(backgroundTexture);
    background.setScale({static_cast<float>(window.getSize().x) / background.getLocalBounds().size.x, static_cast<float>(window.getSize().y) / background.getLocalBounds().size.y});
    if (level == -1)
    {
        gsm.change(std::make_unique<LevelState>(window, gsm, 1, 0, 0, difficulty));
    }
    else if (level == 1)
    {
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(100.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(100.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1400.f, 900.f)));
    }
    else if (level == 2)
    {
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(300.f, 700.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(800.f, 600.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(1400.f, 500.f)));
    }
    else if (level == 3)
    {
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(200.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 700.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 500.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 300.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 800.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 600.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 400.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 200.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1400.f, 200.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1650.f, 700.f)));
    }
    else
    {
        throw LevelLoadException(level);
    }

    levelText = std::make_unique<Texts>("Level " + std::to_string(levelIndex), font);
    levelText->setCharacterSize(24);
    levelText->setFillColor(sf::Color::White);
    levelText->setPosition({10.f, 10.f});

    healthText = std::make_unique<Texts>("Health: ", font);
    healthText->setCharacterSize(24);
    healthText->setFillColor(sf::Color::White);
    healthText->setPosition({10.f, 50.f});

    levelScoreText = std::make_unique<Texts>("Level Score: ", font);
    levelScoreText->setCharacterSize(24);
    levelScoreText->setFillColor(sf::Color::White);
    levelScoreText->setPosition({10.f, 90.f});

    scoreText = std::make_unique<Texts>("Total Score: " + std::to_string(totalScore), font);
    scoreText->setCharacterSize(24);
    scoreText->setFillColor(sf::Color::White);
    scoreText->setPosition({10.f, 130.f});

    timeText = std::make_unique<Texts>("Time: " + std::to_string(accumulatedTime), font);
    timeText->setCharacterSize(24);
    timeText->setFillColor(sf::Color::White);
    timeText->setPosition({10.f, 50.f});

    levelClock.restart();
}

// Daca ies din ecran in partea dreapta, trec la urmatorul nivel
// si se calculeaza si scorul dobandit pana acum in nivel si in
// tot jocul
void LevelState::update(float dt)
{
    if (levelIndex == -1)
    {
        gsm.change(std::make_unique<LevelState>(window, gsm, 1, 0, 0, difficulty));
        return;
    }
    player.setOnGround(false);
    player.handleCollision(platforms);
    player.update(dt);
    player.checkFallOutOfBounds(static_cast<float>(window.getSize().y));

    healthText->streamText("Health: ", player.getHealth(), {10.f, 50.f});
    float timeSpent = levelClock.getElapsedTime().asSeconds();
    float totalTime = accumulatedTime + static_cast<int>(timeSpent);
    float score = std::max(0.f, maxTime - timeSpent);
    float healthMultiplier = player.getHealth() / 100.f;
    int levelScore = static_cast<int>(score * healthMultiplier);
    levelScoreText->streamText("Level Score ", levelScore, {10.f, 90.f});
    timeText->streamText("Time: ", totalTime, {10.f, 50.f});

    if (player.getHasJustFallen())
    {
        if (difficulty == 0)
        {
            player.decreaseHealth(10);
        }
        else if (difficulty == 1)
        {
            player.decreaseHealth(20);
        }
        else if (difficulty == 2)
        {
            if (levelIndex > 1)
            {
                gsm.change(std::make_unique<LevelState>(window, gsm, levelIndex - 1, totalTime, totalScore, difficulty));
                return;
            }
            else
            {
                player.decreaseHealth(100);
            }
        }

        player.resetFallState();
    }

    if (levelIndex != 3 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        totalScore += levelScore;
        gsm.change(std::make_unique<LevelState>(window, gsm, levelIndex + 1, totalTime, totalScore, difficulty));
    }
    else if (levelIndex == 3 && player.getBounds().position.x > window.getSize().x - 100.f)
    {
        totalScore += levelScore;
        gsm.change(std::make_unique<GameEndState>(window, gsm, "YOU WIN", sf::Color::Green, totalScore, difficulty, totalTime));
    }

    if (player.getHealth() <= 0)
    {
        totalScore += levelScore;
        gsm.change(std::make_unique<GameEndState>(window, gsm, "GAME OVER", sf::Color::Red, totalScore, difficulty, totalTime));
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