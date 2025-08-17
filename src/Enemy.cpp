#include "CardGame/Enemy.hpp"
#include "CardGame/Board.hpp"
#include "CardGame/Card.hpp"
#include "CardGame/AttackCard.hpp"
#include "CardGame/HealCard.hpp"
#include <iostream>

Enemy::Enemy(std::string name) : Player(std::move(name)) {}

bool Enemy::takeTurn(Board& board, Player& opponent){
    std::cout << "\n-- " << name_ << " (AI) turn --\n";
    effect.tick();
    energy.refresh();
    draw();
    // Simple heuristic: if low HP and have heal in hand, try heal; else play first affordable card.
    size_t choice = 0;
    for (size_t i=0;i<hand_.size();++i){
        if (dynamic_cast<HealCard*>(hand_[i].get()) && health_ <= 15 && hand_[i]->cost() <= energy.current) { choice = i+1; break; }
    }
    if (choice==0){
        for (size_t i=0;i<hand_.size();++i){
            if (hand_[i]->cost() <= energy.current){ choice = i+1; break; }
        }
    }
    if (choice==0){ std::cout << "AI skips turn.\n"; return false; }
    auto card = hand_[choice-1];
    (void)card->play(*this, opponent, board);
    hand_.erase(hand_.begin()+choice-1);
    std::cout << "AI played: " << board.lastEvent << "\n";
    return true;
}
