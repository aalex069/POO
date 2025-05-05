#include "Player.h"

sf::Texture Player::texture;

Player::Player(const sf::Vector2f &pos) : Entity(pos), sprite(texture)
{
    if (!texture.loadFromFile("Assets/player.png"))
        throw ResourceLoadException("Assets/player.png");

    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale({0.1f, 0.1f});
}

void Player::update(float dt)
{
    previousPosition = sprite.getPosition();

    if (!onGround)
        velocity.y += gravity * dt;

    handleJump(dt);
    handleDash(dt);

    if (dash.active)
    {
        velocity.x = dash.direction * dashSpeed;
        velocity.y = 0.f;

        if (dash.durationClock.getElapsedTime().asSeconds() > dash.duration)
        {
            dash.active = false;
            velocity.x = 0.f;
        }
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
            velocity.x = -200.f;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
            velocity.x = 200.f;
        else
            velocity.x = 0.f;
    }

    sprite.move(velocity * dt);
    position = sprite.getPosition();
}

// In cazul in care jucatorul este pe o platforma sau a sarit in aer, acesta poate sari
void Player::handleJump(float dt)
{
    if ((onGround || (jump.count < jump.max && jump.count > 0)) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)))
    {
        if (!jump.pressedLastFrame)
        {
            velocity.y = -400.f;
            onGround = false;
            jump.count++;
            jump.pressedLastFrame = true;
        }
    }
    else
    {
        jump.pressedLastFrame = false;
    }
}
// Dash-ruile se dau cu dublu click pe A sau pe D, de aceea aici
// se verica daca A sau D au fost apasate de 2 ori succesiv, si
// se mai verifica si daca dash-ul abia a fost folosit si trebuie
// asteptat pana la urmatoarea utilizare
void Player::handleDash(float dt)
{
    float currentTime = dash.inputClock.getElapsedTime().asSeconds();
    const float doubleTapThreshold = 0.3f;

    if (dash.cooldownClock.getElapsedTime().asSeconds() < dash.cooldown)
        return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
        if (!dash.rightPressed)
        {
            if (currentTime - dash.lastRightTap < doubleTapThreshold)
            {
                dash.active = true;
                dash.direction = 1.f;
                dash.durationClock.restart();
                dash.cooldownClock.restart();
            }
            dash.lastRightTap = currentTime;
            dash.rightPressed = true;
        }
    }
    else
    {
        dash.rightPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
        if (!dash.leftPressed)
        {
            if (currentTime - dash.lastLeftTap < doubleTapThreshold)
            {
                dash.active = true;
                dash.direction = -1.f;
                dash.durationClock.restart();
                dash.cooldownClock.restart();
            }
            dash.lastLeftTap = currentTime;
            dash.leftPressed = true;
        }
    }
    else
    {
        dash.leftPressed = false;
    }
}

void Player::render(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

sf::FloatRect Player::getBounds() const
{
    return sprite.getGlobalBounds();
}

std::unique_ptr<Entity> Player::clone() const
{
    return std::make_unique<Player>(*this);
}

void Player::setOnGround(bool value)
{
    onGround = value;
    if (value)
        jump.count = 0;
}

float Player::getVelocityY() const
{
    return velocity.y;
}

void Player::setPositionX(float x)
{
    sprite.setPosition({x, sprite.getPosition().y});
    position.x = x;
}
void Player::setPositionY(float y)
{
    sprite.setPosition({sprite.getPosition().x, y});
    position.y = y;
}

void Player::setVelocityX(float x)
{
    velocity.x = x;
}

void Player::setVelocityY(float y)
{
    velocity.y = y;
}

sf::Vector2f Player::getPreviousPosition() const
{
    return previousPosition;
}

bool Player::getGroundState() const
{
    return onGround;
}

void Player::saveGroundedPosition()
{
    lastGroundedPosition = sprite.getPosition();
}

sf::Vector2f Player::getLastGroundedPosition() const
{
    return lastGroundedPosition;
}

void Player::setPosition(const sf::Vector2f &pos)
{
    sprite.setPosition(pos);
    position = pos;
}
// Coliziunea cu platformele
void Player::handleCollision(const std::vector<std::unique_ptr<StaticObject>> &platforms)
{
    sf::FloatRect pBounds = getBounds();

    for (const auto &obj : platforms)
    {
        sf::FloatRect oBounds = obj->getBounds();

        if (pBounds.findIntersection(oBounds))
        {
            float playerCenterX = pBounds.position.x + pBounds.size.x / 2.f;
            float playerCenterY = pBounds.position.y + pBounds.size.y / 2.f;
            float objectCenterX = oBounds.position.x + oBounds.size.x / 2.f;
            float objectCenterY = oBounds.position.y + oBounds.size.y / 2.f;

            float dx = playerCenterX - objectCenterX;
            float dy = playerCenterY - objectCenterY;

            float overlapX = (pBounds.size.x / 2.f + oBounds.size.x / 2.f) - std::abs(dx);
            float overlapY = (pBounds.size.y / 2.f + oBounds.size.y / 2.f) - std::abs(dy);

            if (overlapX < overlapY)
            {
                // Coliziune pe orizontala
                if (dx > 0)
                    setPositionX(pBounds.position.x + overlapX); // din dreapta
                else
                    setPositionX(pBounds.position.x - overlapX); // din stanga

                setVelocityX(0.f);
            }
            else
            {
                // Coliziune pe verticala
                if (dy > 0)
                {
                    // Lovitura de jos
                    setPositionY(pBounds.position.y + overlapY);
                    setVelocityY(0.f);
                }
                else
                {
                    // Aterizare pe platforma
                    setPositionY(pBounds.position.y - overlapY);
                    setVelocityY(0.f);
                    setOnGround(true);
                    saveGroundedPosition();
                }
            }

            pBounds = getBounds();
        }
    }
}

void Player::checkFallOutOfBounds(float windowHeight)
{
    if (getBounds().position.y > windowHeight)
    {
        setVelocityY(0.f);
        setOnGround(false);
        setPosition(getLastGroundedPosition());
        hasJustFallen = true;
    }
}

int Player::getHealth() const
{
    return health;
}

void Player::decreaseHealth(int amount)
{
    health -= amount;
}

bool Player::getHasJustFallen() const
{
    return hasJustFallen;
}

void Player::resetFallState()
{
    hasJustFallen = false;
}