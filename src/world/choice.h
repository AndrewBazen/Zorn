#pragma once

#include <variant>
#include <string>

struct Navigate { std::string destination; };
struct InitiatePuzzle { 
    std::string puzzleId; 
    std::string rewardItem;
    std::string onSolve;
};
struct Choice {
    std::string label;
    using Effect = std::variant<Navigate, InitiatePuzzle>;
    Effect effect;
};