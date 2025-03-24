#ifndef DEPOT_H
#define DEPOT_H

#include <vector>
#include "CPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "Storage.h"
#include "GPU.h"
#include "PSU.h"

class PC;

class Depot
{
private:
    std::vector<CPU> cpus;
    std::vector<Motherboard> motherboards;
    std::vector<RAM> ram_sticks;
    std::vector<Storage> storages;
    std::vector<GPU> gpus;
    std::vector<PSU> psus;

public:
    void addCPU(const CPU &c);
    void addMotherboard(const Motherboard &m);
    void addRAM(const RAM &r);
    void addStorage(const Storage &s);
    void addGPU(const GPU &g);
    void addPSU(const PSU &p);

    void installCPU(PC &pc, int index);
    void installMotherboard(PC &pc, int index);
    void installRAM(PC &pc, int index);
    void installStorage(PC &pc, int index);
    void installGPU(PC &pc, int index);
    void installPSU(PC &pc, int index);

    void listCPUs() const;
    void listCompatibleCPUs(const PC &pc) const;
    void listMotherboards() const;
    void listCompatibleMotherboards(const PC &pc) const;
    void listRAM() const;
    void listCompatibleRAM(const PC &pc) const;
    void listStorageDevices() const;
    void listGPUs() const;
    void listPSUs() const;
    void listCompatiblePSUs(const PC &pc) const;

    void sortByPrice();
    void sortByPower();
    void sortByPerformance();
};

#endif
