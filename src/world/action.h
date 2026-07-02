#pragma once

#include <string>

enum class ActionResult { Info, Gain, Effect };

struct Action {
    ActionResult result;
    std::string output;
    std::string effect;
    std::string itemToGain;
};