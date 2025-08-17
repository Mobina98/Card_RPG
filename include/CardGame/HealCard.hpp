#pragma once
#include "Card.hpp"

class HealCard : public Card {
    int heal_;
public:
    HealCard(int heal=4, int cost=2) : Card("Heal", cost), heal_(heal) {}
    int healAmount() const { return heal_; }
    std::string type() const override { return "HealCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
