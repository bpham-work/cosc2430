#include "player.h"
#include "gtest/gtest.h"

namespace {
    TEST(Player, ShouldDeduct15PercentOfMoney) {
        Player player("john", 100);

        player.deductMoney();

        ASSERT_EQ(85, player.getMoney());
    }

    TEST(Player, ShouldNotStopPlayingIfCurrentMoneyIsOver10PercentOfStarting) {
        Player player("john", 100);
        player.deductMoney(); // 85

        bool result = player.shouldStopPlaying();

        ASSERT_FALSE(result);
    }

    TEST(Player, ShouldStopPlayingIfCurrentMoneyIsUnder10PercentOfStarting) {
        Player player("john", 100);
        player.setMoney(5);

        bool result = player.shouldStopPlaying();

        ASSERT_TRUE(result);
    }
}
