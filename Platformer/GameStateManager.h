#pragma once
#include "GameState.h"
#include <stack>
#include <memory>

// Cu ajutorul acestei cclase se schimba intre starile jocului (clasele de tip GameState)
class GameStateManager
{
private:
    std::stack<std::unique_ptr<GameState>> states;

public:
    void push(std::unique_ptr<GameState> state);
    void pop();
    void change(std::unique_ptr<GameState> state);
    GameState *getCurrentState();

    void update(float dt);
    void render(sf::RenderWindow &window);
};