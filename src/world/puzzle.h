#pragma once

#include <functional>
#include <string>

enum PuzzleResult { Solved, Left, Died };

struct Puzzle { 
    std::function<PuzzleResult()> puzzleFunction;
    std::string rewardItem;
    bool solved = false;
};