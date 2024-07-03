#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "utilities.h"
#include "whitetreepuzzle.h"
#include "streampuzzle.h"


int main() {

    int choiceInvalid = true;
    int currentArea = 0;
    int currentTurn = 0;
    bool gameOver = false;
    bool allArtifactsFound = false;
    bool brilliantCrystalFound = false;
    bool area1Solved = false;
    bool area2Solved = false;
    bool ancientTomeFound = false;
    bool swordOfLightFound = false;
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
    while (choiceInvalid){
        std::cout << "-------------------------------------------\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Exit\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "You have chosen to start the game!\n";
                choiceInvalid = false;
                break;
            case 2:
                std::cout << "You have chosen to exit the game!\n";
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    clearScreen(currentTurn);
    printSlow("You wake to the sound of leaves rustling in the wind, and find yourself in a dark forest with tall tress that cover the sky above you..\n"
        "You have no memory of how you got here, or where you are.\n"
        "You see a path leading to the left, which seems to be giving off a soft white glow, and a path leading to the right, which looks dark frightening.\n"
        "Directly in front of you, there is a small statue of a wolf, in it's mouth are a piece of paper, and a small bag.\n");
    bool pathChosen = false;
    bool moveOn = false;
    bool paperAndBagTaken = false;
    while(pathChosen == false) {
        std::cout << "-------------------------------------------\n";
        if (!paperAndBagTaken) {
            std::cout << "1. Take the paper and bag\n"
            "2. Take the path to the left\n"
            "3. Take the path to the right\n"
            "-------------------------------------------\n"
            "What do you do: ";
        } else {
            std::cout << "1. Continue\n"
            "2. Take the path to the left\n"
            "3. Take the path to the right\n"
            "-------------------------------------------\n"
            "What do you do: ";
        }
    
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                paperAndBagTaken = true;
                clearScreen(currentTurn);
                printSlow("You carefully move to the wolf statue.\n"  
                "For a moment you think you see its eyes shine red, but maybe it was your imagination.\n"
                "You manage to take the paper and bag.\n");
                
                while (moveOn == false) {
                    std::cout << "-------------------------------------------\n"
                    "1. Read the paper\n"
                    "2. Open the bag\n"
                    "3. Continue\n";
                    std::cout << "-------------------------------------------\n"
                    "What do you do: ";

                    int choice2;
                    std::cin >> choice2;
                    switch (choice2) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You open the paper and read the following:\n"
                            "Welcome to Zorn, a world of darkness and tragedy.\n"
                            "You have been chosen to save this world from the darkness that threatens to consume it.\n"
                            "You must find the 3 artifacts of power, and use them to defeat the evil that lurks in the shadows.\n"
                            "Good luck, brave adventurer.\n");
                            break;
                        case 2:
                            clearScreen(currentTurn);
                            printSlow("You open the bag and find a small dagger inside.\n"
                            "It looks sharp and well made.\n"
                            "You decide to keep it, as it may come in handy.\n");
                            break;
                        case 3:
                            clearScreen(currentTurn);
                            printSlow("You decide to leave the statue behind and continue on your journey.\n");
                            moveOn = true;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                }
                break;
            case 2:
                currentArea = 1;
                clearScreen(currentTurn);
                std::cout << "You cautiously make your way down the path to the left.\n";
                pathChosen = true;
                break;
            case 3:
                currentArea = 2;
                clearScreen(currentTurn);
                std::cout << "You have chosen to take the path to the right\n";
                pathChosen = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    currentTurn = 0;
    int previousArea = 0;
    while (gameOver == false) {
        if (allArtifactsFound) {
            clearScreen(currentTurn);
            printSlow("You have found all 3 artifacts of power, and are ready to face the darkness that threatens to consume Zorn.\n"
            "You make your way to the heart of the forest, where the evil that lurks in the shadows awaits.\n"
            "You feel a sense of dread and fear as you approach, but you know that you must be strong and face your fears.\n"
            "You take a deep breath, and step forward into the darkness.\n"
            "Press any key to continue...\n");
            system("read");
            break;
        } else if (currentTurn == 10) {
            clearScreen(currentTurn);
            printSlow("You have been wandering for hours, but you can't seem to find your way out of the forest.\n"
            "You feel a strong presence growing closer, and the hairs on the back of your neck begin to stand up.\n"
            "Press any key to continue...\n");
            system("read");
        } else if (currentTurn == 20) {
            clearScreen(currentTurn);
            printSlow("You have been wandering for hours, but you can't seem to find your way out of the forest.\n"
            "You feel a strong presence growing much closer, you hear a long deep howl in the distance and feel as though you are being watched.\n"
            "Press any key to continue...\n");
            system("read");
        } else if (currentTurn >= 30 && currentTurn % 3 == 0) {
            clearScreen(currentTurn);
            printSlow("The wind picks up around you and the trees begin to moan and creak.\n"
            "You feel an overwhelming presence as a titanic wolf with giant fangs, blood red eyes, and pitch black fur makes its way out to the dark trees.\n"
            "You feel a sense of dread and fear as it approaches you, its bloodlust hanging in the air like fog.\n\n");
            printRedAndSlow("You feel the darkness start to press in on you");
            if (brilliantCrystalFound && usesLeft > 0) {
                printSlow(" but you feel the power of the artifact start to vibrate.\n"
                "You hold it up and the wolf recoils in fear, its eyes wide with terror.\n"
                "You feel a surge of power as the darkness is pushed back, and the wolf howls in pain before disappearing into the shadows.\n"
                "Press any key to continue...\n");
                system("read");
                usesLeft--;
            } else {
                printSlow(" and you feel the darkness start to consume you. As the wolf begins to devour your flesh.\n");
                printRedAndSlow("Game Over\n");
                std::cout << "Press any key to continue...";
                system("read");
                gameOver = true;
            }
        }
        int choice = 0;
        switch (currentArea) {
            case 0:
                clearScreen(currentTurn);
                while (choice != 1 && choice != 2) {
                    std::cout << "You find yourself back at the statue of the wolf, with the paths to the left and right still before you.\n";
                    std::cout << "-------------------------------------------\n"
                    "1. Take the path to the left\n"
                    "2. Take the path to the right\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    std::cin >> choice;
                    if (choice == 1) {
                        currentArea = 1;
                    } else if (choice == 2) {
                        currentArea = 2;
                    } else {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                }
                currentTurn++;
                break;
            case 1:
                // White Tree Puzzle
                if (!area1Solved) {    // If the puzzle has not been solved
                    int result = whiteTreePuzzle(currentTurn);
                    if (result == 0) {
                        gameOver = true;
                    } else if (result == 1){
                        currentArea = 0;
                        previousArea = 1;
                        area1Solved = true;
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
                    printSlow("You are back in the clearing with the white trees and the pedestal, which is now empty.\n");
                    std::cout << "-------------------------------------------\n"
                    "1. leave the clearing\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    int choice;
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You decide to leave the clearing and continue on your journey.\n");
                            currentArea = 0;
                            previousArea = 1;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                    currentTurn++;
                    break;
                }
            case 2:
                if (!area2Solved) {    // If the puzzle has not been solved
                    int result = streamPuzzle(currentTurn);
                    if (result == 0) {
                        gameOver = true;
                    } else if (result == 1){
                        currentArea = 3;
                        previousArea = 2;
                        area2Solved = true;
                    } else if (result == 2) {
                        currentArea = 0;
                        previousArea = 1;
                    }
                    currentTurn++;
                    break;
                } else {  // If the puzzle has been solved
                    clearScreen(currentTurn);
                    printSlow("You are back in the area with the stream and stepping stones.\n");
                    std::cout << "-------------------------------------------\n"
                    "1. cross the stream and continue.\n"
                    "2. Go back the way you came.\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    int choice;
                    std::cin >> choice;
                    switch (choice) {
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
                printSlow("As you walk along the path, you begin to see a soft\n"
                "orange glow in the distance. As you get closer, you can hear the sound of a crackling fire.\n"
                "You come to a split in the path with a small campfire burning in the center.\n"
                "A figure sits by the fire, their face hidden in the shadows. A crooked and knotted sign\n"
                "points to the left, with the words 'The Path of the Warrior' written on it. To the right,\n"
                "a sign reads 'The Path of the Scholar'.\n");
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
