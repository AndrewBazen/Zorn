# Zorn build.  Run `make` for the game, `make ptest` for the parser test.
CXX      := g++
CXXFLAGS := -std=c++20 -Isrc -g -pthread

# All translation units, grouped by package. (-Isrc lets any file include
# another with a path from src/, e.g. #include "world/gamestate.h".)
SRCS := $(wildcard src/*.cpp) \
        $(wildcard src/world/*.cpp) \
        $(wildcard src/parser/*.cpp) \
        $(wildcard src/puzzles/*.cpp) \
        $(wildcard src/util/*.cpp)

# Build the whole game.
# NOTE: during the parser refactor the full game may not compile yet
# (areas.cpp / gamestate.cpp are mid-rewrite). Use `make ptest` meanwhile.
game: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o zorn

# The parser is world-agnostic, so it builds and tests in isolation.
ptest: tests/parser_test.cpp src/parser/parser.cpp
	$(CXX) $(CXXFLAGS) tests/parser_test.cpp src/parser/parser.cpp -o ptest

clean:
	rm -f zorn zorn.exe ptest ptest.exe

.PHONY: game ptest clean
