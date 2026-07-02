#pragma once

#include <string>

struct Item {
    std::string id;             // stable identity — lookups, bag.has, area rewardItem
    std::string name;           // display label — shown to the player
    std::string description;
    bool isArtifact;
    int usesLeft;

    Item(std::string i, std::string n, std::string d, bool a = false, int u = 0)
        : id(i), name(n), description(d), isArtifact(a), usesLeft(u) {}
};