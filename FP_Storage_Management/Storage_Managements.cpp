#include <iostream>
#include <vector>

using namespace std;

// Abstract class
class Item {
protected:
    string name;
    int id;
public:
    Item(string name, int id) : name(name), id(id) {}
    virtual void display() = 0; // Pure virtual function
};

// PhysicalItem class
class PhysicalItem : public Item {
public:
    PhysicalItem(string name, int id) : Item(name, id) {}
    void display() override {
        cout << "Physical Item: " << name << ", ID: " << id << endl;
    }
};

// DigitalItem class
class DigitalItem : public Item {
public:
    DigitalItem(string name, int id) : Item(name, id) {}
    void display() override {
        cout << "Digital Item: " << name << ", ID: " << id << endl;
    }
};

// Storage class
class Storage {
private:
    vector<Item*> items; // Adjacency list
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
    int input, menuInput, itemId;
    string itemName;
    while(1){
        Storage storage;
        cout << "===== Menu =====" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Delete Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Display Item" << endl;
        cin >> input;
        
        if (input == 1 ){
            cout << "===== Select =====" << endl;
            cout << "1. Digital Item" << endl;
            cout << "2. Physical Item" << endl;
            cin >> menuInput;
            if (menuInput == 1){
                cout << "Enter item's id . . ." << endl;
                cin >> itemId;
                cout << "Enter item's name  . . ." << endl;
                cin >> itemName;
                DigitalItem* digitalItem = new DigitalItem(itemName, itemId);
                storage.addItem(digitalItem);
            } else if (menuInput == 2){
                cout << "Enter item's id . . ." << endl;
                cin >> itemId;
                cout << "Enter item's name  . . ." << endl;
                cin >> itemName;
                PhysicalItem* physicalItem = new PhysicalItem(itemName, itemId);
                storage.addItem(physicalItem);
            }
        } else if (input == 2){
            cout << "===== Select =====" << endl;
            cout << "1. Digital Item" << endl;
            cout << "2. Physical Item" << endl;
        } else if (input == 3){
            cout << "===== Select =====" << endl;
            cout << "1. Digital Item" << endl;
            cout << "tes" << endl;
        } else if (input == 4){
            storage.displayItems();
        } 
    }
    
    // Storage storage;
    // PhysicalItem book("Book", 1);
    // DigitalItem ebook("Ebook", 2);
    // storage.addItem(&book);
    // storage.addItem(&ebook);
    // storage.displayItems();
    return 0;
}