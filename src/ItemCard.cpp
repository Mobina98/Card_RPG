#include "CardGame/ItemCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"

std::string ItemCard::info() const {
    return "Item (Cost " + std::to_string(cost_) + ")";
}

bool ItemCard::play(Player& self, Player& opponent, Board& board) {
    (void)opponent;
    if (!self.energy.spend(cost_)) return false;
    board.log(self.name() + " used an item");
    return true;
}
