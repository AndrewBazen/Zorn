#include <vector>
#include <string>

void clearScreen(int);

void printSlow(std::string);

void printRedAndSlow(std::string);

void waitForInput(const std::string& prompt = "Press Enter to continue");

int makeChoice(std::vector<std::string>);

int makeAdjustedChoice(std::vector<std::string>, std::vector<int>);
