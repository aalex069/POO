#include "menu.h"
#include "Compatibility.h"
#include <iostream>

void installComponent(PC &pc, Depot &depot)
{
    int type;
    std::cout << "\nInstall which component?\n"
              << "1. CPU\n2. Motherboard\n3. RAM\n4. Storage\n5. GPU\n6. PSU\n> ";
    std::cin >> type;

    switch (type)
    {
    case 1:
        depot.listCompatibleCPUs(pc);
        std::cout << "> Index: ";
        int cpuIndex;
        std::cin >> cpuIndex;
        depot.installCPU(pc, cpuIndex);
        break;
    case 2:
        depot.listCompatibleMotherboards(pc);
        std::cout << "> Index: ";
        int mbIndex;
        std::cin >> mbIndex;
        depot.installMotherboard(pc, mbIndex);
        break;
    case 3:
        depot.listCompatibleRAM(pc);
        std::cout << "> Index: ";
        int ramIndex;
        std::cin >> ramIndex;
        depot.installRAM(pc, ramIndex);
        break;
    case 4:
        depot.listStorageDevices();
        std::cout << "> Index: ";
        int storageIndex;
        std::cin >> storageIndex;
        depot.installStorage(pc, storageIndex);
        break;
    case 5:
        depot.listGPUs();
        std::cout << "> Index: ";
        int gpuIndex;
        std::cin >> gpuIndex;
        depot.installGPU(pc, gpuIndex);
        break;
    case 6:
        depot.listCompatiblePSUs(pc);
        std::cout << "> Index: ";
        int psuIndex;
        std::cin >> psuIndex;
        depot.installPSU(pc, psuIndex);
        break;
    default:
        std::cout << "Invalid option.\n";
    }
}

void removeComponent(PC &pc)
{
    int type;
    std::cout << "\nRemove which component?\n"
              << "1. CPU\n2. Motherboard\n3. RAM\n4. Storage\n5. GPU\n6. PSU\n> ";
    std::cin >> type;

    switch (type)
    {
    case 1:
        pc.removeCPUtoDepot();
        break;
    case 2:
        pc.removeMotherboardToDepot();
        break;
    case 3:
        pc.removeRAMtoDepot();
        break;
    case 4:
        pc.removeStorageToDepot();
        break;
    case 5:
        pc.removeGPUtoDepot();
        break;
    case 6:
        pc.removePSUtoDepot();
        break;
    default:
        std::cout << "Invalid option.\n";
    }
}

void showDepot(Depot &depot, const PC &pc)
{
    depot.listGPUs();
    depot.listCPUs();
    depot.listMotherboards();
    depot.listRAM();
    depot.listStorageDevices();
    depot.listPSUs();
}

void sortDepot(Depot &depot)
{
    int choice;
    std::cout << "\nSort depot by:\n"
              << "1. Price\n"
              << "2. Power Consumption\n"
              << "3. Performance\n"
              << "> ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        depot.sortByPrice();
        std::cout << "Depot sorted by price.\n";
        break;
    case 2:
        depot.sortByPower();
        std::cout << "Depot sorted by power consumption.\n";
        break;
    case 3:
        depot.sortByPerformance();
        std::cout << "Depot sorted by performance";
        break;
    default:
        std::cout << "Invalid option.\n";
    }
}

void menu(PC &pc, Depot &depot)
{
    while (true)
    {
        std::cout << "\n=== PC Builder Menu ===\n"
                  << "1. View PC Configuration\n"
                  << "2. View Depot Inventory\n"
                  << "3. Install Component\n"
                  << "4. Remove Component\n"
                  << "5. Check power draw\n"
                  << "6. Check price\n"
                  << "7. Sort depot\n"
                  << "8. Exit\n"
                  << "> ";
        int choice;
        std::string answer;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            pc.printConfig();
            break;
        case 2:
            showDepot(depot, pc);
            break;
        case 3:
            installComponent(pc, depot);
            break;
        case 4:
            removeComponent(pc);
            break;
        case 5:
            std::cout << "PC power draw:" << pc.getTotalPowerDraw() << "\n";
            break;
        case 6:
            std::cout << "PC price:" << pc.getTotalPrice() << "\n";
            break;
        case 7:
            sortDepot(depot);
            break;
        case 8:
            std::cout << "\n=== Final Compatibility Check ===\n";

            if (pc.hasCpu() && pc.hasMb() &&
                !CompatibilityChecker::cpuMotherboard(pc.getCPU(), pc.getMotherboard()))
            {
                std::cout << "Incompatibility: CPU and motherboard socket mismatch.\n";
                break;
            }

            if (pc.hasRam() && pc.hasMb() &&
                !CompatibilityChecker::ramMotherboard(pc.getRAM(), pc.getMotherboard()))
            {
                std::cout << "Incompatibility: RAM type not supported by motherboard.\n";
                break;
            }

            if (pc.hasPsu() && pc.getTotalPowerDraw() > pc.getPSU().getPower())
            {
                std::cout << "Incompatibility: PSU is underpowered.\n";
                break;
            }

            std::cout << "Final PC price: " << pc.getTotalPrice() << "\n";
            std::cout << "Are you satisfied with the PC?\n";
            pc.printConfig();
            std::cout << "\nyes/no\n";
            std::cin >> answer;
            if (answer == "yes")
            {
                std::cout << "I hole you are happy with your configuration!\n";
                return;
            }
            else if (answer == "no")
                std::cout << "Try changing the configuration.\n";
            else
                std::cout << "Invalid option. Try again.\n";
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }
}
