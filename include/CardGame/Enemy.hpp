#pragma once
#include "Player.hpp"

class Enemy : public Player {
public:
    explicit Enemy(std::string name);
    bool takeTurn(Board& board, Player& opponent) override; // AI
};
