#include "Game.h"
#include "GameException.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <variant>

// Aici doar rulez jocul si verific 3 tipuri de erori: cele pe care le am definit eu in GameException, cele de tip std::exception
// si orice alte erori care nu sunt de tipurile mentionate precedent
int main()
{
    try
    {
        std::unique_ptr<Game> game = std::make_unique<Game>();
        game->running();
    }
    catch (const GameException &e)
    {
        std::cerr << "Game error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 2;
    }
    catch (...)
    {
        std::cerr << "Unexpected error" << std::endl;
    }

    return 0;
}
