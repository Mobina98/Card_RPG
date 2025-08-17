#pragma once
#include <memory>
#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Turn.hpp"

class Card_Game {
    std::shared_ptr<Player> player_;
    std::shared_ptr<Enemy> enemy_;
    Board board_;
    Turn turn_;
    void setupDefaultDecks();
    void printState() const;
public:
    void startGame();
    void endGame();
};
