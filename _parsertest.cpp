// scratch test — g++ -std=c++20 _parsertest.cpp parser.cpp -o ptest && ./ptest
#include "parser.h"
#include <iostream>

int main() {
    for (std::string line : {"look", "go north", "n", "take the brass lamp",
                             "put coin in slot", "unlock door with key", ""}) {
        Command c = parseCommand(line);
        std::cout << "[" << line << "]\n   verb='" << c.verb
                  << "' noun='" << c.noun << "' prep='" << c.prep
                  << "' obj2='" << c.object2 << "'\n";
    }
}
