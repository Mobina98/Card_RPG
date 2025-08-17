#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Deck.hpp"
#include "Energy.hpp"
#include "Effect.hpp"

class Board;

class Player : public std::enable_shared_from_this<Player> {
protected:
    std::string name_;
    int health_{30};
    Deck deck_;
    std::vector<std::shared_ptr<Card>> hand_;
public:
    Energy energy;
    Effect effect;
    explicit Player(std::string name);
    virtual ~Player() = default;
    const std::string& name() const { return name_; }
    int health() const { return health_; }
    void heal(int amount);
    void damage(int amount);
    void giveDeck(Deck d);
    Deck& deck();
    const std::vector<std::shared_ptr<Card>>& hand() const { return hand_; }
    bool draw();
    virtual bool takeTurn(Board& board, Player& opponent); // human via console
    void discardHand(); // helper after game end
};
