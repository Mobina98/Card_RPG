#include "CardGame/Deck.hpp"
#include <algorithm>

void Deck::shuffle() {
    std::random_device rd; std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);
}

std::shared_ptr<Card> Deck::draw() {
    if (cards_.empty()) return nullptr;
    auto c = cards_.back();
    cards_.pop_back();
    return c;
}
