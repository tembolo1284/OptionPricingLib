#include <gtest/gtest.h>
#include "../include/RandomWalkGenerator.hpp"

// Test case for generating a random walk of specified size
TEST(RandomWalkGeneratorTest, GenerateWalkSize) {
    RandomWalkGenerator generator(10, 100.0, 1.0);
    std::vector<double> walk = generator.generateWalk();
    ASSERT_EQ(walk.size(), 10); // Size should be 11 (initial + 10 steps)
}

// Test case for generating a random walk with the correct initial price
TEST(RandomWalkGeneratorTest, GenerateWalkInitialPrice) {
    RandomWalkGenerator generator(10, 100.0, 1.0);
    std::vector<double> walk = generator.generateWalk();
    ASSERT_EQ(walk[0], 100.0); // Initial price should be 100.0
}

// Test case for computing a random step
TEST(RandomWalkGeneratorTest, ComputeRandomStep) {
    RandomWalkGenerator generator(1, 100.0, 2.0);
    double step = generator.computeRandomStep(100.0) - 100;
    ASSERT_TRUE(step >= -2.0 && step <= 2.0); // Step should be within [-2.0, 2.0]
}
