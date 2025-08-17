#include "CardGame/Battle.hpp"
#include "CardGame/Player.hpp"

bool Battle::isOver(const Player& a, const Player& b){
    return a.health() <= 0 || b.health() <= 0;
}
