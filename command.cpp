#include "command.h"
#include <iostream>

bool canBeInteger(std::string& str);
bool canBeDouble(std::string& str);

void AddCommand::execute() const  {
    if (args.size() == 3) {
        auto name = args[1];                // expect std::string
        auto price = args[2];               // expect double

        if (canBeDouble(price)) {
            auto item = std::make_shared<Item>(name, std::stod(price));
            inventory.addItem(item);
        } else {
            std::cout << "Given price in unrecognised standard: " << price << std::endl;
        }
    } else if (args.size() == 4) {
        auto name = args[1];     // expect std::string
        auto quantity = args[2]; // expect int
        auto price = args[3];    // expect double

        if (canBeInteger(quantity)) {
            if (canBeDouble(price)) {
                auto item = std::make_shared<Item>(name, std::stoi(quantity), std::stod(price));
                inventory.addItem(item);
            } else {
                std::cout << "Given price in unrecognised standard: " << price << std::endl;
            }
        } else {
            std::cout << "Given quantity in unrecognised standard: " << price << std::endl;
        }
    } else {
        std::cout << "Wrong number of arguments." << std::endl;
    }
}

void RemoveCommand::execute() const  {
    if (args.size() != 2) {
        std::cout << "Wrong number of arguments." << std::endl;
    } else {
        auto id = args[1];
        inventory.removeItem(id);
    }
}

void UpdateCommand::execute() const {
    if (args.size() != 3) {
        std::cout << "Wrong number of arguments." << std::endl;
    } else {
        auto itemID = args[1];
        auto newQuantity = args[2];

        if (canBeInteger(newQuantity)) {
            inventory.updateQuantity(itemID, std::stoi(newQuantity));
        } else {
            std::cout << "Unexpected new quantity value: " << newQuantity << std::endl;
        }
    }

};

void DisplayCommand::execute() const {
    inventory.display();
}

void ReadCommand::execute() const {
    if (args.size() != 2) {
        std::cout << "Please specify target file." << std::endl;
    } else {
        auto filename = args[1];
        inventory.readFile(filename);
    }
}

void SaveCommand::execute() const {
    if (args.size() != 2) {
        std::cout << "Please specify target file." << std::endl;
    } else {
        auto filename = args[1];
        inventory.saveToFile(filename);
    }
}

void HighestCommand::execute() const {
    auto highest = inventory.findHighestPrice();
    std::cout << "Found highest price item: " << highest->getInfo();
}

void BelowCommand::execute() const {
    if (args.size() != 2) {
        std::cout << "Wrong number of arguments." << std::endl;
    } else {
        auto threshold = args[1];
        if (canBeDouble(threshold)) {
            auto items = inventory.findItemsBelowThreshold(std::stod(threshold));
            std::cout << "Found " << items.size() << " items below " << threshold << std::endl;
            for (const auto& item : items) {
                std::cout << item->getInfo();
            }
            std::cout << "DONE." << std::endl;
        } else {
            std::cout << "Unnexpected threshold value: " << threshold << std::endl;
        }
    }
}


bool canBeInteger(std::string& str) {
    std::string numbers = "1234567890";
    for (const auto& ch : str) {
        if (numbers.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

bool canBeDouble(std::string& str) {
    int decimal = 0;
    for (auto c : str) {
        if (!std::isdigit(c)) {
            if (c == '.') {
                decimal++;
                if (decimal > 1) return false;
            } else {
                return false;
            }
        }
    }
    return true;
}
