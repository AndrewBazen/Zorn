/* whitetreepuzzle.cpp
* @AndrewBazen
* @version: 1.0
* @date: 4 Aug 2024
* @description: creates the logic for puzzle area with the white trees.
*/

#include "whitetreepuzzle.h"
#include "util/utilities.h"
#include "parser/parser.h"
#include "world/puzzle.h"
#include <format>
#include <iostream>
#include <string>
#include <vector>

namespace {
	std::string treeFrom(const std::string& noun) {
		if (noun.find("sun") != std::string::npos) return "sun";
		if (noun.find("star") != std::string::npos) return "star";
		if (noun.find("moon") != std::string::npos) return "moon";
		return "";
	}
}

/* whiteTreePuzzle - runs a puzzle for the player to solve by touching 3 trees
* in the correct order.
*
* @param currentTurn - the players current turn
* @return result - returns a number based on if the player solves the puzzle,
*                  leaves, or loses the game.
*/
PuzzleResult whiteTreePuzzle() {
	int chances = 3;
	std::vector<std::string> answer = { "sun", "star", "moon" };
	std::vector<std::string> touched;
	
	printSlow("You examine the trees, and notice that each tree has a\n"
	"small symbol carved into its trunk. The first tree has a moon,\n"
	"the second tree has a sun, and the third tree has a star.\n"
	"You feel a sense of connection to the symbols, and know that they\n"
	"hold the key to the puzzle.\n\n");

	while (true) {
		std::cout << "> ";
		std::string line;
		if (!std::getline(std::cin, line)) return Left;   // EOF (Ctrl-D) -> leave the puzzle
		Command cmd = parseCommand(line);
		
		std::string tree = treeFrom(cmd.noun);
		if (cmd.verb == "touch") {
			if (!tree.empty()) {
				if (tree == answer[touched.size()]) {
					touched.push_back(tree);
					if (touched.size() == answer.size()) {
						printSlow(std::format("You touch the {} tree, and feel a surge of energy\n"
											"flow through you.  All the trees begin to shine brightly,\n"
											"and you feel a sense of peace and calm wash over you.\n"
											"As you look back at the bowl on the pedestal, you notice\n"
											"that the red liquid that was there before has been replaced\n"
											"by a brilliant, white crystal.  You pick up the crystal and \n"
											"feel power and strength flood into you.\n\n", tree));
						return Solved;
					} else {
						printSlow(std::format("You touch the {} tree, and the symbol glows with a soft\n"
											"white light.\n\n", tree));
					}
				} else {
					touched.clear();
					--chances;
					if (chances > 0) {
						printSlow(std::format("You touch the {} tree, but as you do, the\n"
						"earth below your feet begins to shake and the light of the trees\n"
						"grows dimmer.\n\n", tree));
					} else {
						printSlow("The trees go dark and the ground beneath you begins to\n"
						"shake violently and crack beneath you.\n\n");
						printRedAndSlow("You are unable to get away as you fall to darkness.\n\n");
						return Died;
					}
				}
			} else { 
				if (cmd.noun == "liquid") {
					printSlow("You dip your fingers into the dark red liquid, and it is ice cold. As you pull\n"
							"your fingers out of the liquid you notice that it's blood.  Before you are able to\n"
							"wipe it off, it starts too violently shift and extend up your arm, causing you to drop\n"
							"to the ground and convulse and the icy blood completely engulfs you. Just as the liquid\n"
							"reaches your chest, you pass out from the pain.\n\n");

					waitForInput("Press Enter to continue");
					// would like to tie this back to the player as a blood curse or a secret pathway to a different ending maybe.
					// But it is just world flair for now.
					printSlow("You awaken beside the pedestal, but there is no blood on you anymore.  You stand up\n"
							"and look in the bowl, but it is now just an empty silver bowl.\n\n");
				} else {
					printSlow("Nothing happens.\n\n");
				}
			}
		} else if (cmd.verb == "leave") {
			return Left;
		} else if (cmd.verb == "examine") {
			if (!tree.empty()) {
				printSlow(std::format("A stark white birch tree with a small {} symbol carved\n"
					"into the trunk.\n\n", tree));
			} else if (cmd.noun == "pedestal") {
				printSlow("You examine the pedestal, and notice that there is a\n"
					"small inscription carved into the base. It reads: 'To find the\n"
					"light, follow the path of the stars, and the eternal night will\n"
					"be banished. You feel a sense of understanding, and know that\n"
					"the answer lies in the symbols on the trees.\n");
			} else if (cmd.noun == "bowl") {
				printSlow("A silver bowl filled to the brim with a dark red liquid.\n"
					"You feel a slight pull as you look at your reflection in it.\n\n");
			} else {
				printSlow("Not much to see here.\n\n");
			}
		} else {
			printSlow("You can't do that here.\n\n");
		}
	}
}
