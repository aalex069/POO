#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// Este folosita pentru textul jocului
class Texts : public sf::Text
{
public:
    Texts(const std::string &str, const sf::Font &font);
    void streamText(const std::string &prefix, float var, const sf::Vector2f &pos);
};
