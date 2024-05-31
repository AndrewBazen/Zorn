#include "utilities.h"

void clearScreen() {
    try {
        if (system("cls")) system("clear");
    } catch (...) {
        std::cout << "Error clearing screen." << std::endl;
    }
}

void printSlow(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        std::cout << text[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

void printRedAndSlow(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        std::cout << "\033[1;31m" << text[i] << "\033[0m";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}