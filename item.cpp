#include "item.h"

int Item::ID = 0;

Item::Item(std::string newName, double newPrice): name(newName), price(newPrice) {
    itemID = std::to_string(++Item::ID);
    quantity = 0;
}
Item::Item(std::string newName, int newQuantity, double newPrice): name(newName), quantity(newQuantity), price(newPrice) {
    itemID = std::to_string(++Item::ID);
}

void Item::setName(std::string newName) {
    name = newName;
}

void Item::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Item::setPrice(double newPrice) {
    price = newPrice;
}
