#pragma once
#include "Card.hpp"

class ItemCard : public Card {
public:
    ItemCard(int cost=0) : Card("Item", cost) {}
    std::string type() const override { return "ItemCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
