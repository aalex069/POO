#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <variant>

int main()
{
    Game *game = new Game();
    game->running();
    delete game;
    return 0;
}
