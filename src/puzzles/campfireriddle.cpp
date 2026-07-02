/* campfireriddle.cpp
* @AndrewBazen
* @description: the hooded figure at the campfire. Ask it questions; asking which
*               path to take poses the riddle "the sword or the pen?" — answering
*               "sword" or "pen" is fatal, "neither" wins the Ancient Tome.
*/

#include "campfireriddle.h"
#include "util/utilities.h"
#include "parser/parser.h"
#include "world/puzzle.h"
#include <iostream>
#include <string>

PuzzleResult campfireRiddle() {
	bool riddlePosed = false;

	printSlow("You approach the figure by the fire. Up close its proportions are all\n"
		"wrong — limbs too long, head too large. Beneath the hood there is a gleam\n"
		"of sharp teeth and beast-like eyes. It does not move.\n\n");
	printRedAndSlow("Come no closer. I was once as you are, but the lord of this realm\n"
		"remade me. Ask what you will, traveller — but my answers may not be what\n"
		"you seek.\n\n");

	while (true) {
		std::cout << "> ";
		std::string line;
		if (!std::getline(std::cin, line)) return Left;   // EOF (Ctrl-D) -> leave
		Command cmd = parseCommand(line);

		if (cmd.verb == "ask") {
			if (cmd.noun.find("lord") != std::string::npos || cmd.noun.find("who") != std::string::npos) {
				printSlow("You ask who the lord of the realm is. The figure gives an\n"
					"otherworldly chuckle.\n");
				printRedAndSlow("The eternal night. The darkness behind your eyes when you close them.\n\n");
			} else if (cmd.noun.find("happen") != std::string::npos || cmd.noun.find("fate") != std::string::npos) {
				printSlow("You ask what happened to it. Its eyes flash beneath the hood.\n");
				printRedAndSlow("Cruel is the fate of the cowardly — forever wandering the dark,\n"
					"never turning to fight. The dark lord holds out his hand, and the\n"
					"coward takes it, never to return to the light.\n\n");
			} else if (cmd.noun.find("path") != std::string::npos || cmd.noun.find("which") != std::string::npos || cmd.noun.find("way") != std::string::npos) {
				printSlow("You ask which path to take. The figure answers in a low, raspy voice.\n");
				printRedAndSlow("A question for a question: which is mightier, the sword or the pen?\n"
					"With a pen you write your own destiny; with a sword you strike down your\n"
					"foes. Answer wisely — only the brave and the wise may pass.\n\n");
				riddlePosed = true;
			} else {
				printSlow("The figure gives no answer to that.\n\n");
			}
		} else if (cmd.verb == "answer" || cmd.verb == "say" || cmd.verb == "choose"
				|| cmd.verb == "sword" || cmd.verb == "pen" || cmd.verb == "neither") {
			// The answer may arrive as "answer neither", "say pen", or bare "neither".
			std::string ans = cmd.noun.empty() ? cmd.verb : cmd.noun;
			if (!riddlePosed) {
				printSlow("The figure has asked you nothing yet.\n\n");
			} else if (ans.find("neither") != std::string::npos) {
				printSlow("You choose neither. The figure's posture softens.\n");
				printRedAndSlow("A fine answer, traveller. Wise is the one who knows the sword's\n"
					"edge, and brave the one who knows the reach of the pen.\n");
				printSlow("It presses a heavy, dust-covered book into your hands — an Ancient\n"
					"Tome, its ink shifting on the page as though alive.\n\n");
				return Solved;
			} else if (ans.find("sword") != std::string::npos || ans.find("pen") != std::string::npos) {
				printSlow("The figure smiles a wicked, too-wide smile. Its body cracks and\n"
					"distorts, unfolding into a hulking werewolf with bright red eyes.\n");
				printRedAndSlow(ans.find("sword") != std::string::npos
					? "Unwise is the one who forsakes the pen for the sword.\n"
					: "Cowardly is the one who forsakes the sword for the pen.\n");
				printSlow("It lunges, and the darkness takes you.\n\n");
				return Died;
			} else {
				printSlow("The figure waits. \"The sword, the pen, or neither?\"\n\n");
			}
		} else if (cmd.verb == "leave") {
			printSlow("You back away from the fire. The figure watches you go, its eyes\n"
				"following until you are out of sight.\n\n");
			return Left;
		} else {
			printSlow("The figure only watches.\n\n");
		}
	}
}
