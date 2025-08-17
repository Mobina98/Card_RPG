#include "CardGame/EquipmentCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"

std::string EquipmentCard::info() const {
    return "Equipment +" + std::to_string(bonus_) + " (Cost " + std::to_string(cost_) + ")";
}

bool EquipmentCard::play(Player& self, Player& opponent, Board& board) {
    (void)opponent;
    if (!self.energy.spend(cost_)) return false;
    self.effect.attackBuff += bonus_;
    self.effect.turns = 3;
    board.log(self.name() + " equipped for +" + std::to_string(bonus_));
    return true;
}
