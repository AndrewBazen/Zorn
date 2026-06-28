#pragma once

#include <string>
#include <vector>
struct Area {
    std::string name;
    std::string description;
    std::string visitedDescription;
    std::vector<std::string> choices;
    std::vector<std::string> visitedChoices;
    bool solved;
    bool visited;

    Area(std::string n, std::string d, std::string p, std::vector<std::string> c, std::vector<std::string> v, bool s = false, bool i = false) : 
        name(n), description(d), visitedDescription(p), choices(c), visitedChoices(v), solved(s), visited(i) {}
};