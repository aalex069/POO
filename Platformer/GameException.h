#pragma once
#include <exception>
#include <string>

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