#include "streampuzzle.h"

int streamPuzzle() {
    std::vector<int> streamChoices;
    std::vector<int> correctPattern = {2,1,1,2,1};  // the solution to the puzzle
    bool leaveStream = false;
    int result = 0;
    int puzzleChances = 3;
    bool puzzleSolved = false;
    bool puzzleStarted = false;
    bool firstJumpBad = true;
    clearScreen();
    printSlow("After traveling for what feels like hours, you find yourself at a stream that cuts through the path.\n"
    "The stream is too deep and fast to wade through and it is too wide to jump directly across.\n"
    "There is a small wooden sign off to the edge of the path that has some words written on it, and you can now see\n"
    "that just below the surface of the water, there are stepping stones that lead to the other side.\n");

    // Loop until the user decides to start the puzzle of leave the area.
    while (puzzleSolved == false && puzzleStarted == false && leaveStream == false) {
        std::cout << "-------------------------------------------\n"
            "1. Jump to one of the stones\n"
            "2. Read the Sign\n"
            "3. Go Back the Way you Came\n"
            "-------------------------------------------\n"
            "What do you do: ";

        int choice;
        std::cin >> choice;  // get the users choice

        switch (choice) {
            // player decides to jump
            case 1:
                printSlow("As you look at the stones just under the surface of the water in front of you, you notice\n"
                "that the stones are set in pairs all the way across the stream.\n");
            
                // loop until the first jump is the correct one.
                while (puzzleChances > 0 && puzzleStarted == false){
                    std::cout << "-------------------------------------------\n"
                    "1. Jump to the left stone\n"
                    "2. Jump to the Right stone\n"
                    "3. Don't jump\n"
                    "-------------------------------------------\n"
                    "What do you do: ";
                    int firstJumpChoice;
                    std::cin >> firstJumpChoice;
                    if (firstJumpChoice == 3) {  // if the user decides not to jump exit loop
                        continue;
                    } else if (firstJumpChoice == 1 || firstJumpChoice == 2) {  // if they decide to jump, start the puzzle
                        puzzleStarted = true;
                        switch (firstJumpChoice) {
                            case 1:
                                printSlow("You jump to the first left stepping stone.\n");
                                break;
                            case 2:
                                printSlow("You jump to the first right stepping stone.\n");
                                break;
                        }
                        if (firstJumpChoice != correctPattern[0]) {  // decrease chances if the first jump is bad
                            printSlow("The stone gives way under your weight and you find yourself thrust into the depths of the stream\n"
                            "The darkness surrounds you and the icy cold water saps your energy and everything goes dark\n");
                            puzzleChances--;
                            if (puzzleChances != 0) {
                                clearScreen();
                                printSlow("You gasp and cough spitting up water as you come to.  Somehow, you find yourself back on the path\n"
                                "beside the wooden sign that you saw earlier.\n");
                                puzzleStarted = false;
                            }
                        } else {
                            clearScreen();
                            printSlow("The stone holds firm as you land on top of it.\n");
                            for (int i = 1; i < correctPattern.size(); i++) {
                                if (puzzleStarted == false) {
                                    break;
                                }
                                std::cout << "-------------------------------------------\n"
                                "1. Jump to the left stone\n"
                                "2. Jump to the Right stone\n"
                                "-------------------------------------------\n"
                                "What do you do: ";

                                int jumpChoice;
                                std::cin >> jumpChoice;
                                switch (jumpChoice) {
                                    case 1:
                                        printSlow("You jump to the left stepping stone.");
                                        if (jumpChoice != correctPattern[i]) {
                                            printSlow("The stone gives way under your weight and you find yourself thrust into the depths of the stream\n"
                                            "The darkness surrounds you and the icy cold water saps your energy and everything goes dark\n");
                                            puzzleChances--;
                                            if (puzzleChances != 0) {
                                                clearScreen();
                                                printSlow("You gasp and cough spitting up water as you come to.  Somehow, you find yourself back on the path\n"
                                                "beside the wooden sign that you saw earlier.\n");
                                                puzzleStarted = false;
                                            }
                                            break;
                                        } else if (jumpChoice == correctPattern[i] && i == correctPattern.size() - 1) {
                                            printSlow("You have successfully crossed the stream and are now on the other side.\n");
                                            puzzleSolved = true;
                                            result = 1;
                                            break;
                                        }
                                        printSlow("The stone holds firm as you land on top of it, another " + std::to_string(correctPattern.size() - (i + 1)) + " stones now lay in front of you.\n");
                                        break;
                                    case 2:
                                        printSlow("You jump to the right stepping stone.\n");
                                        if (jumpChoice != correctPattern[i]) {
                                            printSlow("The stone gives way under your weight and you find yourself thrust into the depths of the stream\n"
                                            "The darkness surrounds you and the icy cold water saps your energy and everything goes dark\n");
                                            puzzleChances--;
                                            if (puzzleChances != 0) {
                                                clearScreen();
                                                printSlow("You gasp and cough spitting up water as you come to.  Somehow, you find yourself back on the path\n"
                                                "beside the wooden sign that you saw earlier.\n");
                                                puzzleStarted = false;
                                            }
                                            break;
                                        } else if (jumpChoice == correctPattern[i] && i == correctPattern.size() - 1) {
                                            printSlow("You have successfully crossed the stream and are now on the other side.");
                                            puzzleSolved = true;
                                            result = 1;
                                            break;
                                        }
                                        printSlow("The stone holds firm as you land on top of it, another " + std::to_string(correctPattern.size() - (i + 1)) + " stones now lay in front of you.\n");
                                        break;
                                    default:
                                        std::cout << "Invalid choice, please try again.";
                                        std::this_thread::sleep_for(std::chrono::seconds(2));
                                        break;
                                }
                            }
                        }
                    } else {
                        std::cout << "Invalid choice, please try again.";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }
                }
                if (puzzleChances == 0) {
                    result = 0;
                }
                break;
            case 2:
                clearScreen();
                printSlow("the wooden sign seems to have some sort of poem written on it.  It reads..\n"
                "      dark and cold the River flows, ominously the trees Leaves blow\n"
	            "      Look below the surface found, a helping hand, solid and Round\n"
	            "      a leap of faith is needed to cross, but one is gain and one is Loss\n");
                break;
            case 3:
                result = 2;
                leaveStream = true;
                break;
            default:
                std::cout << "Invalid choice, please try again.";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
        }
    }
    return result;
}