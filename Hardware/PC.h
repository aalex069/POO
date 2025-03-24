#ifndef PC_H
#define PC_H

#include "CPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "Storage.h"
#include "PSU.h"
#include "GPU.h"

class Depot;

class PC
{
private:
    CPU cpu;
    Motherboard motherboard;
    RAM ram;
    Storage storage;
    PSU psu;
    GPU gpu;
    bool hasCPU, hasMotherboard, hasRAM, hasStorage, hasPSU, hasGPU;
    Depot *depot;

public:
    PC();
    void linkDepot(Depot *d);
    bool hasCpu() const;
    bool hasMb() const;
    bool hasRam() const;
    bool hasStorageDevice() const;
    bool hasPsu() const;
    bool hasGpu() const;
    CPU getCPU() const;
    Motherboard getMotherboard() const;
    RAM getRAM() const;
    Storage getStorage() const;
    PSU getPSU() const;
    GPU getGPU() const;
    void setCPU(const CPU &c);
    void setMotherboard(const Motherboard &m);
    void setRAM(const RAM &r);
    void setStorage(const Storage &s);
    void setPSU(const PSU &p);
    void setGPU(const GPU &g);
    void removeCPUtoDepot();
    void removeMotherboardToDepot();
    void removeRAMtoDepot();
    void removeStorageToDepot();
    void removePSUtoDepot();
    void removeGPUtoDepot();
    int getTotalPowerDraw() const;
    int getTotalPrice() const;
    void printConfig() const;

    friend class Depot;
};

#endif
