#pragma once

#include <string>
#include <vector>
#include "choice.h"

struct Area {
    std::string description;
    std::string visitedDescription;
    std::vector<Choice> choices;
    bool solved = false;
    bool visited = false;
};