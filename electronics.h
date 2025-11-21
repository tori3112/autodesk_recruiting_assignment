#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "item.h"

class Electronics : public Item
{
public:
    Electronics(std::string newName, int newQuantity, double newPrice, int newWarranty);
    Electronics(std::string newName, double newPrice, int newWarranty);

    int getWarrantyPeriod() const { return warrantyPeriod; };
    void setWarrantyPeriod(int newWarrantyPeriod);

    std::string printInfo() const override;
private:
    int warrantyPeriod;
};

#endif // ELECTRONICS_H
