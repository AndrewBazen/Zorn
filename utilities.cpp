#include "utilities.h"

void clearScreen(int currentTurn) {
    try {
        if (system("cls")) system("clear");
    } catch (...) {
        std::cout << "Error clearing screen." << std::endl;
    }
    std::cout << "                                                   Turn: " << currentTurn << std::endl;
}

void printSlow(std::string text) {
    bool skipKeyPressed = false;
    for (int i = 0; i < text.length(); i++) {
        std::cout << std::cin.peek();
        if (std::cin.peek() != '\n') {
            skipKeyPressed = true;
        }
        std::cout << text[i];
        std::cout.flush();
        if (!skipKeyPressed) {
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    }
}

void printRedAndSlow(std::string text) {
    bool skipKeyPressed = false;
    for (int i = 0; i < text.length(); i++) {
        if (std::cin.peek() != EOF) {
            skipKeyPressed = true;
        }
        std::cout << "\033[1;31m" << text[i] << "\033[0m";
        std::cout.flush();
        if (!skipKeyPressed) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}

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
            choice = std::cin.get();
            if (choice > 0 && choice <= choices.size()) {
                valid = true;
            } else {
                std::cout << "\033[31m" << "  Invalid choice. Please try again." << "\033[0m";
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                printf("\e[2K");
                printf("\e[1A\e[2K\r");
            }
        // } catch (...) {
        //     std::cout << "\033[1;31m" << "  Invalid choice. Please try again." << "\033[0m";
        //     std::cout.flush();
        //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //     printf("\e[2K");
        //     printf("\e[1A\e[2K\r");
        // }
    }
    return choice;
}

int makeAdjustedChoice(std::vector<std::string> choices, std::vector<int> order) {
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
                std::cout << "\033[31m" << "  Invalid choice. Please try again." << "\033[0m";
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                printf("\e[2K");
                printf("\e[1A\e[2K\r");
            }
        } catch (...) {
            std::cout << "\033[1;31m" << "  Invalid choice. Please try again." << "\033[0m";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            printf("\e[2K");
            printf("\e[1A\e[2K\r");
        }
    }
    return choice;
}
