#include "campfireriddle.h"

int campfireRiddle(int currentTurn) {
    std::vector<std::string> questions = {"Ask who the lord is", 
        "Ask what happened to them", "Ask which path to take"};
    bool leaveFire = false;
    bool leaveFigure = false;
    bool gameOver = false;
    bool pathChosen = false;
    bool goBack = false;
    int result = 0;
    int campfireChoice = 0;
    int questionChoice = 0;
    int riddleChoice = 0;
    int fireChoice = 0;

    std::vector<std::string> fireChoices = {
        "Look deeper into the fire",
        "Get up from the fire"
    };

    std::vector<std::string> campfireAreaChoices = {
        "Approach the figure",
        "Sit by the campfire",
        "Leave the campfire and go back"
    };

    std::vector<std::string> figureChoices = {
        "Ask who the lord is", 
        "Ask what happened to them", 
        "Ask which path to take",
        "Try to move past the figure"
    };

    std::vector<std::string> figureAnswerChoices = {
        "The sword",
        "The pen",
        "Neither"
    };
    clearScreen(currentTurn);
    printSlow("As you walk along the path, you begin to see a soft\n"
        "orange glow in the distance. As you get closer, you can hear the\n"
        "sound of a crackling fire. You come to a split in the path with\n"
        "a small campfire burning in the center. A figure sits by the\n"
        "fire, their face hidden in the shadows. A crooked and knotted\n"
        "sign points to the left, with the words 'The Path of the Warrior'\n"
        "written on it. To the right, a sign reads 'The Path of the\n" 
        "Scholar'.\n");

    while (!pathChosen && !gameOver && !leaveFire) {
        campfireChoice = makeChoice(campfireAreaChoices, currentTurn);
        switch (campfireChoice) {
            case 1:
                clearScreen(currentTurn);
                printSlow("You approach the figure by the fire, and as you get\n"
                    "closer, you see that it's proportions are all wrong. It's\n"
                    "limbs are too long, and it's head is too large to be a person.\n"
                    "you can now see that under the hood, there is a slight gleam\n"
                    "of sharp teeth and beast-like eyes. The figure does not move,\n"
                    "but you feel a sense of unease wash over you.\n");
                printRedAndSlow("Come no closer, I fear I may not be able to\n"
                    "control myself.. I was once like you, but now I am something\n"
                    "else entirely. Forever changed by the lord of this realm.\n"
                    "you may ask me three questions, but be warned, my answers\n"
                    "may not be what you seek.\n");
                while (!leaveFigure) {
                    questionChoice = makeChoice(figureChoices, currentTurn);
                    switch (questionChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure who the lord of the realm is, and it\n"
                                "make an otherworldly chuckle.\n");
                            printRedAndSlow("The eternal night, the darkness when you close\n"
                                "your eyes...\n");
                            break;
                        case 2:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure what happened to them, and it's eyes\n"
                                "seem to flash from under the hood.\n");
                            printRedAndSlow("Cruel is the fate that awaits the cowardly. Forever\n"
                                "wandering in the dark and never seeking to fight. The lord\n"
                                "holds out his hand, and the coward takes it, never to return\n"
                                "to the light.\n");
                            break;
                        case 3:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure which path to take, and the figure speaks\n"
                                "in a low, raspy voice,\n");
                            printRedAndSlow("A question for a question, which is mightier, the sword\n"
                                "or the pen? For with a sword you may write your own destiny, and with\n"
                                "a pen you may strike down your foes. Choose wisely, traveler, for\n"
                                "only the brave and the wise may pass.\n");
                            riddleChoice = makeChoice(figureAnswerChoices, currentTurn);
                            switch (riddleChoice) {
                                case 1:
                                    clearScreen(currentTurn);
                                    printSlow("You choose the sword, and the figure smiles a wicked smile, letting\n"
                                        "you see the terrifying teeth. The figures body begins to crack and distort\n"
                                        "as it transforms before you into a hulking werewolf with bright red eyes.\n");
                                    printRedAndSlow("Unwise is the man who forsakes the pen for the sword.\n");
                                    printSlow("The werewolf lunges at you, and the darkness takes you as you feel\n"
                                        "the pain of being ripped apart.\n");
                                    gameOver = true;
                                    break;
                                case 2:
                                    clearScreen(currentTurn);
                                    printSlow("You choose the pen, and the figure smiles a wicked smile, letting you\n"
                                        "see the terrifying teeth. The figures body begins to crack and distort as\n"
                                        "it transforms before you into a hulking werewolf with bright red eyes.\n");
                                    printRedAndSlow("cowardly is the man who forsakes the sword for the pen.\n");
                                    printSlow("The werewolf lunges at you, and the darkness takes you as you feel\n"
                                        "the pain of being ripped apart.\n");
                                    gameOver = true;
                                    break;
                                case 3:
                                    clearScreen(currentTurn);
                                    printSlow("You choose neither, and the figure's posture seems to soften a bit\n");
                                    printRedAndSlow("A fine choice, traveler. Wise is the man who knows the swords\n"
                                        "edge and brave is the man who knows the reach of the pen.\n");
                                    result = 1;
                                    break;
                                default:
                                    std::cout << "Invalid choice. Please try again.\n";
                                    break;
                          }
                     }
                }

                break;
            case 2:
                clearScreen(currentTurn);
                printSlow("You sit by the campfire, feeling the warmth of the\n"
                    "flames on your face. The figure does not move, but you feel\n"
                    "its gaze resting upon you. The fire crackles and pops, and\n"
                    "in the coals, you think you see shapes moving.\n");
                goBack = false;
                while (!goBack) {
                    fireChoice = makeChoice(fireChoices, currentTurn);
                    switch (fireChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You look deeper into the fire, and the shapes in the\n"
                                "coals seem to grow more defined. You see a wolf, chasing a rabbit\n"
                                "through the woods. You continue to watch as the rabbit is caught\n"
                                "and devoured by the wolf. The fire crackles and pops, and the\n"
                                "shapes fade away. As you look away from the fire, you feel a\n"
                                "sense of worry as you realize that more time has passed than you\n"
                                "thought.\n");
                            currentTurn++;
                            break;
                        case 2:
                            clearScreen(currentTurn);
                            printSlow("You decide to get up from the campfire.\n");
                            goBack = true;
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                }
                break;
            case 3:
                clearScreen(currentTurn);
                printSlow("You decide to leave the campfire and go back the way\n"
                    "you came. The figure by the fire watches you go, it's eyes\n"
                    "following you until you are out of sight.\n");
                leaveFire = true;
                result = 2;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;

        }
    }
    return result;
}
