#pragma once

#include <string>
#include <map>

struct Area {
    std::string description;
    std::string visitedDescription;
    std::string solvedDescription;
    std::map<std::string, std::string> exits;
    bool visited = false;   // have we been here before? (gates full vs. brief description)
    bool solved = false;    // puzzle state, set by runPuzzle
};