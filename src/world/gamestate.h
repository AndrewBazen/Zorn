#pragma once

#include "bag.h"
#include "area.h"
#include "item.h"
#include "puzzle.h"
#include <string>
#include <map>
#include <vector>


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
        std::map<std::string, Puzzle> puzzles;
        std::map<std::string, Item> items;

        Area& here();
        void loadItems();
        void loadAreas();
        void loadPuzzles();
        void moveTo(const std::string&);
        void nextTurn();
        void runPuzzle(const std::string&);
        void handleTimedEvents();
        bool allArtifactsFound() const;
        std::string describe(const Area&) const;
};