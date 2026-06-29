#pragma once

#include <string>

// The structured result of parsing one line of player input.
// The parser produces this; verb handlers consume it.
// An empty field means "absent" (e.g. "look" has no noun).
struct Command {
    std::string verb;       // canonical verb:   "take", "go", "examine", "put"
    std::string noun;       // direct object:    "lamp", "sun tree"  (may be empty)
    std::string prep;       // preposition:      "in", "on", "with"  (may be empty)
    std::string object2;    // indirect object:  "slot", "key"       (may be empty)
};