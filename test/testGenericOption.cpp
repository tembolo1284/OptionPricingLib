#include <gtest/gtest.h>
#include "../include/GenericOption.hpp"

TEST(GenericOptionTest, TestValueAtExpiryCallOption) {
  // Create a call option with a strike of 101 and cost of 10.5
  GenericOption callOption(101, OptionType_Call, 10.5);

  // The value of a call option should be (Underlying Price - Strike)
  EXPECT_DOUBLE_EQ(callOption.valueAtExpiry(110.0), 110.0 - 101.0);
}

TEST(GenericOptionTest, TestProfitAtExpiryPutOption) {
  // Create a put option with a strike of 52.75 and a cost of 5
  GenericOption putOption(52.75, OptionType_Put, 5.0);

  // Calc the profit at expirty for underlying price of 45
  double profit = putOption.profitAtExpiry(45.0);

  // The profit of a put option should be (strike - underlying price - cost)
  EXPECT_DOUBLE_EQ(profit, 52.75 - 45.0 - 5);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
