#pragma once

#include "item.h"
#include <vector>
#include <string>

class Bag {
    public:
        void add(const Item&);

        bool has(const std::string&) const;

        void list_contents() const;

    private:
        std::vector<Item> contents;
};
