#include "electronics.h"
#include "groceries.h"
#include "inventory.h"
#include <iostream>

int main()
{

    std::cout << "Creating items..." << std::endl;
    auto i1 = std::make_shared<Item>("flowers", 20, 2.5);
    auto g1 = std::make_shared<Groceries>("apples", 3, 1.5, "Poland");
    auto e1 = std::make_shared<Electronics>("laptop", 2, 699.90, 24);

    std::cout << "Creating the inventory..." << std::endl;
    Inventory inventory;
    std::cout << "Created inventory." << std::endl;
    inventory.addItem(i1);
    std::cout << "Added item 1." << std::endl;
    inventory.addItem(g1);
    std::cout << "Added item 2." << std::endl;
    inventory.addItem(e1);
    std::cout << "Added item 3." << std::endl;

    auto highest = inventory.findHighestPrice();
    std::cout << "Highest price found!\n" << highest->getInfo();

    inventory.removeItem("1");
    inventory.readFile("flower_list.txt");
    inventory.display();

    auto below3 = inventory.findItemsBelowThreshold(3.0);
    std::cout << "Below threshold: 3.0" << std::endl;
    for (auto obj : below3) {
        std::cout << obj->getInfo();
    }
    return 0;
}
