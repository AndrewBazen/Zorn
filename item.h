#pragma once

#include <string>

struct Item {
    std::string name;
    std::string description;
    bool isArtifact;
    int usesLeft;

    Item(std::string n, std::string d, bool a = false, int u = 0) : name(n), description(d), isArtifact(a), usesLeft(u) {}
};