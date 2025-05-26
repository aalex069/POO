#include "ObjectFactory.h"

// Creeaza un vector care contine platformele de pe un anumit nivel
std::vector<std::unique_ptr<StaticObject>> ObjectFactory<StaticObject>::createObjectsForLevel(int level)
{
    std::vector<std::unique_ptr<StaticObject>> platforms;

    switch (level)
    {
    case 1:
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(100.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(600.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1000.f, 900.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(1400.f, 900.f)));
        break;

    case 2:
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(200.f, 40.f), sf::Vector2f(300.f, 700.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(800.f, 600.f)));
        platforms.emplace_back(std::make_unique<Platform>(sf::Vector2f(400.f, 40.f), sf::Vector2f(1400.f, 500.f)));
        break;

    case 3:
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
        break;

    default:
        throw LevelLoadException(level);
    }

    return platforms;
}

// Initializeaza textul la inceputul fiecarui nivel
std::vector<std::unique_ptr<Texts<std::string>>> ObjectFactory<Texts<std::string>>::createObjectsForLevel(int levelIndex, int totalScore, float accumulatedTime, const sf::Font &font)
{
    std::vector<std::unique_ptr<Texts<std::string>>> texts;

    auto levelText = std::make_unique<Texts<std::string>>("Level: ", font);
    levelText->setCharacterSize(24);
    levelText->setFillColor(sf::Color::White);
    levelText->setPosition({10.f, 10.f});
    texts.emplace_back(std::move(levelText));

    auto healthText = std::make_unique<Texts<std::string>>("Health: ", font);
    healthText->setCharacterSize(24);
    healthText->setFillColor(sf::Color::White);
    healthText->setPosition({10.f, 50.f});
    texts.emplace_back(std::move(healthText));

    auto levelScoreText = std::make_unique<Texts<std::string>>("Level Score: ", font);
    levelScoreText->setCharacterSize(24);
    levelScoreText->setFillColor(sf::Color::White);
    levelScoreText->setPosition({10.f, 90.f});
    texts.emplace_back(std::move(levelScoreText));

    auto scoreText = std::make_unique<Texts<std::string>>("Total Score: ", font);
    scoreText->setCharacterSize(24);
    scoreText->setFillColor(sf::Color::White);
    scoreText->setPosition({10.f, 130.f});
    texts.emplace_back(std::move(scoreText));

    auto timeText = std::make_unique<Texts<std::string>>("Time: " + std::to_string(static_cast<int>(accumulatedTime)), font);
    timeText->setCharacterSize(24);
    timeText->setFillColor(sf::Color::White);
    timeText->setPosition({10.f, 50.f});
    texts.emplace_back(std::move(timeText));

    return texts;
}

template class ObjectFactory<StaticObject>;
template class ObjectFactory<Texts<std::string>>;