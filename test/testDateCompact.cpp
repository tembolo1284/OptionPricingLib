#include <gtest/gtest.h>
#include "../include/DateCompact.hpp"

// Test case for setting and getting the year
TEST(DateCompactTest, SetGetYear) {
    DateCompact date(2024, 1, 28);
    date.setYear(2025);
    ASSERT_EQ(date.year(), 2025);
}

// Test case for setting and getting the month
TEST(DateCompactTest, SetGetMonth) {
    DateCompact date(2024, 1, 28);
    date.setMonth(12);
    ASSERT_EQ(date.month(), 12);
}

// Test case for setting and getting the day
TEST(DateCompactTest, SetGetDay) {
    DateCompact date(2024, 1, 28);
    date.setDay(15);
    ASSERT_EQ(date.day(), 15);
}

// Test case for equality operator
TEST(DateCompactTest, EqualityOperator) {
    DateCompact date1(2024, 1, 28);
    DateCompact date2(2024, 1, 28);
    ASSERT_TRUE(date1 == date2);
}

