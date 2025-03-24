#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include <string>

class Motherboard
{
private:
    std::string brand, model, socket, ram;
    int power, price;

public:
    Motherboard();
    Motherboard(std::string b, std::string m, std::string s, std::string r, int p, int pr);
    std::string getSocket() const;
    std::string getRAM() const;
    int getPower() const;
    int getPrice() const;
    void print() const;
};

#endif
