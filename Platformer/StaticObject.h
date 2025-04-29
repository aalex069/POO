#pragma once
#include <SFML/Graphics.hpp>

// Clasa pur virtuala pe care sunt bazate toate obiectele statice
class StaticObject
{
public:
    virtual void render(sf::RenderWindow &window) const = 0;
    virtual sf::FloatRect getBounds() const = 0;

    virtual ~StaticObject() = default;
};