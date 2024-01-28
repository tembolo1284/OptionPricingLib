//
// RandomWalkGenerator.hpp
//
#ifndef _RandomWalkGenerator_HPP
#define _RandomWalkGenerator _HPP

#include <vector>

class RandomWalkGenerator {
private:
  int m_numSteps;
  double m_stepSize;
  double m_initialPrice;

public:
  // Class constructors
  RandomWalkGenerator(int size, double start, double step);
  RandomWalkGenerator(const RandomWalkGenerator &src);
  // Destructor
  virtual ~RandomWalkGenerator();
  // Assignment operator
  RandomWalkGenerator &operator=(const RandomWalkGenerator &src);

  std::vector<double> generateWalk();
  double computeRandomStep(double currPx);
}; // Class RandomWalkGenerator

#endif /* defined(_RandomWalkGenerator_HPP) */
