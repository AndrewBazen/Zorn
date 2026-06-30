#include "gamestate.h"
#include "choice.h"
#include "puzzles/whitetreepuzzle.h"
#include <iostream>

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
        "You stand before a weathered stone wolf. A Path leads off to either side.",
        "You're back at the statue of the wolf.",
        {
            Choice{ "Take the path to the left", Navigate{"white-tree"} },
            Choice{ "Take the path to the right", Navigate{"stream"} },
        }
    });
    areas.emplace("white-tree", Area{
        "You find yourself in a small clearing with three pure-white\n"
        "leafless trees in the center. The trees are arranged in a triangle, with\n" 
        "a small pedestal in the center. On the pedestal, there is a silver bowl\n" 
        "filled to the brim with a dark red liquid.\n",
        "You are back in the clearing with the white trees and the\n" 
                        "pedestal, which is now empty.\n",
        {
            Choice{ "", Navigate{"white-tree"} },
            Choice{ "Take the path to the right", Navigate{"stream"} },
            Choice{ "Take the path to the rig", Navigate{"stream"} },
            Choice{ "Take the path to the right", Navigate{"stream"} },
        }
    });
}

void Gamestate::loadPuzzles() {
   
}

Area& Gamestate::here() {
    return areas.at(currentArea);
}

void Gamestate::nextTurn() {
    ++currentTurn;
}

void Gamestate::moveTo(const std::string& dest) {
    history.push_back(currentArea);
    currentArea = dest;
}

void Gamestate::applyEffect(const Choice::Effect& e) {
    std::visit(overloaded{
        [&](const Navigate& n)       { moveTo(n.destination); },
        [&](const InitiatePuzzle& p) { runPuzzle(p); },
    }, e);
}

void Gamestate::runPuzzle(const InitiatePuzzle& p) {
    switch (puzzles.at(p.puzzleId)(*this)) {
        case PuzzleResult::Solved:
            here().solved = true;
            if (!p.rewardItem.empty()) bag.add(items.at(p.rewardItem));
            moveTo(p.onSolve);
            break;
        case PuzzleResult::Left: break;
        case PuzzleResult::Died: gameOver = true; break;
    }
}

void Gamestate::handleTimedEvents() {
    // TODO: wolf timer
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

std::vector<std::string> labelsOf(const std::vector<Choice>& c) {
    std::vector<std::string> labels;
    for (const Choice& choice : c) {
        labels.push_back(choice.label);
    }
    return labels;
}

bool Gamestate::allArtifactsFound() const {
    for (const auto& [id, item] : items) {
        if (!item.isArtifact) continue;
        if (!bag.has(item.id)) return false;
    }
    return true;
}

void Gamestate::run() {
    currentArea = "wolf-statue";
    while (gameOver == false) {
        Area& area = here();

        std::cout << (area.visited ? area.visitedDescription
                                   : area.description);
        area.visited = true;

        handleTimedEvents();

        int idx = makeChoice(labelsOf(area.choices));
        applyEffect(area.choices[idx - 1].effect);   // makeChoice is 1-based

        nextTurn();
    }
}