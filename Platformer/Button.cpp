#include "Button.h"

Button::Button(const sf::Vector2f &size, const sf::Vector2f &position, const std::string &label, const Fonts &font)
    : text(label, font)
{
    hitbox.setSize(size);
    hitbox.setOrigin(size / 2.f);
    hitbox.setPosition(position);

    text.setCharacterSize(32);
    text.setString(label);
    text.setPosition(position);
    text.setOrigin(text.getGlobalBounds().size / 2.f);
}

void Button::render(sf::RenderWindow &target) const
{
    target.draw(text);
}

bool Button::isHovered(sf::RenderWindow &window) const
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return hitbox.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::setColor(const sf::Color &color)
{
    text.setFillColor(color);
}
