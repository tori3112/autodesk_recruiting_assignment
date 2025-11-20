#include <string>

class Item {
public:
    Item() = default;
    ~Item() = default;
    // TODO: other constructors as needed

    // should ID be changeable?
    // std::string getItemID() const { return itemID; };
    // void setItemID(std::string newItemID);

    std::string getName() const { return name; };
    void setName(std::string newName);

    int getQuantity() const { return quantity; };
    void setQuantity(int newQuantity);
    double getPrice() const { return price; };
    void setPrice(double newPrice);

private:
    std::string itemID;
    std::string name;
    int quantity;
    double price;
};
