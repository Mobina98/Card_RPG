#pragma once
#include "Card.hpp"

class TrapCard : public Card {
    int triggerDamage_;
public:
    TrapCard(int dmg=3, int cost=1) : Card("Trap", cost), triggerDamage_(dmg) {}
    int triggerDamage() const { return triggerDamage_; }
    std::string type() const override { return "TrapCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
