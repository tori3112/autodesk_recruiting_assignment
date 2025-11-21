
#include "inventory.h"

int main()
{
    // std::cout << "Creating items..." << std::endl;

    // auto i1 = new Item("peony", 2.5);
    // auto i2 = new Item("carnation", 10, 3.5);
    // auto i3 = new Item("daffodil", 3, 1.5);

    // std::cout << "Creating the inventory..." << std::endl;
    Inventory inventory;
    // inventory->addItem(*i1);
    // inventory->addItem(*i2);
    // inventory->addItem(*i3);

    // inventory->display();

    // inventory->removeItem("2");
    // inventory->display();

    // inventory->updateQuantity("1", 12);
    // inventory->display();

    inventory.readFile("flower_list.txt");
    inventory.display();

    inventory.saveToFile("inventory_status.txt");
    return 0;
}
