#include "PC.h"
#include "Depot.h"
#include <iostream>

PC::PC() : hasCPU(false), hasMotherboard(false), hasRAM(false), hasStorage(false), hasPSU(false), hasGPU(false), depot(nullptr) {}

void PC::linkDepot(Depot *d) { depot = d; }

bool PC::hasCpu() const { return hasCPU; }
bool PC::hasMb() const { return hasMotherboard; }
bool PC::hasRam() const { return hasRAM; }
bool PC::hasStorageDevice() const { return hasStorage; }
bool PC::hasPsu() const { return hasPSU; }
bool PC::hasGpu() const { return hasGPU; }

CPU PC::getCPU() const { return cpu; }
Motherboard PC::getMotherboard() const { return motherboard; }
RAM PC::getRAM() const { return ram; }
Storage PC::getStorage() const { return storage; }
PSU PC::getPSU() const { return psu; }
GPU PC::getGPU() const { return gpu; }

void PC::setCPU(const CPU &c)
{
    cpu = c;
    hasCPU = true;
}
void PC::setMotherboard(const Motherboard &m)
{
    motherboard = m;
    hasMotherboard = true;
}
void PC::setRAM(const RAM &r)
{
    ram = r;
    hasRAM = true;
}
void PC::setStorage(const Storage &s)
{
    storage = s;
    hasStorage = true;
}
void PC::setPSU(const PSU &p)
{
    psu = p;
    hasPSU = true;
}
void PC::setGPU(const GPU &g)
{
    gpu = g;
    hasGPU = true;
}

void PC::removeCPUtoDepot()
{
    if (hasCPU && depot)
    {
        depot->addCPU(cpu);
        hasCPU = false;
    }
}

void PC::removeMotherboardToDepot()
{
    if (hasMotherboard && depot)
    {
        depot->addMotherboard(motherboard);
        hasMotherboard = false;
    }
}

void PC::removeRAMtoDepot()
{
    if (hasRAM && depot)
    {
        depot->addRAM(ram);
        hasRAM = false;
    }
}

void PC::removeStorageToDepot()
{
    if (hasStorage && depot)
    {
        depot->addStorage(storage);
        hasStorage = false;
    }
}

void PC::removePSUtoDepot()
{
    if (hasPSU && depot)
    {
        depot->addPSU(psu);
        hasPSU = false;
    }
}

void PC::removeGPUtoDepot()
{
    if (hasGPU && depot)
    {
        depot->addGPU(gpu);
        hasGPU = false;
    }
}

int PC::getTotalPowerDraw() const
{
    int total = 150;
    if (hasCPU)
        total += cpu.getPower();
    if (hasMotherboard)
        total += motherboard.getPower();
    if (hasGPU)
        total += int(gpu.getPower() * 1.5);
    if (hasRAM)
        total += ram.getPower();
    if (hasStorage)
        total += storage.getPower();
    return total;
}

int PC::getTotalPrice() const
{
    int total = 0;
    if (hasCPU)
        total += cpu.getPrice();
    if (hasMotherboard)
        total += motherboard.getPrice();
    if (hasGPU)
        total += gpu.getPrice();
    if (hasRAM)
        total += ram.getPrice();
    if (hasStorage)
        total += storage.getPrice();
    if (hasPSU)
        total += psu.getPrice();
    return total;
}

void PC::printConfig() const
{
    std::cout << "=== PC Configuration ===\n";
    if (hasGPU)
        gpu.print();
    else
        std::cout << "No GPU installed\n";
    if (hasCPU)
        cpu.print();
    else
        std::cout << "No CPU installed\n";
    if (hasMotherboard)
        motherboard.print();
    else
        std::cout << "No Motherboard installed\n";
    if (hasRAM)
        ram.print();
    else
        std::cout << "No RAM installed\n";
    if (hasStorage)
        storage.print();
    else
        std::cout << "No Storage installed\n";
    if (hasPSU)
        psu.print();
    else
        std::cout << "No PSU installed\n";
}
