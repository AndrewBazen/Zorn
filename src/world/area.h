#pragma once

#include <string>
#include "action.h"
#include <map>

struct Area {
    std::string description;
    std::string visitedDescription;
    std::map<std::string, std::string> exits;
    std::map<std::string, Action> actions;   // verb+noun -> what that interaction does
    bool visited = false;   // have we been here before? (gates full vs. brief description)
};