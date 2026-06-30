#pragma once

#include "command.h"
#include <string>

// Turn one raw line of player input into a structured Command.
//
// This is PURE text processing: it knows nothing about the game world
// (no rooms, no objects, no Gamestate). That's deliberate — it means you
// can unit-test it by feeding strings and checking the Command fields.
//
// A blank/empty line yields a Command with an empty verb; the caller should
// treat that as "reprompt". A verb the game doesn't recognize still parses
// fine here — deciding "I don't understand that" is the dispatcher's job.
Command parseCommand(const std::string& input);
