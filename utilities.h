#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "choices.h"



void clearScreen(int);

void printSlow(std::string);

void printRedAndSlow(std::string);

int makeChoice(std::vector<std::string>, int);