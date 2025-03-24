#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage
{
private:
    std::string type;
    int size, power, price;

public:
    Storage();
    Storage(std::string t, int s, int p, int pr);
    int getPower() const;
    int getPrice() const;
    void print() const;
};

#endif
