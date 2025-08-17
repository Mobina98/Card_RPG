#pragma once
#include <vector>
#include <memory>
#include <random>
#include "Card.hpp"

class Deck {
    std::vector<std::shared_ptr<Card>> cards_;
public:
    void add(std::shared_ptr<Card> c) { cards_.push_back(std::move(c)); }
    size_t size() const { return cards_.size(); }
    void shuffle();
    std::shared_ptr<Card> draw();
};
