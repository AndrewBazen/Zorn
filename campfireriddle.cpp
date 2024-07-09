#include "campfireriddle.h"

int campfireRiddle(int currentTurn) {
    std::vector<std::string> questions = {"Ask who the lord is", "Ask what happened to them", "Ask which path to take"};
    bool leaveFire = false;
    bool leaveFigure = false;
    bool gameOver = false;
    bool pathChosen = false;
    bool goBack = false;
    int result = 0;
    int campfireChoice = 0;
    int questionChoice = 0;
    int riddleChoice = 0;
    clearScreen(currentTurn);
    printSlow("As you walk along the path, you begin to see a soft\n"
        "orange glow in the distance. As you get closer, you can hear the sound of a crackling fire.\n"
        "You come to a split in the path with a small campfire burning in the center.\n"
        "A figure sits by the fire, their face hidden in the shadows. A crooked and knotted sign\n"
        "points to the left, with the words 'The Path of the Warrior' written on it. To the right,\n"
        "a sign reads 'The Path of the Scholar'.\n");

    while (!pathChosen && !gameOver && !leaveFire) {
        campfireChoice = makeChoice(campfireChoices, currentTurn);
        switch (campfireChoice) {
            case 1:
                clearScreen(currentTurn);
                printSlow("You approach the figure by the fire, and as you get closer, you see that it's\n"
                "proportions are all wrong. It's limbs are too long, and it's head is too large to be a person.\n"
                "you can now see that under the hood, there is a slight gleam of sharp teeth and beast-like eyes.\n"
                "The figure does not move, but you feel a sense of unease wash over you.\n");
                printRedAndSlow("Come no closer, I fear I may not be able to control myself..\n"
                "I was once like you, but now I am something else entirely. Forever changed by the lord of this realm.\n"
                "you may ask me three questions, but be warned, my answers may not be what you seek.\n");
                while (!leaveFigure) {
                    questionChoice = makeChoice(figureChoices, currentTurn);
                    switch (questionChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure who the lord of the realm is, and it make an otherworldly chuckle.\n");
                            printRedAndSlow("The eternal night, the darkness when you close your eyes...\n");
                            break;
                        case 2:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure what happened to them, and it's eyes seem to flash from under the hood.\n");
                            printRedAndSlow("Cruel is the fate that awaits the cowardly.  Forever wandering in the dark and never seeking to fight.\n"
                            "The lord holds out his hand, and the coward takes it, never to return to the light.\n");
                            break;
                        case 3:
                            clearScreen(currentTurn);
                            printSlow("You ask the figure which path to take, and the figure speaks in a low, raspy voice,\n");
                            printRedAndSlow("A question for a question, which is mightier, the sword or the pen?\n"
                            "For with a sword you may write your own destiny, and with a pen you may strike down your foes.\n"
                            "Choose wisely, traveler, for only the brave and the wise may pass.\n");
                            riddleChoice = makeChoice(figureAnswerChoices, currentTurn);
                            switch (riddleChoice) {
                                case 1:
                                    clearScreen(currentTurn);
                                    printSlow("You choose the sword, and the figure smiles a wicked smile, letting you see the terrifying teeth.\n"
                                    "The figures body begins to crack and distort as it transforms before you into a hulking werewolf with bright red eyes.\n");
                                    printRedAndSlow("Unwise is the man who forsakes the pen for the sword.\n");
                                    printSlow("The werewolf lunges at you, and the darkness takes you as you feel the pain of being ripped apart.\n");
                                    gameOver = true;
                                    break;
                                case 2:
                                    clearScreen(currentTurn);
                                    printSlow("You choose the pen, and the figure smiles a wicked smile, letting you see the terrifying teeth.\n"
                                    "The figures body begins to crack and distort as it transforms before you into a hulking werewolf with bright red eyes.\n");
                                    printRedAndSlow("cowardly is the man who forsakes the sword for the pen.\n");
                                    printSlow("The werewolf lunges at you, and the darkness takes you as you feel the pain of being ripped apart.\n");
                                    gameOver = true;
                                    break;
                                case 3:
                                    clearScreen(currentTurn);
                                    printSlow("You choose neither, and the figure's posture seems to soften a bit\n");
                                    printRedAndSlow("A fine choice, traveler. Wise is the man who knows the swords edge and brave is the man who knows the reach of the pen.\n");
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
                printSlow("You sit by the campfire, feeling the warmth of the flames on your face.\n"
                "The figure does not move, but you feel its gaze resting upon you.\n"
                "The fire crackles and pops, and in the coals, you think you see shapes moving.\n");
                goBack = false;
                while (!goBack) {
                    std::cout << "-------------------------------------------\n";
                    std::cout << "1. look deeper into the fire\n"
                    "2. get up from the campfire\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    int fireChoice;
                    std::cin >> fireChoice;
                    switch (fireChoice) {
                        case 1:
                            clearScreen(currentTurn);
                            printSlow("You look deeper into the fire, and the shapes in the coals seem to grow more defined.\n"
                            "You see a wolf, chasing a rabbit through the woods. You continue to watch as the rabbit\n"
                            "is caught and devoured by the wolf. The fire crackles and pops, and the shapes fade away.\n"
                            "as you look away from the fire, you feel a sense of worry as you realize that more time has passed than you thought.\n");
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
                printSlow("You decide to leave the campfire and go back the way you came.\n"
                "The figure by the fire watches you go, it's eyes following you until you are out of sight.\n");
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
