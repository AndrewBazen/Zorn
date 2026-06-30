#include "parser.h"

#include <cstddef>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

// File-local helpers + tables. The unnamed namespace gives them "internal
// linkage" — they're private to this .cpp and invisible to the rest of the
// program. Good default for helpers nothing else needs to call.
namespace {

// Words the parser throws away entirely (articles / filler).
const std::unordered_set<std::string> kNoiseWords = {
    "the", "a", "an",
    // TODO: add others if they get in the way ("at" is tricky — see note in parseCommand)
};

// Prepositions that separate a direct object from an indirect object,
// e.g. "put coin IN slot", "unlock door WITH key".
const std::unordered_set<std::string> kPrepositions = {
    "in", "on", "with", "at", "to", "under",
    // TODO: extend as your puzzles need
};

// Canonical compass directions (after abbreviation expansion below).
const std::unordered_set<std::string> kDirections = {
    "north", "south", "east", "west", "up", "down",
};

// Raw word -> canonical form. Covers verb synonyms AND direction abbreviations.
// Add an entry every time you teach the game a new word.
const std::unordered_map<std::string, std::string> kSynonyms = {
    {"grab", "take"}, {"get", "take"},
    {"x", "examine"}, {"inspect", "examine"}, {"look", "look"}, {"l", "look"},
    {"n", "north"}, {"s", "south"}, {"e", "east"}, {"w", "west"}, {"u", "up"}, {"d", "down"},
    // TODO: add your verbs and their synonyms
};

// Lowercase an entire string. (Worked example — match this style for the rest.)
std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
}

// Split a string into whitespace-separated words.
std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> words;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Map a raw word to its canonical form, or return it unchanged if unknown.
std::string canonical(const std::string& word) {
    auto it = kSynonyms.find(word);
    return it != kSynonyms.end() ? it->second : word;
}

// Join words[begin .. end) into one space-separated phrase.
// e.g. join({"sun","tree"}, 0, 2) -> "sun tree"
std::string join(const std::vector<std::string>& words, size_t begin, size_t end) {
    std::string phrase;
    for (size_t i = begin; i < end; i++) {
        if (i != begin) { phrase += " "; }
        phrase += words[i]; 
    }
    return phrase;
}

} // namespace

Command parseCommand(const std::string& input) {
    Command cmd;

    // 1. Normalize case, then split into words.
    std::vector<std::string> words = tokenize(toLower(input));

    // 2. Drop noise words (articles/filler) so "take the lamp" == "take lamp".
    words.erase(
        std::remove_if(words.begin(), words.end(),
                        [](const std::string& w) { return kNoiseWords.contains(w);}),
        words.end());

    // 3. Nothing left? Empty verb signals "blank line" to the caller.
    if (words.empty()) return cmd;

    // 4. The first word is the verb. Canonicalize it.
    //    Special case: a bare direction ("north", or "n" -> "north") really
    //    means "go north" — rewrite it to verb="go", noun=<direction>.
    // TODO:
    //   - std::string head = canonical(words[0]);
    //   - if head is in kDirections: cmd.verb = "go"; cmd.noun = head; return cmd;
    //   - else: cmd.verb = head;  (then the rest of `words` is the object phrase)
    std::string head = canonical(words[0]);
    if (kDirections.contains(head)) {
        cmd.verb = "go";
        cmd.noun = head;
        return cmd;
    } else {
        cmd.verb = head;
    }

    // 5. Find a preposition in the remaining words and split around it:
    //      before the prep -> noun       (direct object)
    //      the prep itself -> prep
    //      after the prep  -> object2    (indirect object)
    //    If there's no preposition, everything after the verb is the noun.
    // TODO:
    //   - scan words[1..] for the first token that's in kPrepositions
    //   - found at index p:  cmd.noun = join(words, 1, p);
    //                        cmd.prep = words[p];
    //                        cmd.object2 = join(words, p + 1, words.size());
    //   - not found:         cmd.noun = join(words, 1, words.size());
   bool foundPrep = false;
    for (size_t i = 1; i < words.size(); i++) {
        if (kPrepositions.contains(words[i])) {
            cmd.noun = join(words, 1, i);
            cmd.prep = words[i];
            cmd.object2 = join(words, i + 1, words.size());
            foundPrep = true;
            break;
        }
    }

    if (!foundPrep) {
        cmd.noun = join(words, 1, words.size());
    }

    return cmd;
}

/*
 * KNOWN WRINKLES to iterate on later (don't solve them now — just so you're
 * not surprised). Real parsers grow these gradually:
 *
 *   - Multi-word verbs: "look at lamp" and "pick up lamp" read as verb + prep.
 *     You'll likely normalize "look at" -> "examine" and "pick up" -> "take"
 *     BEFORE the preposition scan in step 5.
 *   - Unknown verbs: parseCommand happily returns them; the DISPATCHER decides
 *     "I don't understand that." Keep that judgment out of the parser.
 *   - Multi-word object names ("brass lamp"): the parser keeps the whole phrase;
 *     matching it to an actual world object is the verb handler's job, not this.
 */
