#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;
struct Product {
    int id;
    string name;
    double price;
    Product* next;

    Product(int id, string name, double price,)
        : id(id), name(name), price(price), next(nullptr) {}
};
struct HashNode {
    int key;
    Product* productPtr; 
    HashNode* next;

    HashNode(int k, Product* p) : key(k), next(nullptr) {}
};

class InventorySystem {
private:
    Product* head;
    Product* tail;
    vector<HashNode*> hashTable;

    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

public:
    InventorySystem() : head(nullptr), tail(nullptr) {
        hashTable.resize(TABLE_SIZE, nullptr);
    }

    // Add a new product (O(1) average time)
    void addProduct(int id, string name, double price, int stock) {
        if (searchProduct(id) != nullptr) {
            cout << "Error: Product ID " << id << " already exists.\n";
            return;
        }

        // Insert into Doubly Linked List
        Product* newProd = new Product(id, name, price, stock);
        if (!head) {
            head = tail = newProd;
        } else {
            tail->next = newProd;
            newProd->prev = tail;
            tail = newProd;
        }

        // Insert into Hash Table (Chaining)
        int index = hashFunction(id);
        HashNode* newHashNode = new HashNode(id, newProd);
        newHashNode->next = hashTable[index];
        hashTable[index] = newHashNode;

        cout << "Added: " << name << " (ID: " << id << ")\n";
    }

    // Fast lookup via Hash Table (O(1) average time)
    Product* searchProduct(int id) {
        int index = hashFunction(id);
        HashNode* current = hashTable[index];
        while (current != nullptr) {
            if (current->key == id) {
                return current->productPtr;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Update product details (O(1) average time)
    void updateProduct(int id, double newPrice, int newStock) {
        Product* prod = searchProduct(id);
        if (!prod) {
            cout << "Product ID " << id << " not found.\n";
            return;
        }
        prod->price = newPrice;
        prod->stock = newStock;
        cout << "Updated ID " << id << ": Price = $" << newPrice << ", Stock = " << newStock << "\n";
    }

    // Remove discontinued product (O(1) average time)
    void removeProduct(int id) {
        int index = hashFunction(id);
        HashNode* currHash = hashTable[index];
        HashNode* prevHash = nullptr;

        // Find and remove from Hash Table
        while (currHash != nullptr && currHash->key != id) {
            prevHash = currHash;
            currHash = currHash->next;
        }

        if (!currHash) {
            cout << "Product ID " << id << " not found.\n";
            return;
        }

        if (prevHash) {
            prevHash->next = currHash->next;
        } else {
            hashTable[index] = currHash->next;
        }

        Product* target = currHash->productPtr;
        delete currHash;

        // Unlink and delete from Doubly Linked List
        if (target->prev) target->prev->next = target->next;
        else head = target->next;

        if (target->next) target->next->prev = target->prev;
        else tail = target->prev;

        cout << "Removed: " << target->name << " (ID: " << id << ")\n";
        delete target;
    }

    // Display all available products (O(N) time)
    void displayCatalog() {
        cout << "\n--- Product Catalog ---\n";
        if (!head) {
            cout << "Catalog is empty.\n";
            return;
        }
        Product* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->id
                 << " | Name: " << current->name
                 << " | Price: $" << current->price
                 << " | Stock: " << current->stock << "\n";
            current = current->next;
        }
        cout << "-----------------------\n\n";
    }
};

int main() {
    InventorySystem store;

    store.addProduct(101, "Wireless Mouse", 25.99, 50);
    store.addProduct(111, "Mechanical Keyboard", 89.50, 30); // Collides with 101 (111 % 10 == 1)
    store.addProduct(205, "USB-C Hub", 34.00, 15);

    store.displayCatalog();

    store.updateProduct(111, 79.99, 25);
    store.removeProduct(101);

    store.displayCatalog();

    return 0;
}

