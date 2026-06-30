/* utilites.cpp
* @AndrewBazen
* @version: 1.0
* @date: 4 Aug 2024
* @description: holds simple utilites used throughout the rest of the program.
*/

#include "utilities.h"

/* clearScreen - clears the terminal screen
*
* @param currentTurn - the players current turn number
*/
void clearScreen(int currentTurn) {
    try {
        if (system("cls")) system("clear");
    } catch (...) {
        std::cout << "Error clearing screen." << std::endl;
    }
    std::cout << "                                                   Turn: " 
    << currentTurn << std::endl;
}

/* printSlow - prints a string to the terminal slowly
*
* @param text - the string to be printed 
*/
void printSlow(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        std::cout << text[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

/* printRedAndSlow - prints a string to the terminal slowly and in a red color
*
* @param text - the string to be printed 
*/
void printRedAndSlow(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        std::cout << "\033[1;31m" << text[i] << "\033[0m";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    }
}

/* makeChoice - prompts the user to make a choice based on the input choices 
*
* @param choices - a vector of strings that will be printed to the player
* @param currentTurn - the players turn number
* @return choice - the number of the choice the player chose.
*/
int makeChoice(std::vector<std::string> choices, int currentTurn) {
    int choice = 0;
    std::string input;
    bool valid = false;
    std::cout << "---------------------------------------------------\n";
    for (int i = 0; i < choices.size(); i++) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }
    std::cout << "---------------------------------------------------\n";
    while (!valid) {
        choice = 0;
        std::cout << "Enter your choice: ";
        // try {
            std::cin >> choice;
            if (choice > 0 && choice <= choices.size()) {
                valid = true;
            } else {
                std::cout << "\033[31m" << "  Invalid choice. Please try again." 
                << "\033[0m";
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                printf("\e[2K");
                printf("\e[1A\e[2K\r");
            }
        // } catch (...) {
        //     std::cout << "\033[1;31m" << "  Invalid choice. Please try again." 
        //     << "\033[0m";
        //     std::cout.flush();
        //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //     printf("\e[2K");
        //     printf("\e[1A\e[2K\r");
        // }
    }
    return choice;
}

/* makeAdjustedChoice - prompts the user to make a choice based on the input 
* choices and a predetermined order.
*
* @param choices - a vector of strings that will be printed to the player
* @param order - the order of the questions
* @return choice - the number of the choice the player chose.
*/
int makeAdjustedChoice(std::vector<std::string> choices, std::vector<int> order) 
{
    int choice = 0;
    bool valid = false;
    std::cout << "---------------------------------------------------\n";
    for (int i = 0; i < order.size(); i++) {
        std::cout << i + 1 << ". " << choices[order[i]] << "\n";
    }
    std::cout << "---------------------------------------------------\n";
    while (!valid) {
        std::cout << "Enter your choice: ";
        try {
            std::cin >> choice;
            if (choice > 0 && choice <= choices.size()) {
                valid = true;
            } else {
                std::cout << "\033[31m" << "  Invalid choice. Please try again." 
                << "\033[0m";
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                printf("\e[2K");
                printf("\e[1A\e[2K\r");
            }
        } catch (...) {
            std::cout << "\033[1;31m" << "  Invalid choice. Please try again." 
            << "\033[0m";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            printf("\e[2K");
            printf("\e[1A\e[2K\r");
        }
    }
    return choice;
}
