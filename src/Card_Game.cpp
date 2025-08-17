#include "CardGame/Card_Game.hpp"
#include "CardGame/Deck.hpp"
#include "CardGame/AttackCard.hpp"
#include "CardGame/HealCard.hpp"
#include "CardGame/SpellCard.hpp"
#include "CardGame/TrapCard.hpp"
#include "CardGame/EquipmentCard.hpp"
#include "CardGame/ItemCard.hpp"
#include "CardGame/Battle.hpp"
#include <iostream>

void Card_Game::setupDefaultDecks(){
    Deck pd, ed;
    // 2 Attack, 2 Heal, 1 Spell, 1 Trap per deck
    pd.add(std::make_shared<AttackCard>());
    pd.add(std::make_shared<AttackCard>());
    pd.add(std::make_shared<HealCard>());
    pd.add(std::make_shared<HealCard>());
    pd.add(std::make_shared<SpellCard>());
    pd.add(std::make_shared<TrapCard>());
    pd.shuffle();
    ed.add(std::make_shared<AttackCard>());
    ed.add(std::make_shared<AttackCard>());
    ed.add(std::make_shared<HealCard>());
    ed.add(std::make_shared<HealCard>());
    ed.add(std::make_shared<SpellCard>());
    ed.add(std::make_shared<TrapCard>());
    ed.shuffle();
    player_->giveDeck(std::move(pd));
    enemy_->giveDeck(std::move(ed));
}

void Card_Game::printState() const {
    auto p = player_, e = enemy_;
    std::cout << "\n=== Fantasy Card RPG ===\n";
    std::cout << p->name() << " HP: " << p->health() << " | " << e->name() << " HP: " << e->health() << "\n";
}

void Card_Game::startGame(){
    player_ = std::make_shared<Player>("Hero");
    enemy_ = std::make_shared<Enemy>("Goblin");
    board_.p1 = player_;
    board_.p2 = enemy_;
    setupDefaultDecks();
    turn_.number = 1;

    const size_t maxTurns = 10;
    while (turn_.number <= maxTurns){
        printState();
        std::cout << "Turn " << turn_.number << " / " << maxTurns << "\n";

        player_->takeTurn(board_, *enemy_);
        if (Battle::isOver(*player_, *enemy_)) break;

        enemy_->takeTurn(board_, *player_);
        if (Battle::isOver(*player_, *enemy_)) break;

        ++turn_.number;
    }

    endGame();
}

void Card_Game::endGame(){
    printState();
    if (player_->health() <= 0 && enemy_->health() <= 0) {
        std::cout << "It's a draw!\n";
    } else if (player_->health() <= 0) {
        std::cout << enemy_->name() << " wins!\n";
    } else if (enemy_->health() <= 0) {
        std::cout << player_->name() << " wins!\n";
    } else {
        // Decide by higher HP
        if (player_->health() > enemy_->health()) std::cout << player_->name() << " wins by HP!\n";
        else if (enemy_->health() > player_->health()) std::cout << enemy_->name() << " wins by HP!\n";
        else std::cout << "It's a draw by HP!\n";
    }
    player_->discardHand();
    enemy_->discardHand();
}
