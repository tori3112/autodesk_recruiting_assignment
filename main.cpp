#include "inventory.h"
#include <iostream>
#include <sstream>
#include <cctype>

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

void printHelp() { // TODO: improve commands instructions
    std::cout << "Commands:\n"
              << "\tadd\t\t - add an item,\n"
              << "\tremove\t\t - removes an item by IT,\n"
              << "\tupdate\t\t - updates quantity of an item, \n"
              << "\tdisplay\t\t - shows all items in the invetory,\n"
              << "\tread\t\t - reads items from file,\n"
              << "\tsave\t\t - saves current inventory to a file,\n"
              << "\thighest\t\t - finds and shows an item with the highest price,\n"
              << "\tbelow\t\t - finds and shows items below specific price,\n"
              << "\texit\t\t - quits the program" << std::endl;
}

int main()
{

    Inventory inventory;
    std::string command;

    std::cout << "---------------Inventory CLI---------------" << std::endl;
    std::cout << "Type 'help' for available commands:)" << std::endl;

    while (1) {
        std::cout << "> "; // to show I'm waiting for the command and not processing

        if (!std::getline(std::cin, command)) {
            std::cerr << "Input closed and exit.";
                break;
        }

        std::stringstream ss(command);
        std::vector<std::string> line;;
        std::string word;

        while (std::getline(ss, word, ' ')) {
            line.push_back(word);
        }

        if (line[0] == "help") {
            printHelp();
        } else if (line[0] == "add") {
            if (line.size() == 3) {
                // add <item name> <item price>
                auto name = line[1];                // expect std::string
                auto price = line[2];               // expect double

                if (canBeDouble(price)) {
                    auto item = std::make_shared<Item>(name, std::stod(price));
                    inventory.addItem(item);
                } else {
                    std::cout << "Given price in unrecognised standard: " << price << std::endl;
                }

            } else if (line.size() == 4) {
                // add <item name> <item quantity> <item price>
                auto name = line[1];                // expect std::string
                auto quantity = line[2]; // expect int
                auto price = line[3];    // expect double

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
        } else if (line[0] == "remove") {
            if (line.size() != 2) {
                std::cout << "Wrong number of arguments." << std::endl;
            } else {
                auto id = line[1];
                inventory.removeItem(id);
            }
        } else if (line[0] == "display") {
            inventory.display();
        } else if (line[0] == "read") {
            if (line.size() != 2) {
                std::cout << "Please specify target file." << std::endl;
            } else {
                auto filename = line[1];
                inventory.readFile(filename);
            }
        } else if (line[0] == "save") {
            if (line.size() != 2) {
                std::cout << "Please specify target file." << std::endl;
            } else {
                auto filename = line[1];
                inventory.saveToFile(filename);
            }
        } else if (line[0] == "highest") {
            auto highest = inventory.findHighestPrice();
            std::cout << "Found highest price item: " << highest->getInfo();
        } else if (line[0] == "below") {
            // TODO: what if user puts threshold as a non-numeric
            if (line.size() != 2) {
                std::cout << "Wrong number of arguments." << std::endl;
            } else {
                auto threshold = line[1];
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
        } else if (line[0] == "exit") {
            break;
        }
    }

    return 0;
}
