#include <gtest/gtest.h>
#include "../include/Date.hpp"

TEST(DateTest, ConstructorAndGetters) {
    Date date(2023, 5, 15);

    EXPECT_EQ(date.month(), "May");
    EXPECT_EQ(date.dayOfWeek(), "Monday"); // Adjust as per your dayOfWeek implementation
}

TEST(DateTest, AddDays) {
    Date date(2023, 6, 15);

    date.add(20); // Adding 20 days

    EXPECT_EQ(date.month(), "July");
}

TEST(DateTest, DateComparison) {
    Date date1(2023, 5, 15);
    Date date2(2023, 5, 22);
    Date date3(2022, 12, 31);

    EXPECT_TRUE(date1 < date2);
    EXPECT_FALSE(date2 < date1);
    EXPECT_TRUE(date3 < date1);
    EXPECT_TRUE(date1 == date1);
    EXPECT_FALSE(date1 == date2);
}

