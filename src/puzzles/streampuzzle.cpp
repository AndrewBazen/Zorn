/* streampuzzle.cpp
* @AndrewBazen
* @description: cross the stream by jumping the stepping stones in the correct
*               left/right order. The order is hidden in the sign's poem
*               (capital letters: River, Leaves, Look, Round, Loss -> R L L R L).
*/

#include "streampuzzle.h"
#include "util/utilities.h"
#include "parser/parser.h"
#include "world/puzzle.h"
#include <format>
#include <iostream>
#include <string>
#include <vector>

namespace {
	// "left" / "right" from the player's noun, or "" if it names neither.
	std::string dirFrom(const std::string& noun) {
		if (noun.find("left") != std::string::npos) return "left";
		if (noun.find("right") != std::string::npos) return "right";
		return "";
	}
}

PuzzleResult streamPuzzle() {
	int chances = 3;
	std::vector<std::string> answer = { "right", "left", "left", "right", "left" };
	std::vector<std::string> jumped;

	printSlow("You step up to the water's edge. Just below the surface the stepping\n"
		"stones are set in pairs — a left and a right — all the way across. In each\n"
		"pair one stone will hold your weight and the other will not. A wrong step\n"
		"means the current. Do you jump left, or right?\n\n");

	while (true) {
		std::cout << "> ";
		std::string line;
		if (!std::getline(std::cin, line)) return Left;   // EOF (Ctrl-D) -> leave
		Command cmd = parseCommand(line);

		std::string dir = dirFrom(cmd.noun);
		if (cmd.verb == "jump" || cmd.verb == "step") {
			if (dir.empty()) {
				printSlow("Left stone, or right stone?\n\n");
			} else if (dir == answer[jumped.size()]) {
				jumped.push_back(dir);
				if (jumped.size() == answer.size()) {
					printSlow("The stone holds, and you spring to the far bank — soaked, shaking,\n"
						"but alive. Half-buried in the moss lies a longsword, its blade giving\n"
						"off a soft white glow. You take up the Sword of Light.\n\n");
					return Solved;
				}
				printSlow(std::format("The {} stone holds firm. {} stones still lie ahead.\n\n",
					dir, answer.size() - jumped.size()));
			} else {
				jumped.clear();
				--chances;
				if (chances > 0) {
					printSlow("The stone gives way and the icy current drags you under. You come\n"
						"to coughing and shivering, back on the bank beside the sign.\n\n");
				} else {
					printSlow("The stone gives way one last time. The cold and the dark close\n"
						"over you, and this time you do not surface.\n\n");
					printRedAndSlow("You are lost to the stream.\n\n");
					return Died;
				}
			}
		} else if (cmd.verb == "leave") {
			return Left;
		} else if (cmd.verb == "read" || cmd.verb == "examine") {
			if (cmd.noun.find("sign") != std::string::npos) {
				printSlow("The sign reads:\n"
					"  dark and cold the River flows, ominously the trees Leaves blow\n"
					"  Look below the surface found, a helping hand, solid and Round\n"
					"  a leap of faith is needed to cross, but one is gain and one is Loss\n\n");
			} else {
				printSlow("Just the stream, the stones, and the sign.\n\n");
			}
		} else {
			printSlow("You can't do that here.\n\n");
		}
	}
}
