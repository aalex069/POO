#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include "GameException.h"

// Gesioneaza proprietatile si actiunile jucatorului, care sunt
// explicate mai in detaliu in README
class Player : public Entity
{
private:
    static sf::Texture texture;
    sf::Sprite sprite;
    int health = 100;

    sf::Vector2f previousPosition;
    sf::Vector2f lastGroundedPosition;
    bool onGround = false;
    bool hasJustFallen = false;

    struct Dash
    {
        sf::Clock inputClock;
        float lastLeftTap = -1.f;
        float lastRightTap = -1.f;
        bool leftPressed = false;
        bool rightPressed = false;
        sf::Clock durationClock;
        sf::Clock cooldownClock;
        bool active = false;
        float direction = 0.f;
        const float duration = 0.2500f;
        const float cooldown = 2.500f;
    } dash;

    struct Jump
    {
        int count = 0;
        const int max = 2;
        bool pressedLastFrame = false;
    } jump;

public:
    static constexpr float gravity = 980.f;
    static constexpr float dashSpeed = 750.f;
    Player(const sf::Vector2f &pos = sf::Vector2f(100.f, 100.f));

    void update(float dt) override;
    void render(sf::RenderWindow &window) const override;

    sf::FloatRect getBounds() const;
    sf::Vector2f getPreviousPosition() const;
    void setPositionX(float x);
    void setPositionY(float y);
    void setVelocityX(float x);
    void setVelocityY(float y);
    float getVelocityY() const;
    void setOnGround(bool value);
    void setPosition(const sf::Vector2f &pos);
    void handleCollision(const std::vector<std::unique_ptr<StaticObject>> &platforms);
    void checkFallOutOfBounds(float windowHeight);
    int getHealth() const;
    void decreaseHealth(int amount);

    void saveGroundedPosition();
    sf::Vector2f getLastGroundedPosition() const;
    bool getGroundState() const;
    bool getHasJustFallen() const;
    void resetFallState();

    void handleDash(float dt);
    void handleJump(float dt);

    std::unique_ptr<Entity> clone() const override;
};
