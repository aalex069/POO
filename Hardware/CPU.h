#ifndef CPU_H
#define CPU_H

#include <string>

class CPU
{
private:
    std::string brand, model, socket;
    int power, price, performance;

public:
    CPU();
    CPU(std::string b, std::string m, std::string s, int p, int pr, int per);
    std::string getSocket() const;
    int getPower() const;
    int getPrice() const;
    int getPerformance() const;
    void print() const;
};

#endif
