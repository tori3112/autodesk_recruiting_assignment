#include "electronics.h"

Electronics::Electronics(std::string newName, int newQuantity, double newPrice, int newWarranty): Item(newName, newQuantity, newPrice), warrantyPeriod(newWarranty){}

Electronics::Electronics(std::string newName, double newPrice, int newWarranty): Item(newName, newPrice), warrantyPeriod(newWarranty){}

std::string Electronics::printInfo() const {
    return "Item ID: " + this->getItemID()
        + ", Name: " + this->getName()
        + ", Quantity: " + std::to_string(this->getQuantity())
        + ", Price: " + std::to_string(this->getPrice())
        + ", Warranty Period: " + std::to_string(this->getWarrantyPeriod()) + "\n";
}
