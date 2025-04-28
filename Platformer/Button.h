#pragma once
#include <SFML/Graphics.hpp>
#include "Texts.h"
#include "Fonts.h"

class Button
{
private:
    sf::RectangleShape hitbox;
    Texts text;

public:
    Button(const sf::Vector2f &size, const sf::Vector2f &position, const std::string &label, const Fonts &font);

    void render(sf::RenderWindow &target) const;
    bool isHovered(sf::RenderWindow &window) const;
    void setColor(const sf::Color &color);
};
