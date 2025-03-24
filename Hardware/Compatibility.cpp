#include "Compatibility.h"

bool CompatibilityChecker::cpuMotherboard(const CPU &cpu, const Motherboard &mb)
{
    return cpu.getSocket() == mb.getSocket();
}

bool CompatibilityChecker::ramMotherboard(const RAM &ram, const Motherboard &mb)
{
    return ram.getType() == mb.getRAM();
}

bool CompatibilityChecker::psuSupports(const PC &pc)
{
    return !pc.hasPsu() || pc.getPSU().getPower() >= pc.getTotalPowerDraw();
}
