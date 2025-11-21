#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory
{
public:
    Inventory();

    void addItem(const Item& newItem);
    void removeItem(const std::string itemID);
    void updateQuantity(const std::string itemID, int newQuantity);

    void display();

    void readFile(const std::string filename);
    void saveToFile(std::string filename);
private:
    std::vector<Item> objects;
};

#endif // INVENTORY_H
