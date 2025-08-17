#include <gtest/gtest.h>
#include "CardGame/Deck.hpp"
#include "CardGame/AttackCard.hpp"

TEST(Deck, DrawReducesSize){
    Deck d;
    d.add(std::make_shared<AttackCard>());
    d.add(std::make_shared<AttackCard>());
    size_t before = d.size();
    auto c = d.draw();
    ASSERT_NE(c, nullptr);
    EXPECT_EQ(d.size(), before-1);
}
