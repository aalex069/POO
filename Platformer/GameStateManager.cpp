#include "GameStateManager.h"

void GameStateManager::push(std::unique_ptr<GameState> state)
{
    if (state)
    {
        state->onEnter();
        states.push(std::move(state));
    }
}

void GameStateManager::pop()
{
    if (!states.empty())
    {
        states.top()->onExit();
        states.pop();
    }
}

void GameStateManager::change(std::unique_ptr<GameState> state)
{
    pop();
    push(std::move(state));
}

GameState *GameStateManager::getCurrentState()
{
    if (!states.empty())
        return states.top().get();
    return nullptr;
}

void GameStateManager::update(float dt)
{
    if (auto *current = getCurrentState())
        current->update(dt);
}

void GameStateManager::render(sf::RenderWindow &window)
{
    if (auto *current = getCurrentState())
        current->render(window);
}
