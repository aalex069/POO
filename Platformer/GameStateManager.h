#pragma once
#include "GameState.h"
#include "FallPenaltyStrategy.h"
#include <stack>
#include <memory>

// Cu ajutorul acestei clase se schimba intre starile jocului (clasele de tip GameState)
// Este unic in tot codul
class GameStateManager
{
private:
    std::stack<std::unique_ptr<GameState>> states;

    GameStateManager() = default;
    GameStateManager(const GameStateManager &) = delete;
    GameStateManager &operator=(const GameStateManager &) = delete;

public:
    static GameStateManager &getInstance();

    void push(std::unique_ptr<GameState> state);
    void pop();
    void change(std::unique_ptr<GameState> state);
    GameState *getCurrentState();

    void update(float dt);
    void render(sf::RenderWindow &window);
};