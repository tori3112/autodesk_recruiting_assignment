#include <string>

class Item {
public:
    // TODO: move semantics?
    // Item() = default;
    // ~Item() = default;
    // other constructors as needed
    Item(std::string newName, int newQuantity, double newPrice);
    Item(std::string newName, double newPrice);

    std::string getItemID() const { return itemID; };
    // void setItemID(std::string newItemID); // we shouldn't change IDs after initialisation

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

protected:
    static int ID;
};
