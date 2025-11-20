#include "inventory.h"
#include <vector>
#include <iostream>

bool Inventory::addItem(const Item& newItem) {
    // check if object's there, return false?
    objects.emplace_back(newItem);
    return true;
}

bool Inventory::removeItem(const std::string itemID) {
    // if the item is not there false, if it is and we can remove true?
    std::erase_if(objects, [&](auto object) {return object.getItemID() == itemID;});
    return true;
}

bool Inventory::updateQuantity(const std::string itemID, int newQuantity) {
    auto it = std::ranges::find_if(objects.begin(), objects.end(), [itemID](const auto& object) {return object.getItemID() == itemID; });
    if (it != objects.end()) {
        it->setQuantity(newQuantity);
        return true;
    }
    return false;
}

void Inventory::display() {
    for (const auto object : objects) {
        std::cout << "Item ID: " << object.getItemID() << ", Name: " << object.getName() << ", Quantity: " << object.getQuantity() << ", Price: " << object.getPrice() << std:: endl;
    }
    std::cout << "DONE-----printed " << objects.size() << " objects in the inventory" << std::endl;
}
