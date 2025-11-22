#include "electronics.h"
#include "groceries.h"
#include "inventory.h"
#include <iostream>
#include <sstream>

void printHelp() {
    std::cout << "Commands:\n"
              << "\tadd\t\t - add an item,\n"
              << "\tremove\t\t - removes an item by IT,\n"
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
                std::string name = line[1];
                double price = std::stod(line[2]);
                auto item = std::make_shared<Item>(name, price);
                inventory.addItem(item);
            } else if (line.size() == 4) {
                // add <item name> <item quantity> <item price>
                std::string name = line[1];
                int quantity = std::stoi(line[2]);
                double price = std::stod(line[3]);
                auto item = std::make_shared<Item>(name, quantity, price);
                inventory.addItem(item);
            } else {
                std::cout << "Wrong number of arguments." << std::endl;
            }
        } else if (line[0] == "remove") {
            if (line.size() != 2) {
                std::cout << "Wrong number of arguments." << std::endl;
            }

            auto id = line[1];
            inventory.removeItem(id);
        } else if (line[0] == "display") {
            inventory.display();
        } else if (line[0] == "read") {

        } else if (line[0] == "save") {
            std::vector<std::string> line;
            std::string word;

            while (std::getline(ss, word, ' ')) {
                line.push_back(word);
            }

            if (line.size() < 2) {
                std::cout << "Please specify target file." << std::endl;
            }
        } else if (line[0] == "highest") {
            auto highest = inventory.findHighestPrice();
            std::cout << "Found highest price item: " << highest->getInfo();
        } else if (line[0] == "below") {
            // TODO: what if user puts threshold as a non-numeric
            if (line.size() != 2) {
                std::cout << "Wrong number of arguments." << std::endl;
            }

            auto threshold = std::stod(line[1]);
            auto items = inventory.findItemsBelowThreshold(threshold);
            std::cout << "Found " << items.size() << " items below " << threshold << std::endl;
            for (const auto& item : items) {
                std::cout << item->getInfo();
            }
            std::cout << "DONE." << std::endl;
        } else if (line[0] == "exit") {
            break;
        }
    }

    return 0;
}
