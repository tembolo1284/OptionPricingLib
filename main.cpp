#include "include/GenericOption.hpp"
#include "include/RandomWalkGenerator.hpp"
#include "include/Date.hpp"
#include <iostream>

int main() {
  GenericOption go1(100.0, OptionType_Put, 1.1);
  double price1 {120.0};
  double value1 = go1.valueAtExpiry(price1);

  std::cout << "For 100Put, value at expiry for price " << price1 << " is " << value1 << "\n";

  double price2 {85.0};
  double value2 = go1.valueAtExpiry(price2);

  std::cout << "For 100Put, value at expiry for price " << price2 << " is " << value2 << "\n";

  double limit = 120.0;

  double value = 0;
  for (auto price = 80.0; price <= limit; price += 0.1) {
    value = go1.profitAtExpiry(price);
    std::cout << price << ", " << value << "\n";
  }

  // 100 steps starting at 45 dollars
  RandomWalkGenerator rw(100, 45, 0.01);
  std::vector<double> walk = rw.generateWalk();
  for (size_t i = 0; i < walk.size(); i++) {
//    std::cout << i << ", " << walk[i] << "\n";
  }
  std::cout << "\n";

  Date d(2022, 9, 12);
  DayOfTheWeek wd = d.dayOfTheWeek();
  std::cout << " day of the week: " << wd << " " << d.dayOfWeek() << "\n";
  d.print();

  d.add(25);
  d.print();
  d.addTradingDays(120);
  d.print();
  std::cout << " day of the week: " << d.dayOfTheWeek() << " " << d.dayOfWeek() << "\n";

  return 0;
}
