#pragma once
#include "StaticObject.h"

class Platform : public StaticObject
{
private:
    sf::RectangleShape shape;

public:
    Platform(const sf::Vector2f &size, const sf::Vector2f &position);

    void render(sf::RenderWindow &window) const override;
    sf::FloatRect getBounds() const override;
};
