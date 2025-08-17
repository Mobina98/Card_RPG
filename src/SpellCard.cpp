#include "CardGame/SpellCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"
#include <sstream>

std::string SpellCard::info() const {
    std::ostringstream os; os << "Buff +" << buff_ << " (Cost " << cost_ << ")";
    return os.str();
}

bool SpellCard::play(Player& self, Player& opponent, Board& board) {
    (void)opponent;
    if (!self.energy.spend(cost_)) return false;
    self.effect.attackBuff += buff_;
    self.effect.turns = 2; // lasts 2 turns
    board.log(self.name() + " cast a buff +" + std::to_string(buff_));
    return true;
}
