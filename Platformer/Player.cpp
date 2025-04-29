#include "Player.h"

Player::Player(const sf::Vector2f &pos) : Entity(pos)
{
    shape.setSize({50.f, 50.f});
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(position);
}

void Player::update(float dt)
{
    previousPosition = shape.getPosition();

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

    shape.move(velocity * dt);
    position = shape.getPosition();
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
    window.draw(shape);
}

sf::FloatRect Player::getBounds() const
{
    return shape.getGlobalBounds();
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

void Player::setPositionY(float y)
{
    shape.setPosition({shape.getPosition().x, y});
    position.y = y;
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
    lastGroundedPosition = shape.getPosition();
}

sf::Vector2f Player::getLastGroundedPosition() const
{
    return lastGroundedPosition;
}

void Player::setPosition(const sf::Vector2f &pos)
{
    shape.setPosition(pos);
    position = pos;
}
// Coliziunea cu platformele, se verifica daca in frame-ul trecut jucatorul
// era deasupra platformei si ca in frameul curent este sub platforma, ceea ce
// inseamna ca jucatorul a ajuns pe platforma si trebuie sa ramana pe ea
void Player::handleCollision(const std::vector<std::unique_ptr<StaticObject>> &platforms)
{
    sf::FloatRect pBounds = getBounds();

    for (const auto &obj : platforms)
    {
        sf::FloatRect oBounds = obj->getBounds();

        if (pBounds.findIntersection(oBounds))
        {
            float playerBottom = pBounds.position.y + pBounds.size.y;
            float platformTop = oBounds.position.y;
            float prevBottom = previousPosition.y + pBounds.size.y;

            if (prevBottom <= platformTop && playerBottom >= platformTop &&
                velocity.y >= 0.f && pBounds.findIntersection(oBounds))
            {
                setOnGround(true);
                setVelocityY(0.f);
                setPositionY(platformTop - pBounds.size.y);
                saveGroundedPosition();
                pBounds = getBounds();
            }
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
        health -= 10;
    }
}

int Player::getHealth() const
{
    return health;
}
