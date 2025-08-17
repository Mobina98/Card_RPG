#include "CardGame/Player.hpp"
#include "CardGame/Card.hpp"
#include "CardGame/Board.hpp"
#include <iostream>

Player::Player(std::string name) : name_(std::move(name)) {}

void Player::heal(int amount){ health_ += amount; if (health_ > 50) health_ = 50; }
void Player::damage(int amount){ health_ -= amount; if (health_ < 0) health_ = 0; }

void Player::giveDeck(Deck d){ deck_ = std::move(d); }
Deck& Player::deck(){ return deck_; }

bool Player::draw(){
    auto c = deck_.draw();
    if (!c) return false;
    hand_.push_back(c);
    return true;
}

bool Player::takeTurn(Board& board, Player& opponent){
    std::cout << "\n-- " << name_ << " turn --\n";
    effect.tick();
    energy.refresh();
    draw();
    std::cout << "Energy: " << energy.current << "\n";
    std::cout << "Hand:\n";
    for (size_t i=0;i<hand_.size();++i){
        std::cout << (i+1) << ") " << hand_[i]->info() << "\n";
    }
    std::cout << "Choose card number (0 to skip): ";
    size_t idx{0};
    std::cin >> idx;
    if (idx==0 || idx>hand_.size()) return false;
    auto card = hand_[idx-1];
    if (!card->play(*this, opponent, board)){
        std::cout << "Not enough energy!\n";
        return false;
    }
    hand_.erase(hand_.begin()+idx-1);
    return true;
}

void Player::discardHand(){ hand_.clear(); }
