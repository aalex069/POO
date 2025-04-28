#pragma once
#include "GameException.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Fonts : public sf::Font
{
private:
    void initFonts(const std::string &address);

public:
    Fonts(const std::string &address);
    ~Fonts();
};
