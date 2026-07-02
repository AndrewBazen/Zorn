#include "gamestate.h"
#include "parser/parser.h"
#include "puzzles/whitetreepuzzle.h"
#include "world/puzzle.h"
#include <iostream>
#include <string>

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

Gamestate::Gamestate() {
    loadItems();
    loadAreas();
    loadPuzzles();
}

void Gamestate::loadItems() {
    items.emplace("dagger",
        Item("dagger", "Dagger",
            "It's nothing special, but it could come in handy"));
    items.emplace("brilliant-crystal",
        Item("brilliant-crystal", "Brilliant Crystal",
            "A shining white crystal that pulses with warmth and power.", true, 3));
    items.emplace("sword-of-light",
        Item("sword-of-light", "Sword of Light",
            "A longsword with a blade that gives off a white glow.", true));
    items.emplace("ancient-tome",
        Item("ancient-tome", "Ancient Tome",
            "A very dusty and intricately designed book. The ink on the pages seems to have a mind\n"
                " of its own, and you feel vibrations of power eminating from it.", true));
}

void Gamestate::loadAreas() {
    areas.emplace("wolf-statue", Area{
        "You stand before a weathered stone wolf. A Path leads off to either side.\n\n",
        "You're back at the statue of the wolf.\n\n",
        {
            { "west", "white-tree" },
            { "east", "stream"},
        }
    });
    areas.emplace("white-tree", Area{
        "You find yourself in a small clearing with three pure-white\n"
        "leafless trees in the center. The trees are arranged in a triangle, with\n" 
        "a small pedestal in the center. On the pedestal, there is a silver bowl\n" 
        "filled to the brim with a dark red liquid.\n\n",
        "You are back in the clearing with the white trees and the\n" 
                        "pedestal, which is now empty.\n\n",
        {
            { "north", "stream" },
            { "east", "wolf-statue" },
        },
        {
            { "examine trees", "white-tree-puzzle" },
        },
        {
            { "examine pedestal", 
                "You examine the pedestal, and notice that there is a\n" 
                "small inscription carved into the base. It reads: 'To find the\n" 
                "light, follow the path of the stars, and the eternal night will\n" 
                "be banished. You feel a sense of understanding, and know that\n" 
                "the answer lies in the symbols on the trees.\n", }
        }

    });
    areas.emplace("stream", Area{
        "After traveling for what feels like hours, you find yourself at a stream that cuts through the path.\n"
        "The stream is too deep and fast to wade through and it is too wide to jump directly across.\n"
        "There is a small wooden sign off to the edge of the path that has some words written on it, and you can now see\n"
        "that just below the surface of the water, there are stepping stones that lead to the other side.\n\n",
        "You are back at the stream with the stepping stones, a wooden sign still stands to the side.\n\n",
        {
            { "north", "campfire" },
            { "south", "wolf-statue" },
            { "west", "white-tree" },
        },

    });
}

void Gamestate::loadPuzzles() {
   puzzles.emplace("white-tree-puzzle", 
    Puzzle{ whiteTreePuzzle, "brilliant-crystal"});
}

Area& Gamestate::here() {
    return areas.at(currentArea);
}

void Gamestate::nextTurn() {
    ++currentTurn;
}

void Gamestate::moveTo(const std::string& dest) {
    here().visited = true;
    history.push_back(currentArea);
    currentArea = dest;
}

void Gamestate::runPuzzle(const std::string& id) {
    Puzzle& p = puzzles.at(id);
    switch (p.puzzleFunction()) {
        case PuzzleResult::Solved:
            p.solved = true;
            if (!p.rewardItem.empty()) bag.add(items.at(p.rewardItem));
            break;
        case PuzzleResult::Left: break;
        case PuzzleResult::Died: gameOver = true; break;
    }
}

void Gamestate::handleTimedEvents() {
    if (allArtifactsFound()) {

        clearScreen(currentTurn);
        printSlow("You have found all artifacts of power, and are ready to\n"
            "face the darkness that threatens to consume Zorn. You make your\n"
            "way to the heart of the forest, where the evil that lurks in the\n" 
            "shadows awaits. You feel a sense of dread and fear as you approach,\n"
            "but you know that you must be strong and face your fears. You take\n"
            "a deep breath, and step forward into the darkness.\n\n");
        waitForInput();

    } else if (currentTurn == 10) {

        clearScreen(currentTurn);
        printSlow("You have been wandering for hours, but you can't seem to find\n" 
            "your way out of the forest. You feel a strong presence growing closer,\n"
            "and the hairs on the back of your neck begin to stand up.\n\n");
        waitForInput();

    } else if (currentTurn == 20) {

        clearScreen(currentTurn);
        printSlow("You have been wandering for hours, but you can't seem to find\n" 
        "your way out of the forest. You feel a strong presence growing much closer,\n"
        "you hear a long deep howl in the distance and feel as though you are being watched.\n\n");
        waitForInput();

    } else if (currentTurn >= 30) {

        clearScreen(currentTurn);
        printSlow("The wind picks up around you and the trees begin to moan and creak.\n"
            "You feel an overwhelming presence as a titanic wolf with giant fangs,\n"
            "blood red eyes, and pitch black fur makes its way out to the dark trees.\n"
            "You feel a sense of dread and fear as it approaches you, its bloodlust\n"
            "hanging in the air like fog.\n\n");
        printRedAndSlow("You feel the darkness start to press in on you\n\n");

        if (bag.has("brilliant-crystal") && bag.getUses("brilliant-crystal") > 0) {
            printSlow(" but you feel the power of the artifact start to vibrate.\n"
                "You hold it up and the wolf recoils in fear, its eyes wide with terror.\n"
                "You feel a surge of power as the darkness is pushed back, and the\n"
                "wolf howls in pain before disappearing into the shadows.\n\n");
            waitForInput();
            bag.use("brilliant-crystal");

        } else {
            printSlow(" and you feel the darkness start to consume you. As the wolf\n"
                "begins to devour you.\n\n");
            printRedAndSlow("Game Over\n\n");
            waitForInput();
            gameOver = true;
        }
    }
}

bool Gamestate::allArtifactsFound() const {
    for (const auto& [id, item] : items) {
        if (!item.isArtifact) continue;
        if (!bag.has(item.id)) return false;
    }
    return true;
}

std::string Gamestate::describe(const Area& area) const {
    if (!area.visited) return area.description;
    return area.visitedDescription;
}

void Gamestate::run() {
    currentArea = "wolf-statue";
    std::string shownArea;

    while (gameOver == false) {
        if (currentArea != shownArea) {
            std::cout << describe(here());
            shownArea = currentArea;
        }

        handleTimedEvents();

        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line)) { gameOver = true; break; }  // EOF (e.g. Ctrl+Z) → end cleanly
        Command cmd = parseCommand(line);

        Area& area = here();

        std::string verbNounCmd = cmd.verb + " " + cmd.noun;
        auto trigger = area.triggers.find(verbNounCmd);
        auto prompt = area.prompts.find(verbNounCmd);
        if (trigger != area.triggers.end() && puzzles.contains(trigger->second) && !puzzles.at(trigger->second).solved) {
            runPuzzle(trigger->second);
        } else if (prompt != area.prompts.end()) {
            std::cout << prompt->second;
        } else if (cmd.verb == "go") {
            auto it = area.exits.find(cmd.noun);
            if (it == area.exits.end() || !areas.contains(it->second)) { 
                std::cout << "You can't go that way.\n"; 
            } else {
                moveTo(it->second);
            }
        } else if (cmd.verb == "look") {
            std::cout << describe(area);
        } else if (cmd.verb == "quit") {
            gameOver = true;
        } else {
            std::cout << "I don't understand that.\n";
        }

        nextTurn();
    }
}