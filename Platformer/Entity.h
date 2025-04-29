#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

// Clasa de baza pentru obiectele dinamice, are doar Player ca clasa derivata, dar
// s-ar putea baza pe ea si alte entitati dinamice
class Entity
{
protected:
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    Entity(const sf::Vector2f &pos = {}) : position(pos), velocity(0.0f, 0.0f) {}
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow &window) const = 0;

    virtual std::unique_ptr<Entity> clone() const = 0;

    const sf::Vector2f &getPosition() const { return position; }
    void setPosition(const sf::Vector2f &pos) { position = pos; }
};
