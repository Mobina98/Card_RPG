#pragma once
#include "Card.hpp"

class EquipmentCard : public Card {
    int bonus_;
public:
    EquipmentCard(int bonus=1, int cost=1) : Card("Equipment", cost), bonus_(bonus) {}
    std::string type() const override { return "EquipmentCard"; }
    std::string info() const override;
    bool play(Player& self, Player& opponent, Board& board) override;
};
