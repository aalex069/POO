#include "CPU.h"
#include <iostream>

CPU::CPU() {}
CPU::CPU(std::string b, std::string m, std::string s, int p, int pr, int per) : brand(b), model(m), socket(s), power(p), price(pr), performance(per) {}

std::string CPU::getSocket() const
{
    return socket;
}
int CPU::getPower() const
{
    return power;
}
int CPU::getPrice() const
{
    return price;
}
int CPU::getPerformance() const
{
    return performance;
}
void CPU::print() const
{
    std::cout << brand << " " << model << " " << power << "W " << price << "$ " << "(Socket: " << socket << ")\n";
}
