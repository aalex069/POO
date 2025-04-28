#include "Game.h"
#include "GameException.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <variant>

int main()
{
    try
    {
        std::unique_ptr<Game> game = std::make_unique<Game>();
        game->running();
    }
    catch (const GameException &e)
    {
        std::cerr << "Eroare din joc: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Alta eroare: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}
