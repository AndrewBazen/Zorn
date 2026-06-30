#include "world/gamestate.h"
#include "util/utilities.h"
#include <iostream>


int main() {

    Gamestate game;

    std::vector<std::string> mainMenuChoices = {
        "New Game", 
        "Quit"
    };

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
    int mainMenuChoice = makeChoice(mainMenuChoices);
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
    
    printSlow("You wake to the sound of leaves rustling in the wind, and find\n" 
        "yourself in a dark forest with tall tress that cover the sky above you..\n"
        "You have no memory of how you got here, or where you are. You see a path\n" 
        "leading to the left, which seems to be giving off a soft white glow,\n" 
        "and a path leading to the right, which looks dark frightening. Directly\n"
        "in front of you, there is a small statue of a wolf, in it's mouth are\n"
        "a piece of paper, and a small bag.\n\n");
    waitForInput();

    printSlow("You carefully move to the wolf statue. For a moment you think\n"
        "you see its eyes shine red, but maybe it was your imagination. You manage\n"
        "to take the paper and bag.\n\n");
    waitForInput();

    printSlow("You open the paper and read the following:\n"
        "Welcome to Zorn, a world of darkness and tragedy.\n"
        "You have been chosen to save this world from the\n"
        "darkness that threatens to consume it. You must\n"
        "find the 3 artifacts of power, and use them to defeat\n"
        "the evil that lurks in the shadows. Good luck, brave\n"
        "adventurer.\n\n");
    waitForInput();

    printSlow("You open the bag and find a small dagger inside.\n"
        "It looks sharp and well made. You decide to keep it,\n"
        "as it may come in handy.\n\n");
    waitForInput();

    printSlow("Beyond the wolf statue you see a pathleading to the left, which seems to be giving\n"
        "off a soft white glow, and a path leading to the right, which looks\n"
        "dark and frightening.\n\n");

    game.run();
}
