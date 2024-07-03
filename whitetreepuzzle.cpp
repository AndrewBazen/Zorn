#include "whitetreepuzzle.h"

int whiteTreePuzzle(int currentTurn) {
    std::vector<int> treeChoices;
    bool leaveTrees = false;
    bool gameOver = false;
    bool puzzleSolved = false;
    int result = 0;
    int puzzleChances = 3;
    clearScreen(currentTurn);
    printSlow("You find yourself in a small clearing with three pure-white leafless trees in the center.\n"
    "The trees are arranged in a triangle, with a small pedestal in the center.\n"
    "On the pedestal, there is a silver bowl filled to the brim with a dark red liquid.\n");
    

    while (!puzzleSolved && !gameOver) {
        std::cout << "-------------------------------------------\n"
        "1. Drink the liquid\n"
        "2. Examine the trees\n"
        "3. Examine the pedestal\n"
        "4. Leave the clearing\n"
        "-------------------------------------------\n"
        "What do you do: ";

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                clearScreen(currentTurn);
                printSlow("You take a sip of the liquid, and feel a warm sensation spread through your body.\n"
                "it tastes warm and sweet like the juice of a fruit, but as you look down at your self, you notice that the liquid on your hands is deep red blood.\n"
                "You feel a sudden sense of dread, and know that you have made a grave mistake. Pain grips your entire body as you begin to cough and choke on the blood.\n"
                "you fall to the ground, your vision blurring as the darkness consumes you.\n");
                printRedAndSlow("Game Over\n");
                std::cout << "press any key to continue...";
                system("read");
                puzzleSolved = true;
                break;
            case 2:
                clearScreen(currentTurn);
                printSlow("You examine the trees, and notice that each tree has a small symbol carved into its trunk.\n"
                "The first tree has a crescent moon, the second tree has a sun, and the third tree has a star.\n"
                "You feel a sense of connection to the symbols, and know that they hold the key to the puzzle.\n");
                leaveTrees = false;
                while (puzzleChances > 0 && !leaveTrees) {
                    std::cout << treeChoices.size() << "\n";
                    std::cout << "-------------------------------------------\n"
                    "1. Touch the first tree\n"
                    "2. Touch the second tree\n"
                    "3. Touch the third tree\n"
                    "4. Leave the trees\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    int treeChoice;
                    std::cin >> treeChoice;
                    switch (treeChoice) {
                        case 1:
                            treeChoices.push_back(1);
                            if (treeChoices.size() == 3 && treeChoices[0] == 2 && treeChoices[1] == 3 && treeChoices[2] == 1){
                                printSlow("You touch the first tree, and feel a surge of energy flow through you.\n"
                                "The tree begins to glow with a soft white light, and you feel a sense of peace and calm wash over you.\n"
                                "As you look back at the bowl on the pedestal, you notice that instead of the liquid there is a white crystal that is glowing\n"
                                "You pick up the crystal and feel a sense of power and strength flow through you.\n");
                                puzzleSolved = true;
                                result = 1;
                                break;
                            } else if (treeChoices.size() != 3) {
                                printSlow("You touch the crescent moon tree, and the symbol glows with a soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the crescent moon tree, but as you do, the earth below your feet begins to shake and the light of the trees grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 2:
                            treeChoices.push_back(2);
                            if (treeChoices.size() != 3){
                                printSlow("You touch the sun tree, and the symbol glows with a soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the sun tree, but as you do, the earth below your feet begins to shake and the light of the trees grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 3:
                            treeChoices.push_back(3);
                            if (treeChoices.size() != 3){
                                printSlow("You touch the star tree, and the symbol glows with a soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the star tree, but as you do, the earth below your feet begins to shake and the light of the trees grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 4:
                            clearScreen(currentTurn);
                            printSlow("you leave the trees, and you are back in front of the pedestal.\n");
                            leaveTrees = true;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                }
                if (puzzleChances == 0 && !leaveTrees) {
                    clearScreen(currentTurn);
                    printSlow("The trees go dark and the ground beneath you begins to shake violently and crack beneath you.\n");
                    printRedAndSlow("You are unable to get away as you fall to darkness.\n"
                    "Game Over\n");
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    std::cout << "Press any key to continue...";
                    system("read");
                    puzzleSolved = true;
                }
                break;
            case 3:
                clearScreen(currentTurn);
                printSlow("You examine the pedestal, and notice that there is a small inscription carved into the base.\n"
                "It reads: 'To find the light, follow the path of the stars, and the eternal night will be banished.'\n"
                "You feel a sense of understanding, and know that the answer lies in the symbols on the trees.\n");
                break;
            case 4:
                clearScreen(currentTurn);
                printSlow("You decide to leave the clearing and continue on your journey.\n");
                result = 2;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return result;
}