#include "Platform.h"
#include <iostream>
Platform::Platform(const sf::Vector2f &size, const sf::Vector2f &position)
{
    shape.setSize(size);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
}

void Platform::render(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::FloatRect Platform::getBounds() const
{
    return shape.getGlobalBounds();
}
