#pragma once

#include "bag.h"
#include "area.h"
#include "choice.h"
#include "item.h"
#include "puzzle.h"
#include <string>
#include <map>
#include <vector>
#include <functional>


class Gamestate {
    public:
        Gamestate();
        void run();
    private:
        int currentTurn = 0;
        bool gameOver = false;
        std::string currentArea;
        std::vector<std::string> history;
        Bag bag;
        std::map<std::string, Area> areas;
        std::map<std::string, std::function<PuzzleResult(const Gamestate&)>> puzzles;
        std::map<std::string, Item> items;

        Area& here();
        void loadItems();
        void loadAreas();
        void loadPuzzles();
        void moveTo(const std::string&);
        void nextTurn();
        void applyEffect(const Choice::Effect&);
        void runPuzzle(const InitiatePuzzle&);
        void handleTimedEvents();
        bool allArtifactsFound() const;
};