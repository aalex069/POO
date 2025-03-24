#include "RAM.h"
#include <iostream>

RAM::RAM() {}
RAM::RAM(int cap, int s, int c, std::string t, int p, int pr, int per) : capacity(cap), speed(s), cl(c), type(t), power(p), price(pr), performance(per) {}

std::string RAM::getType() const
{
    return type;
}
int RAM::getPower() const
{
    return power;
}
int RAM::getPrice() const
{
    return price;
}
int RAM::getPerformance() const
{
    return performance;
}
void RAM::print() const
{
    std::cout << capacity << "GB " << speed << "MTs CL" << cl << " " << type << " " << price << "$\n";
}
