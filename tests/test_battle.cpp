#include <gtest/gtest.h>
#include "CardGame/Battle.hpp"
#include "CardGame/Player.hpp"
#include "CardGame/Enemy.hpp"

TEST(Battle, EndsWhenHPZero){
    Player p("P");
    Enemy e("E");
    e.damage(100);
    EXPECT_TRUE(Battle::isOver(p, e));
}
