#pragma once
#include "Texts.h"
#include <SFML/Graphics.hpp>

class Times
{
private:
    sf::Clock clock;
    float deltaTime;
    float totalTime;
    int frameCount;
    float fps;

public:
    Times();
    ~Times();

    void update();
    float getDeltaTime() const;
    float getFPS() const;
};
