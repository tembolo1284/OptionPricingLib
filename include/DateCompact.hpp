//
// DateCompact.hpp
//
#ifndef _DateCompact_HPP
#define _DateCompact_HPP

class DateCompact {
private:
  char m_date[8];

public:
  DateCompact(int year, int month, int day);
  DateCompact(const DateCompact &src);
  virtual ~DateCompact();
 
  DateCompact &operator=(const DateCompact &src);
  void setYear(int y);
  void setMonth(int m);
  void setDay(int d);

  int year();
  int month();
  int day();

  void print();

  bool operator==(const DateCompact &d) const;
  bool operator<(const DateCompact &d) const;


}; // class DateCompact

#endif /* defined(_DateCompact_HPP)*/
