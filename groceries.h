#ifndef GROCERIES_H
#define GROCERIES_H

#include "item.h"

class Groceries : public Item
{
public:
    Groceries(std::string newName, int newQuantity, double newPrice, std::string newOrigin);
    Groceries(std::string newName, double newPrice, std::string newOrigin);

    std::string getOrigin() const { return origin; };
    void setOrigin(std::string newOrigin);

    std::string getInfo() const override;
private:
    std::string origin;
};

#endif // GROCERIES_H
