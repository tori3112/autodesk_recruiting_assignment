#include "groceries.h"

Groceries::Groceries(std::string newName, int newQuantity, double newPrice, std::string newOrigin): Item(newName, newQuantity, newPrice), origin(newOrigin) {}

Groceries::Groceries(std::string newName, double newPrice, std::string newOrigin): Item(newName, newPrice), origin(newOrigin) {};
