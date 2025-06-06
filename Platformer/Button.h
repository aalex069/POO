#pragma once
#include <SFML/Graphics.hpp>
#include "Texts.h"
#include "Fonts.h"

// Clasa aceasta ar putea fi considerat ca este in plus, dar fara sa adaug "butoane" nu am reusit sa fac
// meniul principal sa mearga, si m-am gandit ca asta ar fi o solutie buna
class Button
{
private:
    sf::RectangleShape hitbox;
    Texts<std::string> text;

public:
    Button(const sf::Vector2f &size, const sf::Vector2f &position, const std::string &label, const Fonts &font);

    void render(sf::RenderWindow &target) const;
    bool isHovered(sf::RenderWindow &window) const;
    void setColor(const sf::Color &color);
};
