#pragma once
#include <memory>

class Player;

struct Battle {
    static bool isOver(const Player& a, const Player& b);
};
