#pragma once
#include <memory>
#include <string>

class Player;

class Board {
public:
    std::weak_ptr<Player> p1;
    std::weak_ptr<Player> p2;
    std::string lastEvent;
    void log(const std::string& s){ lastEvent = s; }
};
