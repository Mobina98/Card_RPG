#pragma once
#include <string>
#include <memory>

class Player;
class Board;

class Card {
protected:
    std::string name_;
    int cost_ = 0;
public:
    Card(std::string name, int cost) : name_(std::move(name)), cost_(cost) {}
    virtual ~Card() = default;
    const std::string& name() const { return name_; }
    int cost() const { return cost_; }
    virtual std::string type() const { return "Card"; }
    virtual std::string info() const;
    virtual bool play(Player& self, Player& opponent, Board& board) = 0; // returns true if effect applied
};
