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
        std::vector<Area> gameAreas;
};