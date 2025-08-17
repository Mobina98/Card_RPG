#include "CardGame/Card.hpp"
#include <sstream>

std::string Card::info() const {
    std::ostringstream os; os << name_ << " (Cost " << cost_ << ")";
    return os.str();
}
