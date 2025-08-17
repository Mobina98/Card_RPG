#pragma once
#include "Card.hpp"

class SpellCard : public Card {
    int buff_;
public:
    SpellCard(int buff=2, int cost=3) : Card("Spell", cost), buff_(buff) {}
    int buff() const { return buff_; }
    std::string type() const override { return "SpellCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
