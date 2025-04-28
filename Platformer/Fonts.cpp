#include "Fonts.h"

void Fonts::initFonts(const std::string &address)
{
    if (!this->openFromFile(address))
    {
        throw FontLoadException(address);
    }
    this->setSmooth(false);
}

Fonts::Fonts(const std::string &address)
{
    initFonts(address);
}

Fonts::~Fonts()
{
}
