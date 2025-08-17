#include "CardGame/HealCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"
#include <sstream>

std::string HealCard::info() const {
    std::ostringstream os; os << "Heal " << heal_ << " (Cost " << cost_ << ")";
    return os.str();
}

bool HealCard::play(Player& self, Player& opponent, Board& board) {
    (void)opponent;
    if (!self.energy.spend(cost_)) return false;
    self.heal(heal_);
    board.log(self.name() + " healed " + std::to_string(heal_));
    return true;
}
