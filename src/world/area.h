#pragma once

#include <string>
#include <map>

struct Area {
    std::string description;
    std::string visitedDescription;
    std::map<std::string, std::string> exits;
    std::map<std::string, std::string> triggers;
    std::map<std::string, std::string> prompts;
    bool visited = false;   // have we been here before? (gates full vs. brief description)
};