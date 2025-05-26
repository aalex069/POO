#pragma once
#include <SFML/Graphics.hpp>

// Este folosita pentru textul jocului
template <typename T>
class Texts : public sf::Text
{
private:
    T prefix;

public:
    Texts(const T &prefixValue, const sf::Font &font)
        : sf::Text(font, "", 30), prefix(prefixValue)
    {
        this->setFillColor(sf::Color::White);
    }

    void streamText(float var, const sf::Vector2f &pos)
    {
        std::stringstream ss;
        ss << prefix << var;
        this->setString(ss.str());
        this->setPosition(pos);
    }
};
