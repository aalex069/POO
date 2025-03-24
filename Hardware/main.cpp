#include "Depot.h"
#include "populate_depot.h"
#include "PC.h"
#include "menu.h"
#include <iostream>

/*
    Acest program are ca scop simularea procesului de construire a unui PC, permitand utilizatorului sa aleaga si sa instaleze componente
    dintr-un depozit virtual. La fiecare pas, se verifica compatibilitatea intre componente, iar fiecare piesa are si un pret asociat.
    Singurele date de intrare sunt componenetele din depozit.
    Utilizatorul poate:
        - Vizualiza configuratia PC-ului;
        - Vizualiza toate componentele disponibile din depozit;
        - Adauga/Elimina componente;
        - Verifica pretul total si energia consumata a PC-ului;

*/
int main()
{
    PC pc;
    Depot depot;
    pc.linkDepot(&depot);

    populateDepot(depot);

    menu(pc, depot);

    return 0;
}
