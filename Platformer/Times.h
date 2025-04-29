#pragma once
#include "Texts.h"
#include <SFML/Graphics.hpp>

// Pe moment nu o mai folosesc la nimic, dar am pastrat-o in caz ca o sa am nevoie undeva de numarul de FPS-uri
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
