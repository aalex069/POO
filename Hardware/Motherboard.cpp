#include "Motherboard.h"
#include <iostream>

Motherboard::Motherboard() {}
Motherboard::Motherboard(std::string b, std::string m, std::string s, std::string r, int p, int pr) : brand(b), model(m), socket(s), ram(r), power(p), price(pr) {}

std::string Motherboard::getSocket() const
{
    return socket;
}
std::string Motherboard::getRAM() const
{
    return ram;
}
int Motherboard::getPower() const
{
    return power;
}
int Motherboard::getPrice() const
{
    return price;
}
void Motherboard::print() const
{
    std::cout << brand << " " << model << " " << price << "$ " << "(Socket: " << socket << ")\n";
}
