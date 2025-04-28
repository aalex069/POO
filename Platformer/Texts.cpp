#include "Texts.h"
#include <sstream>

Texts::Texts(const std::string &str, const sf::Font &font)
    : sf::Text(font, str, 30) // setezi default character size 30
{
    this->setFillColor(sf::Color::White);
}

void Texts::streamText(const std::string &prefix, float var, const sf::Vector2f &pos)
{
    std::stringstream ss;
    ss << prefix << var;
    this->setString(ss.str());
    this->setPosition(pos);
}
