#ifndef PSU_H
#define PSU_H

class PSU
{
private:
    int power, price;

public:
    PSU();
    PSU(int p, int pr);
    int getPower() const;
    int getPrice() const;
    void print() const;
};

#endif
