#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory
{
public:
    Inventory() = default;

    bool addItem(const Item& newItem);
    bool removeItem(const std::string itemID);
    bool updateQuantity(const std::string itemID, int newQuantity);

    void display();
private:
    std::vector<Item> objects;
};

#endif // INVENTORY_H
