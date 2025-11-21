#include "electronics.h"

Electronics::Electronics(std::string newName, int newQuantity, double newPrice, int newWarranty): Item(newName, newQuantity, newPrice), warrantyPeriod(newWarranty){}

Electronics::Electronics(std::string newName, double newPrice, int newWarranty): Item(newName, newPrice), warrantyPeriod(newWarranty){}
