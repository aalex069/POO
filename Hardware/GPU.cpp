#include "GPU.h"
#include <iostream>

GPU::GPU() {}
GPU::GPU(std::string b, std::string m, int p, int pr, int per) : brand(b), model(m), power(p), price(pr), performance(per) {}

int GPU::getPower() const
{
    return power;
}
int GPU::getPrice() const
{
    return price;
}
int GPU::getPerformance() const
{
    return performance;
}
void GPU::print() const
{
    std::cout << brand << " " << model << " " << power << "W " << price << "$" << "\n";
}
