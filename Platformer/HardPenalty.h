#pragma once
#include "FallPenaltyStrategy.h"

class HardPenalty : public FallPenaltyStrategy
{
public:
    void handleFall(Player &player, int &levelIndex, int &totalScore, float &totalTime, sf::RenderWindow &window) override;
};
