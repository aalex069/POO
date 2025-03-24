#include "Storage.h"
#include <iostream>

Storage::Storage() : size(0) {}
Storage::Storage(std::string t, int s, int p, int pr) : type(t), size(s), power(p), price(pr) {}

int Storage::getPower() const
{
    return power;
}
int Storage::getPrice() const
{
    return price;
}
void Storage::print() const
{
    std::cout << type << ' ' << size << "GB " << price << "$\n";
}
