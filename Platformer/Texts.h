#pragma once
#include "Fonts.h"
#include <sstream>

class Texts : public sf::Text
{
private:
    std::string originalStr;
    Fonts *fonts;

    void initFont(std::string font_adress);
    void initString(std::string str);

public:
    Texts(std::string str, std::string font_address);
    ~Texts();

    void streamText(const std::string str, float var, const sf::Vector2f &pos);
};