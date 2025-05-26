#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

// Decide ce se intampla atunci cand jucatorul cade de pe harta
class FallPenaltyStrategy
{
public:
    virtual void handleFall(Player &player, int &levelIndex, int &totalScore, float &totalTime, sf::RenderWindow &window) = 0;
    virtual ~FallPenaltyStrategy() = default;
};

class EasyPenalty : public FallPenaltyStrategy
{
public:
    void handleFall(Player &player, int &, int &, float &, sf::RenderWindow &) override
    {
        player.decreaseHealth(10);
    }
};

class MediumPenalty : public FallPenaltyStrategy
{
public:
    void handleFall(Player &player, int &, int &, float &, sf::RenderWindow &) override
    {
        player.decreaseHealth(20);
    }
};
