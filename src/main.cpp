#include "puzzles/whitetreepuzzle.h"
#include "puzzles/campfireriddle.h"
#include "puzzles/streampuzzle.h"
#include "util/utilities.h"
#include "world/gamestate.h"

int main() {
    Gamestate gamestate = new Gamestate();
    bool gameOver = false;

    std::vector<int> campfireChoiceOrder;
    std::vector<std::string> bag = {"Dagger"};
    int usesLeft = 3;



    std::cout << "\n"
        "▒███████▒ ▒█████   ██▀███   ███▄    █\n"
        "▒ ▒ ▒ ▄▀░▒██▒  ██▒▓██ ▒ ██▒ ██ ▀█   █\n" 
        "░ ▒ ▄▀▒░ ▒██░  ██▒▓██ ░▄█ ▒▓██  ▀█ ██▒\n"
        "  ▄▀▒   ░▒██   ██░▒██▀▀█▄  ▓██▒  ▐▌██▒\n"
        "▒███████▒░ ████▓▒░░██▓ ▒██▒▒██░   ▓██░\n"
        "░▒▒ ▓░▒░▒░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░ ▒░   ▒ ▒\n" 
        "░░▒ ▒ ░ ▒  ░ ▒ ▒░   ░▒ ░ ▒░░ ░░   ░ ▒░\n"
        "░ ░ ░ ░ ░░ ░ ░ ▒    ░░   ░    ░   ░ ░\n" 
        "  ░ ░        ░ ░     ░              ░\n" 
        "░\n";                                 

    std::cout << "-------------------------------------------\n";
    std::cout << " Welcome to Zorn, a text adventure game!\n";
    int mainMenuChoice = makeChoice(mainMenuChoices, currentTurn);
    switch (mainMenuChoice) {
        case 1:
            std::cout << "You have chosen to start the game!\n";
            break;
        case 2:
            std::cout << "You have chosen to exit the game!\n";
            std::cout << "Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
    
    clearScreen(currentTurn);
    printSlow("You wake to the sound of leaves rustling in the wind, and find\n" 
        "yourself in a dark forest with tall tress that cover the sky above you..\n"
        "You have no memory of how you got here, or where you are. You see a path\n" 
        "leading to the left, which seems to be giving off a soft white glow,\n" 
        "and a path leading to the right, which looks dark frightening. Directly\n"
        "in front of you, there is a small statue of a wolf, in it's mouth are\n"
        "a piece of paper, and a small bag.\n");

    clearScreen(currentTurn);
    printSlow("You carefully move to the wolf statue. For a moment you think\n"
        "you see its eyes shine red, but maybe it was your imagination. You manage\n"
        "to take the paper and bag.\n"
        "Press any key to continue...\n");
    system("read");

    clearScreen(currentTurn);
    printSlow("You open the paper and read the following:\n"
        "Welcome to Zorn, a world of darkness and tragedy.\n"
        "You have been chosen to save this world from the\n"
        "darkness that threatens to consume it. You must\n"
        "find the 3 artifacts of power, and use them to defeat\n"
        "the evil that lurks in the shadows. Good luck, brave\n"
        "adventurer.\n"
        "Press any key to continue...\n");
    system("read");

    clearScreen(currentTurn);
    printSlow("You open the bag and find a small dagger inside.\n"
        "It looks sharp and well made. You decide to keep it,\n"
        "as it may come in handy.\n"
        "Press any key to continue...\n");
    system("read");

    clearScreen(currentTurn);
    printSlow("Beyond the wolf statue you see a pathleading to the left, which seems to be giving\n"
        "off a soft white glow, and a path leading to the right, which looks\n"
        "dark and frightening.\n");

    currentArea = 1;

    clearScreen(currentTurn);
    std::cout << "You cautiously make your way down the path to the left.\n";

    currentArea = 2;

    clearScreen(currentTurn);
    std::cout << "You have chosen to take the path to the right\n";

    while (gameOver == false) {
        if (allArtifactsFound) {
            clearScreen(currentTurn);
            printSlow("You have found all 3 artifacts of power, and are ready to\n"
                "face the darkness that threatens to consume Zorn. You make your\n"
                "way to the heart of the forest, where the evil that lurks in the\n" 
                "shadows awaits. You feel a sense of dread and fear as you approach,\n"
                "but you know that you must be strong and face your fears. You take\n"
                "a deep breath, and step forward into the darkness.\n"
                "Press any key to continue...\n");
            system("read");
            break;
        } else if (currentTurn == 10) {
            clearScreen(currentTurn);
            printSlow("You have been wandering for hours, but you can't seem to find\n" 
                "your way out of the forest. You feel a strong presence growing closer,\n"
                "and the hairs on the back of your neck begin to stand up.\n"
                "Press any key to continue...\n");
            system("read");
        } else if (currentTurn == 20) {
            clearScreen(currentTurn);
            printSlow("You have been wandering for hours, but you can't seem to find\n" 
            "your way out of the forest. You feel a strong presence growing much closer,\n"
            "you hear a long deep howl in the distance and feel as though you are being watched.\n"
                "Press any key to continue...\n");
            system("read");
        } else if (currentTurn >= 30 && currentTurn % 3 == 0) {
            clearScreen(currentTurn);
            printSlow("The wind picks up around you and the trees begin to moan and creak.\n"
                "You feel an overwhelming presence as a titanic wolf with giant fangs,\n"
                "blood red eyes, and pitch black fur makes its way out to the dark trees.\n"
                "You feel a sense of dread and fear as it approaches you, its bloodlust\n"
                "hanging in the air like fog.\n\n");
            printRedAndSlow("You feel the darkness start to press in on you");
            if (brilliantCrystalFound && usesLeft > 0) {
                printSlow(" but you feel the power of the artifact start to vibrate.\n"
                    "You hold it up and the wolf recoils in fear, its eyes wide with terror.\n"
                    "You feel a surge of power as the darkness is pushed back, and the\n"
                    "wolf howls in pain before disappearing into the shadows.\n"
                    "Press any key to continue...\n");
                system("read");
                usesLeft--;
            } else {
                printSlow(" and you feel the darkness start to consume you. As the wolf\n"
                    "begins to devour your flesh.\n");
                printRedAndSlow("Game Over\n");
                std::cout << "Press any key to continue...\n";
                system("read");
                gameOver = true;
            }
        }
        switch (currentArea) {
            case 0:
                clearScreen(currentTurn);
                    std::cout << "You find yourself back at the statue of the wolf\n";
                    startPathReturnChoice = makeChoice(startAreaChoicesReturn, currentTurn);
                    if (startPathReturnChoice == 1) {
                        currentArea = 2;
                        previousArea = 0;
                    } else if (startPathReturnChoice == 2) {
                        currentArea = 1;
                        previousArea = 0;
                }
                currentTurn++;
                break;
            case 1:
                // White Tree Puzzle
                if (!whiteTreeAreaSolved) {    // If the puzzle has not been solved
                    int result = whiteTreePuzzle(currentTurn);
                    if (result == 0) {
                        gameOver = true;
                    } else if (result == 1){
                        currentArea = 0;
                        previousArea = 1;
                        whiteTreeAreaSolved = true;
                        brilliantCrystalFound = true;
                        if (ancientTomeFound && swordOfLightFound) {
                            allArtifactsFound = true;
                        }
                        bag.push_back("Brilliant Crystal");
                    } else if (result == 2) {
                        currentArea = 0;
                        previousArea = 1;
                    }
                    currentTurn++;
                    break;
                } else {  // If the puzzle has been solved
                    clearScreen(currentTurn);
                    printSlow("You are back in the clearing with the white trees and the\n" 
                        "pedestal, which is now empty.\n");
                    whiteTreeReturnChoice = makeChoice(whiteTreeChoicesReturn, currentTurn);
                    switch (whiteTreeReturnChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You decide to leave the clearing and continue on your journey.\n");
                            currentArea = 0;
                            previousArea = 1;
                            break;
                    }
                    currentTurn++;
                    break;
                }
            case 2:
                if (!streamAreaSolved) {    // If the puzzle has not been solved
                    int result = streamPuzzle(currentTurn);
                    if (result == 0) {
                        gameOver = true;
                    } else if (result == 1){
                        currentArea = 3;
                        previousArea = 2;
                        streamAreaSolved = true;
                    } else if (result == 2) {
                        currentArea = 0;
                        previousArea = 1;
                    }
                    currentTurn++;
                    break;
                } else {  // If the puzzle has been solved
                    clearScreen(currentTurn);
                    printSlow("You are back in the area with the stream and stepping stones.\n");
                    streamReturnChoice = makeChoice(streamChoicesReturn, currentTurn);
                    switch (streamReturnChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You decide to cross and continue on your journey.\n");
                            if (previousArea == 1) {
                                currentArea = 3;
                                previousArea = 2;
                            } else if (previousArea == 3) {
                                currentArea = 1;
                                previousArea = 2;
                            }
                            break;
                        case 2:
                            currentArea = previousArea;
                            previousArea = 2;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                    currentTurn++;
                    break;
                }
                break;
            case 3:
                if (campfireRiddleSolved) {
                    clearScreen(currentTurn);
                    printSlow("You are back at the campfire, but the figure is no longer there.\n"
                        "The fire crackles and pops, and you feel a sense of peace and warmth.\n");
                    if (previousArea == 2){
                        campfireChoiceOrder = {3, 1, 2};
                        campfireReturnChoice = makeAdjustedChoice(campfireChoicesReturn, campfireChoiceOrder); 
                        switch (campfireReturnChoice) {
                            case 1:
                                clearScreen(currentTurn);
                                printSlow("You decide to leave the campfire and go back\n"
                                "the way you came.\n");
                                currentArea = previousArea;
                                previousArea = 3;
                                break;
                            case 2:
                                clearScreen(currentTurn);
                                printSlow("You decide to take the path of the warrior.\n");
                                currentArea = 4;
                                previousArea = 3;
                                break;
                            case 3:
                                clearScreen(currentTurn);
                                printSlow("You decide to take the path of the scholar.\n");
                                currentArea = 5;
                                previousArea = 3;
                                break;
                            default:
                                std::cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    } else if (previousArea == 5) {
                        campfireChoiceOrder = {0, 1, 3};
                        campfireReturnChoice = makeAdjustedChoice(campfireChoicesReturn, campfireChoiceOrder); 
                        switch (campfireReturnChoice) {
                            case 1:
                                clearScreen(currentTurn);
                                printSlow("You decide to leave the campfire and continue on your journey.\n");
                                currentArea = 2;
                                previousArea = 3;
                                break;
                            case 2:
                                clearScreen(currentTurn);
                                printSlow("You decide to take the path of the warrior.\n");
                                currentArea = 4;
                                previousArea = 3;
                                break;
                            case 3:
                                clearScreen(currentTurn);
                                printSlow("You decide to leave the campfire and go back the way you came.\n");
                                currentArea = previousArea;
                                previousArea = 3;
                                break;
                            default:
                                std::cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    } else if (previousArea == 4) {
                        campfireChoiceOrder = {0, 2, 3};
                        campfireReturnChoice = makeAdjustedChoice(campfireChoicesReturn, campfireChoiceOrder); 
                        switch (campfireReturnChoice) {
                            case 1:
                                clearScreen(currentTurn);
                                printSlow("You decide to leave the campfire and continue on your journey.\n");
                                currentArea = 2;
                                previousArea = 3;
                                break;
                            case 2:
                                clearScreen(currentTurn);
                                printSlow("You decide to take the path of the scholar.\n");
                                currentArea = 5;
                                previousArea = 3;
                                break;
                            case 3:
                                clearScreen(currentTurn);
                                printSlow("You decide to leave the campfire and go back the way you came.\n");
                                currentArea = previousArea;
                                previousArea = 3;
                                break;
                            default:
                                std::cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    }
                    currentTurn++;
                    break;
                } else {
                    int result = campfireRiddle(currentTurn);
                    if (result == 0) {
                        gameOver = true;
                    } else if (result == 1) {
                        campfireRiddleSolved = true;
                        currentArea = 3;
                        previousArea = 2;
                        bag.push_back("Ancient Tome");
                    } else if (result == 2) {
                        currentArea = previousArea;
                        previousArea = 3;
                    }
                    currentTurn++;
                    break;
                }
                break;
            case 4:
                std::cout << "You are in area 4\n";
                break;
            default:
                std::cout << "Invalid area\n";
                break;
        }
    }
    return 0;
}
