#include "CardGame/TrapCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"
#include <sstream>

std::string TrapCard::info() const {
    std::ostringstream os; os << "Trap " << triggerDamage_ << " (Cost " << cost_ << ")";
    return os.str();
}

bool TrapCard::play(Player& self, Player& opponent, Board& board) {
    if (!self.energy.spend(cost_)) return false;
    opponent.damage(triggerDamage_);
    board.log(self.name() + " set a trap dealing " + std::to_string(triggerDamage_));
    return true;
}
