#include "electronics.h"
#include "groceries.h"
#include "inventory.h"
#include <iostream>

int main()
{
    Item i1("flowers", 20, 2.5);
    Groceries g1("apples", 3, 1.5, "Poland");
    Electronics e1("laptop", 2, 699.90, 24);

    Inventory inventory;
    inventory.addItem(i1);
    inventory.addItem(g1);
    inventory.addItem(e1);

    auto highest = inventory.findHighestPrice();
    std::cout << "Highest price found!\n" << highest->printInfo();

    inventory.removeItem("1");
    inventory.readFile("flower_list.txt");
    inventory.display();

    auto below3 = inventory.findItemsBelowThreshold(3.0);
    std::cout << "Below threshold: 3.0" << std::endl;
    for (auto obj : below3) {
        std::cout << obj->printInfo();
    }
    return 0;
}
