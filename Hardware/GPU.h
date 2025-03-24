#ifndef GPU_H
#define GPU_H

#include <string>

class GPU
{
private:
    std::string brand, model;
    int power, price, performance;

public:
    GPU();
    GPU(std::string b, std::string m, int p, int pr, int per);
    int getPower() const;
    int getPrice() const;
    int getPerformance() const;
    void print() const;
};

#endif
