#include "command.h"
#include "inventory.h"
#include <iostream>
#include <sstream>
#include <cctype>

void printHelp();
std::unique_ptr<Command> createCommand(const std::string name, Inventory& inventory, std::vector<std::string>& args);

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

        auto cmd = line[0];
        if (cmd == "exit") break;
        if (cmd == "help") {
            printHelp();
            continue;
        }

        auto command = createCommand(cmd, inventory, line);
        if (!command) {
            std::cout << "Unrecognised command: " << cmd << std::endl;
            continue;
        }
        command->execute();
    }

    return 0;
}

std::unique_ptr<Command> createCommand(const std::string name, Inventory& inventory, std::vector<std::string>& args) {
    if (name == "add") return std::make_unique<AddCommand>(inventory, args);
    if (name == "remove") return std::make_unique<RemoveCommand>(inventory, args);
    if (name == "update") return std::make_unique<UpdateCommand>(inventory, args);
    if (name == "display") return std::make_unique<DisplayCommand>(inventory, args);
    if (name == "read") return std::make_unique<ReadCommand>(inventory, args);
    if (name == "save") return std::make_unique<SaveCommand>(inventory, args);
    if (name == "highest") return std::make_unique<HighestCommand>(inventory, args);
    if (name == "below") return std::make_unique<BelowCommand>(inventory, args);

    return nullptr;
}

void printHelp() {
    std::cout << "Commands:\n"
              << " add <name> <quantity> <price> \t - add an item with name, quantity, price,\n"
              << " add <name> <price> \t\t - add an item with name, price and quantity 0\n"
              << " remove <id> \t\t\t - removes an item by ID,\n"
              << " update <id> <quantity> \t - updates quantity of an item with id, \n"
              << " display \t\t\t - shows all items in the invetory,\n"
              << " read <filename> \t\t - reads items from file,\n"
              << " save <filename> \t\t - saves current inventory to a file,\n"
              << " highest \t\t\t - finds and shows an item with the highest price,\n"
              << " below <threshold> \t\t - finds and shows items below specific price,\n"
              << " exit \t\t\t\t - quits the program" << std::endl;
}
