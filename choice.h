#pragma once

#include <variant>
#include <string>

struct Navigate { std::string destination; };
struct InitiatePuzzle { std::string puzzleId; };
struct Choice {
    std::string label;
    std::variant<Navigate, InitiatePuzzle> effect;
};