#include "populate_depot.h"
#include "Depot.h"

void populateDepot(Depot &depot)
{
    depot.addCPU(CPU("Intel", "i5-10400", "LGA1200", 105, 60, 3));
    depot.addCPU(CPU("Intel", "i7-10700K", "LGA1200", 160, 80, 4));
    depot.addCPU(CPU("Intel", "i9-10900K", "LGA1200", 225, 100, 5));
    depot.addCPU(CPU("AMD", "Ryzen 5 5600X", "AM4", 120, 110, 6));
    depot.addCPU(CPU("AMD", "Ryzen 7 5800X", "AM4", 170, 150, 7));
    depot.addCPU(CPU("AMD", "Ryzen 9 5900X", "AM4", 210, 200, 8));
    depot.addCPU(CPU("Intel", "i3-10100", "LGA1200", 70, 60, 2));
    depot.addCPU(CPU("AMD", "Ryzen 3 3100", "AM4", 60, 40, 1));
    depot.addCPU(CPU("Intel", "i5-12600K", "LGA1700", 200, 200, 9));
    depot.addCPU(CPU("AMD", "Ryzen 7 7700X", "AM5", 120, 320, 10));

    depot.addMotherboard(Motherboard("ASUS", "Prime B460", "LGA1200", "DDR4", 10, 90));
    depot.addMotherboard(Motherboard("Gigabyte", "Z490 AORUS", "LGA1200", "DDR4", 10, 110));
    depot.addMotherboard(Motherboard("MSI", "MAG B460M", "LGA1200", "DDR4", 10, 100));
    depot.addMotherboard(Motherboard("ASRock", "X570 Phantom Gaming", "AM4", "DDR4", 10, 130));
    depot.addMotherboard(Motherboard("ASUS", "TUF Gaming B550", "AM4", "DDR4", 10, 140));
    depot.addMotherboard(Motherboard("MSI", "Z690 Tomahawk", "LGA1700", "DDR5", 10, 180));
    depot.addMotherboard(Motherboard("Gigabyte", "B550 AORUS Elite", "AM4", "DDR4", 10, 130));
    depot.addMotherboard(Motherboard("ASUS", "ROG Crosshair X670E", "AM5", "DDR5", 12, 300));
    depot.addMotherboard(Motherboard("ASRock", "B60M/M.2", "AM5", "DDR5", 10, 120));

    depot.addRAM(RAM(16, 3200, 16, "DDR4", 5, 50, 2));
    depot.addRAM(RAM(16, 3600, 18, "DDR4", 5, 70, 4));
    depot.addRAM(RAM(16, 2666, 16, "DDR4", 5, 40, 1));
    depot.addRAM(RAM(32, 6000, 30, "DDR5", 10, 120, 5));
    depot.addRAM(RAM(32, 4800, 36, "DDR5", 6, 80, 3));

    depot.addStorage(Storage("SSD", 512, 5, 50));
    depot.addStorage(Storage("HDD", 1000, 5, 40));
    depot.addStorage(Storage("NVMe", 1000, 5, 70));
    depot.addStorage(Storage("SSD", 256, 3, 40));
    depot.addStorage(Storage("HDD", 2000, 6, 75));
    depot.addStorage(Storage("NVMe", 2000, 7, 200));

    depot.addGPU(GPU("NVIDIA", "RTX 3060", 180, 300, 4));
    depot.addGPU(GPU("NVIDIA", "RTX 3070", 210, 400, 5));
    depot.addGPU(GPU("NVIDIA", "GTX 1660 Super", 130, 100, 2));
    depot.addGPU(GPU("AMD", "Radeon RX 6700 XT", 200, 300, 6));
    depot.addGPU(GPU("NVIDIA", "GTX 1050 Ti", 80, 60, 1));
    depot.addGPU(GPU("NVIDIA", "RTX 4080", 300, 1200, 7));
    depot.addGPU(GPU("AMD", "Radeon RX 7900 XTX", 425, 1000, 8));
    depot.addGPU(GPU("Intel", "Arc A770", 17, 150, 3));

    depot.addPSU(PSU(550, 60));
    depot.addPSU(PSU(650, 80));
    depot.addPSU(PSU(750, 70));
    depot.addPSU(PSU(850, 150));
    depot.addPSU(PSU(1000, 250));
    depot.addPSU(PSU(1200, 300));
}
