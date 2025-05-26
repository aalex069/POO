#include "HardPenalty.h"
#include "GameStateManager.h"
#include "LevelState.h"

void HardPenalty::handleFall(Player &player, int &levelIndex, int &totalScore, float &totalTime, sf::RenderWindow &window)
{
    if (levelIndex > 1)
    {
        GameStateManager::getInstance().change(std::make_unique<LevelState>(window, levelIndex - 1, totalTime, totalScore, 2));
    }
    else
    {
        player.decreaseHealth(100);
    }
}
