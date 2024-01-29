# Option Pricing Library

The Option Pricing Library is a comprehensive tool for pricing derivative financial instruments, commonly used in quantitative finance. It provides classes and functions for handling various aspects of option pricing and financial modeling.

## Classes and Functions

### GenericOption.hpp

**Class: `GenericOption`**

- `GenericOption(double strike, OptionType type, double cost)`: Constructor for creating a generic option with a specified strike price, option type (Call or Put), and cost.
- `GenericOption(const GenericOption &src)`: Copy constructor for creating a new option based on an existing one.
- `~GenericOption()`: Destructor for cleaning up the option.
- `GenericOption &operator=(const GenericOption &src)`: Assignment operator for assigning one option to another.
- `double valueAtExpiry(double underlyingAtExpiry)`: Calculates the option's value at expiry based on the underlying asset's price.
- `double profitAtExpiry(double underlyingAtExpiry)`: Calculates the profit at expiry based on the underlying asset's price.

### Date.hpp

**Class: `Date`**

- `Date(int year, int month, int day)`: Constructor for creating a date with a specified year, month, and day.
- `Date(const Date &src)`: Copy constructor for creating a new date based on an existing one.
- `~Date()`: Destructor for cleaning up the date.
- `Date &operator=(const Date &src)`: Assignment operator for assigning one date to another.
- `void setHolidays(const std::vector<Date> &days)`: Sets a list of holidays for the date.
- `std::string month()`: Returns the month as a string.
- `std::string dayOfWeek()`: Returns the day of the week as a string.
- Various date manipulation and comparison functions (add, subtract, dateDifference, tradingDateDifference, dayOfTheWeek, isHoliday, isWeekDay, nextTradingDay, isLeapYear, isTradingDay, print, operators for increment and decrement, comparison operators).

### RandomWalkGenerator.hpp

**Class: `RandomWalkGenerator`**

- `RandomWalkGenerator(int size, double start, double step)`: Constructor for creating a random walk generator with a specified number of steps, initial price, and step size.
- `RandomWalkGenerator(const RandomWalkGenerator &src)`: Copy constructor for creating a new random walk generator based on an existing one.
- `~RandomWalkGenerator()`: Destructor for cleaning up the random walk generator.
- `RandomWalkGenerator &operator=(const RandomWalkGenerator &src)`: Assignment operator for assigning one random walk generator to another.
- `std::vector<double> generateWalk()`: Generates a random walk sequence of prices.
- `double computeRandomStep(double currPx)`: Computes the next random step based on the current price.

## Building the Project

To build the Option Pricing Library and generate the executable for the main application and the tests using Google Test, follow these steps:

  ```shell
  cmake -B build -G Ninja
  
  cmake --build build
  ```

After building the project the executable can be found at:

./build/OptionPricingApp

The test executable will be available at:

./build/test/OptionPricingTets

