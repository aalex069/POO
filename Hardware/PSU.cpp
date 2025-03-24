#include "PSU.h"
#include <iostream>

PSU::PSU() {}
PSU::PSU(int p, int pr) : power(p), price(pr) {}

int PSU::getPower() const
{
    return power;
}
int PSU::getPrice() const
{
    return price;
}
void PSU::print() const
{
    std::cout << power << "W " << price << "$\n";
}
