#include "electronics.h"
#include "groceries.h"
#include "inventory.h"

int main()
{
    Item i1("flowers", 20, 2.5);
    Groceries g1("apples", 3, 1.5, "Poland");
    Electronics e1("Laptop", 2, 699.90, 24);

    Inventory inventory;
    inventory.addItem(&i1);
    inventory.addItem(&g1);
    inventory.addItem(&e1);

    inventory.display();

    inventory.removeItem("3");
    inventory.display();

    inventory.updateQuantity("1", 21);
    inventory.display();

    return 0;
}
