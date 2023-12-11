#include <iostream>
#include <vector>

// Abstract class
class Item {
protected:
    std::string name;
    int id;
public:
    Item(std::string name, int id) : name(name), id(id) {}
    virtual void display() = 0; // Pure virtual function
};

// PhysicalItem class
class PhysicalItem : public Item {
public:
    PhysicalItem(std::string name, int id) : Item(name, id) {}
    void display() override {
        std::cout << "Physical Item: " << name << ", ID: " << id << std::endl;
    }
};

// DigitalItem class
class DigitalItem : public Item {
public:
    DigitalItem(std::string name, int id) : Item(name, id) {}
    void display() override {
        std::cout << "Digital Item: " << name << ", ID: " << id << std::endl;
    }
};

// Storage class
class Storage {
private:
    std::vector<Item*> items; // Adjacency list
public:
    void addItem(Item* item) {
        items.push_back(item);
    }
    void displayItems() {
        for (Item* item : items) {
            item->display();
        }
    }
};

int main() {
    Storage storage;
    PhysicalItem book("Book", 1);
    DigitalItem ebook("Ebook", 2);
    storage.addItem(&book);
    storage.addItem(&ebook);
    storage.displayItems();
    return 0;
}