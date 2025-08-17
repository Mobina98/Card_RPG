#include "CardGame/AttackCard.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Board.hpp"
#include <sstream>

std::string AttackCard::info() const {
    std::ostringstream os; os << "Attack " << damage_ << " (Cost " << cost_ << ")";
    return os.str();
}

bool AttackCard::play(Player& self, Player& opponent, Board& board) {
    if (!self.energy.spend(cost_)) return false;
    int bonus = self.effect.attackBuff;
    opponent.damage(damage_ + bonus);
    board.log(self.name() + " attacked for " + std::to_string(damage_ + bonus));
    return true;
}
