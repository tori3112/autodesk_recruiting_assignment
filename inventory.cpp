#include "inventory.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

Inventory::Inventory() {}

void Inventory::addItem(Item* newItem) {
    auto it = std::ranges::find_if(objects.begin(), objects.end(), [newItem](const auto& object) {return newItem->getItemID() == object->getItemID(); }  );
    if (it != objects.end()) {
        std::cout << "Item: " << newItem->getName()
                  <<" already in the inventory." << std::endl;
        return;
    }
    objects.emplace_back(newItem);
    std::cout << "Added: " << newItem->getName()
              << ", total now: " << objects.size() << std::endl;
}

void Inventory::removeItem(const std::string itemID) {
    std::erase_if(objects, [&](auto object) {return object->getItemID() == itemID;});
}

void Inventory::updateQuantity(const std::string itemID, int newQuantity) {
    auto it = std::ranges::find_if(objects.begin(), objects.end(), [itemID](const auto& object) {return object->getItemID() == itemID; });
    if (it != objects.end()) {
        (*it)->setQuantity(newQuantity);
        return;
    }
    std::cout << "Item with ID " << itemID << " not in the inventory." << std::endl;
}

void Inventory::display() {
    for (const auto object : objects) {
        std::cout << object->printInfo();
    }
    std::cout << "DONE-----printed " << objects.size() << " objects in the inventory" << std::endl;
}


void Inventory::readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Couldn't open a file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        // std::cout << line << std::endl;
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;

        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }

        auto name = row[1];
        auto quantity = std::stoi(row[2]);
        auto price = std::stod(row[3]);

        Item item(name, quantity, price);

        this->addItem(&item);
        display();
    }
    file.close();

}

void Inventory::saveToFile(std::string filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Couldn't make a file: " << filename << std::endl;
        return;
    }

    for (auto const& object : objects) {
        // file << "Item ID: " << object->getItemID()
        //      << ", Name: " << object->getName()
        //      << ", Quantity: " << object->getQuantity()
        //      << ", Price: " << object->getPrice() << "\n";
        file << object->printInfo();
    }

    file.close();
}

Item* Inventory::findHighestPrice() {
    std::sort(objects.begin(), objects.end(), [] (auto a, auto b) {
        return a->getPrice() > b->getPrice();
    } );
    return objects[0];
}

std::vector<Item*> Inventory::findItemsBelowThreshold(double threshold) {
    std::vector<Item*> belowThreshold;
    for (const auto& object : objects) {
        if (object->getPrice() < threshold) {
            belowThreshold.push_back(object);
        }
    }
    return belowThreshold;
}

