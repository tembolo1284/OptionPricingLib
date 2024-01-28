#include "../include/GenericOption.hpp"
#include <iostream>

GenericOption::GenericOption(double strike, OptionType type, double cost) : m_strike(strike), m_type(type), m_cost(cost) {}

GenericOption::GenericOption(const GenericOption &src) : m_strike(src.m_strike), m_type(src.m_type), m_cost(src.m_cost) {}

GenericOption::~GenericOption() {
  std::cout << "Bye Bye Generic Option\n";
}

GenericOption &GenericOption::operator=(const GenericOption &src) {
  if (this != &src) {
    m_type = src.m_type;
    m_strike = src.m_strike;
    m_cost = src.m_cost;
  }

  return *this;
}

double GenericOption::valueAtExpiry(double underlyingAtExpiry) {
  double value = 0.0;
  if (m_type == OptionType_Call) {
    if (m_strike < underlyingAtExpiry) {
      value = underlyingAtExpiry - m_strike;
    }
  } else {
      if (m_strike > underlyingAtExpiry) {
        value = m_strike - underlyingAtExpiry;
      }
    }
  return value;
}

double GenericOption::profitAtExpiry(double underlyingAtExpiry){
  double value = 0.0;
  double finalValue = valueAtExpiry(underlyingAtExpiry);
  if (finalValue > m_cost) {
    value = finalValue - m_cost;
  }
  return value;
}
