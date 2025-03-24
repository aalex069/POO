#ifndef COMPATIBILITYH
#define COMPATIBILITY_H

#include "CPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "PSU.h"
#include "PC.h"

class CompatibilityChecker
{
public:
    static bool cpuMotherboard(const CPU &cpu, const Motherboard &mb);
    static bool ramMotherboard(const RAM &ram, const Motherboard &mb);
    static bool psuSupports(const PC &pc);
};

#endif