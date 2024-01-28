#ifndef _GenericOption_HPP
#define _GenericOption_HPP
#include <stdio.h>

enum OptionType {
  OptionType_Call,
  OptionType_Put
};

class GenericOption {
  private:
    double m_strike;
    OptionType m_type;
    double m_cost;

  public:
    GenericOption(double strike, OptionType type, double cost);
    GenericOption(const GenericOption &src);
    ~GenericOption();
    GenericOption &operator=(const GenericOption &src);

    double valueAtExpiry(double underlyingAtExpiry);
    double profitAtExpiry(double underlyingAtExpiry);

 
}; // GenericOption 

#endif /* defined(_GenericOption_) */
