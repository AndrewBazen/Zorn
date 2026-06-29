#pragma once

#include "bag.h"
#include "area.h"
#include <string>
#include <vector>


class Gamestate {
    public:
        int currentTurn;
        std::string currentArea;
        
        Bag bag;

        void nextTurn();
        void moveTo(Area);

    private:
        std::map<std::string, Area> gameAreas;
};