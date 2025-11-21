#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
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

    std::shared_ptr<Item> findHighestPrice();
    std::vector<std::shared_ptr<Item>> findItemsBelowThreshold(double threshold);
private:
    std::vector<std::shared_ptr<Item>> objects;
};

#endif // INVENTORY_H
