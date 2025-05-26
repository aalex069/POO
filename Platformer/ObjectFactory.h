#pragma one
#include <vector>
#include <memory>
#include "GameException.h"
#include "Platform.h"
#include "Texts.h"

// Factory pt a introduce obiectele din fiecare nivel

template <typename T>
class ObjectFactory
{
public:
    static std::vector<std::unique_ptr<T>> createObjectsForLevel(int level);
};

template <>
class ObjectFactory<StaticObject>
{
public:
    static std::vector<std::unique_ptr<StaticObject>> createObjectsForLevel(int level);
};

template <>
class ObjectFactory<Texts<std::string>>
{
public:
    static std::vector<std::unique_ptr<Texts<std::string>>> createObjectsForLevel(
        int levelIndex, int totalScore, float accumulatedTime, const sf::Font &font);
};