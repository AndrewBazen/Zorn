#pragma once

#include "item.h"
#include <map>
#include <string>

class Bag {
    public:
        void add(const Item&);

        bool has(const std::string&) const;

        int getUses(const std::string&) const;

        void use(const std::string&);    

        void list_contents() const;

    private:
        std::map<std::string, Item> contents;
};
