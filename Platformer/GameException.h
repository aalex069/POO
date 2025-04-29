#pragma once
#include <exception>
#include <string>

// Clasa GameException permite claselor derivate sa afisese ce mesaj de erroare
// doresc in funtie de tipul erorii. Pe baza ei am implemenat erori de: font,
// nivel si texturi(aceasta doar am declarat-o, pe moment nu este folosita nicaieri)
class GameException : public std::exception
{
protected:
    std::string message;

public:
    explicit GameException(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override { return message.c_str(); }
};

class FontLoadException : public GameException
{
public:
    explicit FontLoadException(const std::string &fontPath)
        : GameException("Font couldn't load: " + fontPath) {}
};

class LevelLoadException : public GameException
{
public:
    explicit LevelLoadException(int level)
        : GameException("Invalid level: " + std::to_string(level)) {}
};

class ResourceLoadException : public GameException
{
public:
    explicit ResourceLoadException(const std::string &texture)
        : GameException("Invalid texture: " + texture) {}
};