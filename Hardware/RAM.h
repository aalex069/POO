#ifndef RAM_H
#define RAM_H

#include <string>

class RAM
{
private:
    int speed, cl, power, price, performance, capacity;
    std::string type;

public:
    RAM();
    RAM(int cap, int s, int c, std::string t, int p, int pr, int per);
    std::string getType() const;
    int getPower() const;
    int getPrice() const;
    int getPerformance() const;
    void print() const;
};

#endif
