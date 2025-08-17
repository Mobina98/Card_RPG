#include <gtest/gtest.h>
#include "CardGame/Player.hpp"
#include "CardGame/Enemy.hpp"
#include "CardGame/Board.hpp"
#include "CardGame/AttackCard.hpp"
#include "CardGame/HealCard.hpp"

TEST(Cards, AttackAndHeal){
    Board b;
    Player p("P");
    Enemy e("E");
    int eHP = e.health();
    AttackCard atk(5, 0); // cost 0 for test
    atk.play(p, e, b);
    EXPECT_LT(e.health(), eHP);

    int pHP = p.health();
    p.damage(6);
    HealCard heal(4, 0);
    heal.play(p, e, b);
    EXPECT_EQ(p.health(), pHP-2); // 6 damage then 4 heal
}
