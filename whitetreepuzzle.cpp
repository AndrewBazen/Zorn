/* whitetreepuzzle.cpp
* @AndrewBazen
* @version: 1.0
* @date: 4 Aug 2024
* @description: creates the logic for puzzle area with the white trees.
*/

#include "whitetreepuzzle.h"

/* whiteTreePuzzle - runs a puzzle for the player to solve by touching 3 trees
* in the correct order.
*
* @param currentTurn - the players current turn
* @return result - returns a number based on if the player solves the puzzle,
*                  leaves, or loses the game.
*/
int whiteTreePuzzle(int currentTurn) {
    std::vector<std::string> treeAreaChoices = { // main area choices
        "Drink the liquid",
        "Examine the trees",
        "Examine the pedestal",
        "Leave the clearing"
    };

    
    std::vector<std::string> treePuzzleChoices = { // choices in the puzzle
        "Touch the cresent moon tree",
        "Touch the sun tree",
        "Touch the star tree",
        "Leave the trees"
    };
    
    std::vector<int> treeChoices;
    bool leaveTrees = false;
    bool gameOver = false;
    bool puzzleSolved = false;
    int result = 0;
    int treeAreaChoice = 0;
    int treeChoice = 0;
    int puzzleChances = 3;
    clearScreen(currentTurn);
    printSlow("You find yourself in a small clearing with three pure-white\n"
    "leafless trees in the center. The trees are arranged in a triangle, with\n" 
    "a small pedestal in the center. On the pedestal, there is a silver bowl\n" 
    "filled to the brim with a dark red liquid.\n");
    
    // If the puzzle isn't solved and the player hasn't failed, then loop.
    while (!puzzleSolved && !gameOver) {
        treeAreaChoice = makeChoice(treeAreaChoices, currentTurn);
        switch (treeAreaChoice) {
            case 1:
                clearScreen(currentTurn);
                printSlow("You take a sip of the liquid, and feel a warm sensation\n" 
                "spread through your body. it tastes warm and sweet like the juice\n" 
                "of a fruit, but as you look down at your self, you notice that the\n" 
                "liquid on your hands is deep red blood. You feel a sudden sense of\n" 
                "dread, and know that you have made a grave mistake. Pain grips your\n" 
                "entire body as you begin to cough and choke on the blood. You fall\n" 
                "to the ground, your vision blurring as the darkness consumes you.\n");
                printRedAndSlow("Game Over\n");
                printSlow("press any key to continue...");
                system("pause");
                puzzleSolved = true;
                break;
            case 2:
                clearScreen(currentTurn);
                printSlow("You examine the trees, and notice that each tree has a\n"
                "small symbol carved into its trunk. The first tree has a crescent\n"
                "moon, the second tree has a sun, and the third tree has a star.\n"
                "You feel a sense of connection to the symbols, and know that they\n"
                "hold the key to the puzzle.\n");
                leaveTrees = false;

                // If the player still has chances and they haven't decided to leave, loop.
                while (puzzleChances > 0 && !leaveTrees) {
                    treeChoice = makeChoice(treeAreaChoices, currentTurn);
                    switch (treeChoice) {
                        case 1:
                            treeChoices.push_back(1);
                            // Checks to see if the choice vector is filled with the correct sequence
                            // and solves the puzzle if it is.
                            if (treeChoices.size() == 3 && treeChoices[0] == 2 && treeChoices[1] == 3 
                                && treeChoices[2] == 1){
                                printSlow("You touch the first tree, and feel a surge of energy\n" 
                                "flow through you. The tree begins to glow with a soft white\n" 
                                "light, and you feel a sense of peace and calm wash over you.\n"
                                "As you look back at the bowl on the pedestal, you notice that\n" 
                                "instead of the liquid there is a white crystal that is glowing\n"
                                "You pick up the crystal and feel a sense of power and strength\n" 
                                "flow through you.\n");
                                puzzleSolved = true;
                                result = 1;
                                break;
                            } else if (treeChoices.size() != 3) {
                                printSlow("You touch the crescent moon tree, and the symbol glows\n"
                                "with a soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the crescent moon tree, but as you do, the\n"
                                "earth below your feet begins to shake and the light of the trees\n"
                                "grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 2:
                            treeChoices.push_back(2);
                            if (treeChoices.size() != 3){
                                printSlow("You touch the sun tree, and the symbol glows with a\n"
                                "soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the sun tree, but as you do, the earth below\n"
                                "your feet begins to shake and the light of the trees grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 3:
                            treeChoices.push_back(3);
                            if (treeChoices.size() != 3){
                                printSlow("You touch the star tree, and the symbol glows with a\n"
                                "soft white light.\n");
                                break;
                            } else {
                                printSlow("You touch the star tree, but as you do, the earth below\n" 
                                "your feet begins to shake and the light of the trees grows dimmer.\n");
                                treeChoices.clear();
                                puzzleChances--;
                                break;
                            }
                        case 4:
                            // Allows the player to go back.
                            clearScreen(currentTurn);
                            printSlow("you leave the trees, and you are back in front of the pedestal.\n");
                            leaveTrees = true;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } 
                // Checks to see if the player has run out of chances to solve 
                // the puzzle and returns game over if so.
                if (puzzleChances == 0 && !leaveTrees) {
                    gameOver = true;
                    clearScreen(currentTurn);
                    printSlow("The trees go dark and the ground beneath you begins to\n"
                    "shake violently and crack beneath you.\n");
                    printRedAndSlow("You are unable to get away as you fall to darkness.\n"
                    "Game Over\n");
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    std::cout << "Press any key to continue...";
                    system("read");
                }
                break;
            case 3:
                clearScreen(currentTurn);
                printSlow("You examine the pedestal, and notice that there is a\n" 
                "small inscription carved into the base. It reads: 'To find the\n" 
                "light, follow the path of the stars, and the eternal night will\n" 
                "be banished. You feel a sense of understanding, and know that\n" 
                "the answer lies in the symbols on the trees.\n");
                break;
            case 4:
                clearScreen(currentTurn);
                printSlow("You decide to leave the clearing and continue on your\n" 
                "journey.\n");
                result = 2;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return result;
}
