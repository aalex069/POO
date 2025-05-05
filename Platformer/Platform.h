#pragma once
#include "StaticObject.h"
#include "GameException.h"

class Platform : public StaticObject
{
private:
    static sf::Texture texture;
    sf::Sprite sprite;

public:
    Platform(const sf::Vector2f &size, const sf::Vector2f &position);

    void render(sf::RenderWindow &window) const override;
    sf::FloatRect getBounds() const override;
};
