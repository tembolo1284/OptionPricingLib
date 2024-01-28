//
// RandomWalkGenerator.cpp
//
#include "../include/RandomWalkGenerator.hpp"
#include <cstdlib>
#include <iostream>

RandomWalkGenerator::RandomWalkGenerator(int size, double start, double step) : m_numSteps(size), m_stepSize(step), m_initialPrice(start) {}

RandomWalkGenerator::RandomWalkGenerator(const RandomWalkGenerator &src) : m_numSteps(src.m_numSteps), m_stepSize(src.m_stepSize), m_initialPrice(src.m_initialPrice) {}

RandomWalkGenerator::~RandomWalkGenerator() {
  std::cout << "Deleting RandomWalkGenerator...\n";
}

RandomWalkGenerator &RandomWalkGenerator::operator=(const RandomWalkGenerator &src) {
  if (this != &src) {
    m_numSteps = src.m_numSteps;
    m_stepSize = src.m_stepSize;
    m_initialPrice = src.m_initialPrice;
  }

  return *this;
}

double RandomWalkGenerator::computeRandomStep(double currPx) {
  const int num_directions = 3;
  int r = rand() % num_directions;
  double val = currPx;
  if (r == 0) {
    val += (m_stepSize * val);
  } 
  else if (r == 1) {
    val -= (m_stepSize * val);    
  }

  return val;
}

std::vector<double> RandomWalkGenerator::generateWalk() {
  std::vector<double> walk;
  double prev = m_initialPrice;
  for (int i = 0; i < m_numSteps; i++) {
    double val = computeRandomStep(prev);
    walk.push_back(val);
    prev = val;
  }
  return walk;
}
