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
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int newQuantity);

    void display() const;

    void readFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    std::shared_ptr<Item> findHighestPrice() const;
    std::vector<std::shared_ptr<Item>> findItemsBelowThreshold(double threshold) const;
private:
    std::vector<std::shared_ptr<Item>> objects;
};

#endif // INVENTORY_H
