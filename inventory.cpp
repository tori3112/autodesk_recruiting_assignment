#include "inventory.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory>

Inventory::Inventory() {}

void Inventory::addItem(std::shared_ptr<Item> newItem) {
    auto it = std::ranges::find_if(objects, [&](const auto& object) {
        return newItem->getItemID() == object->getItemID();
    }  );

    if (it != objects.end()) {
        std::cout << "Item: " << newItem->getName()
                  <<" already in the inventory." << std::endl;
        return;
    }

    objects.push_back(std::move(newItem));
    std::cout << "Added: " << objects.back()->getName()
              << ", total now: " << objects.size() << std::endl;
}

void Inventory::removeItem(const std::string& itemID) {
    std::erase_if(objects, [&](const auto& object) {
        return object->getItemID() == itemID;
    });
}

void Inventory::updateQuantity(const std::string& itemID, int newQuantity) {
    auto it = std::ranges::find_if(objects.begin(), objects.end(), [itemID](const auto& object) {
        return object->getItemID() == itemID;
    });

    if (it != objects.end()) {
        (*it)->setQuantity(newQuantity);
        return;
    }

    std::cout << "Item with ID " << itemID << " not in the inventory." << std::endl;
}

void Inventory::display() const {
    for (const auto object : objects) {
        std::cout << object->getInfo();
    }
    std::cout << "DONE-----printed " << objects.size() << " objects in the inventory." << std::endl;
}


void Inventory::readFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Couldn't open a file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // std::cout << line << std::endl;
        std::stringstream ss(line);
        std::string idStr, nameStr, quantityStr, priceStr;

        // TODO: check if this is better for fixed indices
        std::getline(ss, idStr, ',');
        std::getline(ss, nameStr, ',');
        std::getline(ss, quantityStr, ',');
        std::getline(ss, priceStr, ',');

        int quantityInt = std::stoi(quantityStr);
        double priceDou = std::stod(priceStr);

        auto item = std::make_shared<Item>(nameStr, quantityInt, priceDou);
        addItem(item);
        // display();
    }
    file.close();

}

void Inventory::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Couldn't write file: " << filename << std::endl;
        return;
    }

    for (auto const& object : objects) {
        file << object->getInfo();
    }

    file.close();
}

std::shared_ptr<Item> Inventory::findHighestPrice() const {
    if (objects.empty()) return nullptr;

    auto it = std::ranges::max_element(objects, {}, [](const auto& i) {
        return i->getPrice();
    });

    return *it;
}

std::vector<std::shared_ptr<Item>> Inventory::findItemsBelowThreshold(double threshold) const {
    std::vector<std::shared_ptr<Item>> belowThreshold;
    belowThreshold.reserve(objects.size());

    for (const auto& object : objects) {
        if (object->getPrice() < threshold) {
            belowThreshold.push_back(object);
        }
    }
    return belowThreshold;
}

