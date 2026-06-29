#include "bag.h"
#include <iostream>

void Bag::add(const Item& item) {
    contents.push_back(item);
}

bool Bag::has(const std::string& id) const {
    for (const Item& item : contents) {
        if (item.id == id) return true;
    }
    return false;
}

void Bag::list_contents() const {
    std::cout << "----Bag Contents----\n";  
    for (const Item& item : contents) std::cout << "  " << item.name << "\n";
}