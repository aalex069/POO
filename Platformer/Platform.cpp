#include "Platform.h"
#include <iostream>

sf::Texture Platform::texture;

Platform::Platform(const sf::Vector2f &size, const sf::Vector2f &position) : sprite(texture)
{
    static bool loaded = false;

    {
        if (!texture.loadFromFile("Assets/stone_tile.png"))
        {
            throw ResourceLoadException("Assets/stone_tile.png");
        }
        loaded = true;
    }

    sprite.setTexture(texture);
    sprite.setPosition(position);

    sprite.setScale({size.x / texture.getSize().x, size.y / texture.getSize().y});
}

void Platform::render(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

sf::FloatRect Platform::getBounds() const
{
    return sprite.getGlobalBounds();
}
