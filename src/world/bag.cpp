#include "bag.h"
#include <iostream>

void Bag::add(const Item& item) {
    contents.insert({item.id, item});
}

bool Bag::has(const std::string& id) const {
    return contents.contains(id) ? true : false;
}

int Bag::getUses(const std::string& id) const {
    return contents.at(id).usesLeft;
}

void Bag::use(const std::string& id) {
    --contents.at(id).usesLeft;
}

void Bag::list_contents() const {
    std::cout << "----Bag Contents----\n";  
    for (const auto& [id, item] : contents) {
        std::cout << "  " << item.name << "\n";
    }
}