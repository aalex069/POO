#include "Texts.h"
#include "Times.h"

Times::Times()
{
    update();
}

Times::~Times()
{
}

void Times::update()
{
    deltaTime = clock.restart().asSeconds();
    totalTime += deltaTime;
    frameCount++;

    if (totalTime >= 1.f)
    {
        fps = frameCount / totalTime;
        frameCount = 0;
        totalTime = 0.f;
    }
}

float Times::getDeltaTime() const
{
    return deltaTime;
}

float Times::getFPS() const
{
    return fps;
}