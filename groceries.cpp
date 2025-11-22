#include "groceries.h"

Groceries::Groceries(std::string newName, int newQuantity, double newPrice, std::string newOrigin): Item(newName, newQuantity, newPrice), origin(newOrigin) {}

Groceries::Groceries(std::string newName, double newPrice, std::string newOrigin): Item(newName, newPrice), origin(newOrigin) {};

std::string Groceries::getInfo() const {
    return "Item ID: " + this->getItemID()
        + ", Name: " + this->getName()
        + ", Quantity: " + std::to_string(this->getQuantity())
        + ", Price: " + std::to_string(this->getPrice())
        + ", Origin: " + this->getOrigin() + "\n";
}
