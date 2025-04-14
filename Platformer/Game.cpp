#include "Game.h"
#include "LevelState.h"
#include <memory>

Game::Game()
{
    initWindow();
    gsm.push(std::make_unique<LevelState>(*window, gsm, 1));
}

Game::~Game()
{
    delete window;
}

void Game::initWindow()
{
    width = 1920;
    height = 1080;
    title = "SFML Platformer";
    vm = sf::VideoMode({width, height});
    window = new sf::RenderWindow(vm, title);
    window->setFramerateLimit(60);
}

void Game::pollEvents()
{

    while (const std::optional event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window->close();
        else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window->close();
        }

        if (gsm.getCurrentState())
            gsm.getCurrentState()->handleEvent(*event);
    }
}

void Game::updating()
{
    pollEvents();
    times.update();
    float dt = times.getDeltaTime();
    gsm.update(dt);
}

void Game::rendering()
{
    window->clear();
    gsm.render(*window);
    window->display();
}

void Game::running()
{
    while (window->isOpen())
    {
        updating();
        rendering();
    }
}
