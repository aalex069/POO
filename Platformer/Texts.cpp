#include "Texts.h"

void Texts::initFont(std::string font_adress)
{
    fonts = new Fonts(font_adress);
    this->setFont(*fonts);
}

void Texts::initString(std::string str)
{
    originalStr = str;
    this->setString(originalStr);
}

Texts::Texts(std::string str, std::string font_address) : sf::Text(*fonts)
{
    initFont(font_address);
    initString(str);
}

Texts::~Texts()
{
    delete fonts;
}

void Texts::streamText(std::string str, float var, const sf::Vector2f &pos)
{
    std::stringstream sStream;
    sStream << str << var;

    this->setString(sStream.str());
    this->setPosition(pos);
}
