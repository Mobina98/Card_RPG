#pragma once
#include "Card.hpp"

class AttackCard : public Card {
    int damage_;
public:
    AttackCard(int dmg=5, int cost=2) : Card("Attack", cost), damage_(dmg) {}
    int damage() const { return damage_; }
    std::string type() const override { return "AttackCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
