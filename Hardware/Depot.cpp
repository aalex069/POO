#include "Depot.h"
#include "PC.h"
#include "Compatibility.h"
#include <iostream>
#include <algorithm>

void Depot::addCPU(const CPU &c) { cpus.push_back(c); }
void Depot::addMotherboard(const Motherboard &m) { motherboards.push_back(m); }
void Depot::addRAM(const RAM &r) { ram_sticks.push_back(r); }
void Depot::addStorage(const Storage &s) { storages.push_back(s); }
void Depot::addGPU(const GPU &g) { gpus.push_back(g); }
void Depot::addPSU(const PSU &p) { psus.push_back(p); }

void Depot::installCPU(PC &pc, int index)
{
    if (index >= 0 && index < cpus.size())
    {
        CPU newCPU = cpus[index];
        if (pc.hasMb() && !CompatibilityChecker::cpuMotherboard(newCPU, pc.getMotherboard()))
        {
            std::cout << "Incompatible CPU with current motherboard!\n";
            return;
        }
        pc.removeCPUtoDepot();
        pc.setCPU(newCPU);
        cpus.erase(cpus.begin() + index);
    }
    else
    {
        std::cout << "Invalid option.\n";
    }
}

void Depot::installMotherboard(PC &pc, int index)
{
    if (index >= 0 && index < motherboards.size())
    {
        Motherboard newMB = motherboards[index];
        if (pc.hasCpu() && !CompatibilityChecker::cpuMotherboard(pc.getCPU(), newMB))
        {
            std::cout << "Incompatible Motherboard with current CPU!\n";
            return;
        }
        if (pc.hasRam() && !CompatibilityChecker::ramMotherboard(pc.getRAM(), newMB))
        {
            std::cout << "Incompatible Motherboard with current RAM!\n";
            return;
        }
        pc.removeMotherboardToDepot();
        pc.setMotherboard(newMB);
        motherboards.erase(motherboards.begin() + index);
    }
    else
    {
        std::cout << "Invalid option.\n";
    }
}

void Depot::installRAM(PC &pc, int index)
{
    if (index >= 0 && index < ram_sticks.size())
    {
        RAM newRAM = ram_sticks[index];
        if (pc.hasMb() && !CompatibilityChecker::ramMotherboard(newRAM, pc.getMotherboard()))
        {
            std::cout << "Incompatible RAM type for current motherboard!\n";
            return;
        }
        pc.removeRAMtoDepot();
        pc.setRAM(newRAM);
        ram_sticks.erase(ram_sticks.begin() + index);
    }
    else
    {
        std::cout << "Invalid option.\n";
    }
}

void Depot::installStorage(PC &pc, int index)
{
    if (index >= 0 && index < storages.size())
    {
        pc.removeStorageToDepot();
        pc.setStorage(storages[index]);
        storages.erase(storages.begin() + index);
    }
    else
        std::cout << "Invalid option.\n";
}

void Depot::installGPU(PC &pc, int index)
{
    if (index >= 0 && index < gpus.size())
    {
        pc.removeGPUtoDepot();
        pc.setGPU(gpus[index]);
        gpus.erase(gpus.begin() + index);
    }
    else
        std::cout << "Invalid option.\n";
}

void Depot::installPSU(PC &pc, int index)
{
    if (index >= 0 && index < psus.size())
    {
        PSU newPSU = psus[index];
        if (pc.getTotalPowerDraw() > newPSU.getPower())
        {
            std::cout << "PSU too weak for current configuration!\n";
            return;
        }
        pc.removePSUtoDepot();
        pc.setPSU(newPSU);
        psus.erase(psus.begin() + index);
    }
    else
    {
        std::cout << "Invalid option.\n";
    }
}

void Depot::listCPUs() const
{
    std::cout << "=== Depot CPUs ===\n";
    for (int i = 0; i < cpus.size(); i++)
    {
        std::cout << i << ") ";
        cpus[i].print();
    }
    std::cout << std::endl;
}

void Depot::listCompatibleCPUs(const PC &pc) const
{
    std::cout << "=== Compatible CPUs ===\n";
    for (int i = 0; i < cpus.size(); ++i)
    {
        if (!pc.hasMb() || CompatibilityChecker::cpuMotherboard(cpus[i], pc.getMotherboard()))
        {
            std::cout << i << ") ";
            cpus[i].print();
        }
    }
    std::cout << std::endl;
}

void Depot::listMotherboards() const
{
    std::cout << "=== Depot Motherboards ===\n";
    for (int i = 0; i < motherboards.size(); i++)
    {
        std::cout << i << ") ";
        motherboards[i].print();
    }
    std::cout << std::endl;
}

void Depot::listCompatibleMotherboards(const PC &pc) const
{
    std::cout << "=== Compatible Motherboards ===\n";
    for (int i = 0; i < motherboards.size(); ++i)
    {
        bool compatibleWithCPU = !pc.hasCpu() || CompatibilityChecker::cpuMotherboard(pc.getCPU(), motherboards[i]);
        bool compatibleWithRAM = !pc.hasRam() || CompatibilityChecker::ramMotherboard(pc.getRAM(), motherboards[i]);

        if (compatibleWithCPU && compatibleWithRAM)
        {
            std::cout << i << ") ";
            motherboards[i].print();
        }
    }
    std::cout << std::endl;
}

void Depot::listRAM() const
{
    std::cout << "=== Depot RAM Sticks ===\n";
    for (int i = 0; i < ram_sticks.size(); i++)
    {
        std::cout << i << ") ";
        ram_sticks[i].print();
    }
    std::cout << std::endl;
}

void Depot::listCompatibleRAM(const PC &pc) const
{
    std::cout << "=== Compatible RAM ===\n";
    for (int i = 0; i < ram_sticks.size(); ++i)
    {
        if (!pc.hasMb() || CompatibilityChecker::ramMotherboard(ram_sticks[i], pc.getMotherboard()))
        {
            std::cout << i << ") ";
            ram_sticks[i].print();
        }
    }
    std::cout << std::endl;
}

void Depot::listStorageDevices() const
{
    std::cout << "=== Depot Storage Devices ===\n";
    for (int i = 0; i < storages.size(); i++)
    {
        std::cout << i << ") ";
        storages[i].print();
    }
    std::cout << std::endl;
}

void Depot::listGPUs() const
{
    std::cout << "=== Depot GPUs ===\n";
    for (int i = 0; i < gpus.size(); i++)
    {
        std::cout << i << ") ";
        gpus[i].print();
    }
    std::cout << std::endl;
}

void Depot::listPSUs() const
{
    std::cout << "=== Depot PSUs ===\n";
    for (int i = 0; i < psus.size(); i++)
    {
        std::cout << i << ") ";
        psus[i].print();
    }
    std::cout << std::endl;
}

void Depot::listCompatiblePSUs(const PC &pc) const
{
    int powerNeeded = pc.getTotalPowerDraw();

    std::cout << "=== Compatible PSUs (Needed >= " << powerNeeded << "W) ===\n";
    for (int i = 0; i < psus.size(); ++i)
    {
        if (psus[i].getPower() >= powerNeeded)
        {
            std::cout << i << ") ";
            psus[i].print();
        }
    }
    std::cout << std::endl;
}
void Depot::sortByPrice()
{
    std::sort(cpus.begin(), cpus.end(), [](const CPU &a, const CPU &b)
              { return a.getPrice() < b.getPrice(); });
    std::sort(motherboards.begin(), motherboards.end(), [](const Motherboard &a, const Motherboard &b)
              { return a.getPrice() < b.getPrice(); });
    std::sort(ram_sticks.begin(), ram_sticks.end(), [](const RAM &a, const RAM &b)
              { return a.getPrice() < b.getPrice(); });
    std::sort(storages.begin(), storages.end(), [](const Storage &a, const Storage &b)
              { return a.getPrice() < b.getPrice(); });
    std::sort(gpus.begin(), gpus.end(), [](const GPU &a, const GPU &b)
              { return a.getPrice() < b.getPrice(); });
    std::sort(psus.begin(), psus.end(), [](const PSU &a, const PSU &b)
              { return a.getPrice() < b.getPrice(); });
}

void Depot::sortByPower()
{
    std::sort(cpus.begin(), cpus.end(), [](const CPU &a, const CPU &b)
              { return a.getPower() < b.getPower(); });
    std::sort(ram_sticks.begin(), ram_sticks.end(), [](const RAM &a, const RAM &b)
              { return a.getPower() < b.getPower(); });
    std::sort(storages.begin(), storages.end(), [](const Storage &a, const Storage &b)
              { return a.getPower() < b.getPower(); });
    std::sort(gpus.begin(), gpus.end(), [](const GPU &a, const GPU &b)
              { return a.getPower() < b.getPower(); });
    std::sort(psus.begin(), psus.end(), [](const PSU &a, const PSU &b)
              { return a.getPower() < b.getPower(); });
}

void Depot::sortByPerformance()
{
    std::sort(cpus.begin(), cpus.end(), [](const CPU &a, const CPU &b)
              { return a.getPerformance() > b.getPerformance(); });
    std::sort(gpus.begin(), gpus.end(), [](const GPU &a, const GPU &b)
              { return a.getPerformance() > b.getPerformance(); });
    std::sort(ram_sticks.begin(), ram_sticks.end(), [](const RAM &a, const RAM &b)
              { return a.getPerformance() > b.getPerformance(); });
}
