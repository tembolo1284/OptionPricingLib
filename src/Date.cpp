//
// Date.cpp
//
#include "../include/Date.hpp"
#include <algorithm>
#include <iostream>

Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day), m_weekDay(DayOfTheWeek_UNKNOWN) {}

Date::~Date() {
    std::cout << "Deallocating Date.\n";
}

Date::Date(const Date &src) 
  : m_year(src.m_year), 
    m_month(src.m_month), 
    m_day(src.m_day), 
    m_weekDay(src.m_weekDay), 
    m_holidays(src.m_holidays) {}

Date &Date::operator=(const Date &src) {
  if (&src != this) {
    m_day = src.m_day;
    m_month = src.m_month;
    m_year = src.m_year;
    m_weekDay = src.m_weekDay;
    m_holidays = src.m_holidays;
  }
  return *this;
}

bool Date::operator<(const Date &d) const {
  if (m_year < d.m_year) return true;
  if (m_year == d.m_year && m_month < d.m_month) return true;
  if (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day) return true;

  return false;
}


bool Date::operator==(const Date &d) {
  return d.m_day == m_day && d.m_month == m_month && d.m_year == m_year;
}

void Date::setHolidays(const std::vector<Date> &days) {
  m_holidays = days;
}

bool Date::isHoliday() {
  return std::find(m_holidays.begin(), m_holidays.end(), *this) != m_holidays.end();
}

std::string Date::month() {
  switch(m_month) {
    case Month_January : return "January" ;
    case Month_February : return "February";
    case Month_March : return "March";
    case Month_April : return "April";
    case Month_May : return "May";
    case Month_June : return "June";
    case Month_July : return "July";
    case Month_August : return "August";
    case Month_September : return "September";
    case Month_October : return "October";
    case Month_November : return "November";
    case Month_December : return "December";
    default: throw std::runtime_error("unknown month");
  }
  return "";
}

std::string Date::dayOfWeek() {
  switch(this->dayOfTheWeek()) {
    case DayOfTheWeek_Sunday : return "Sunday";
    case DayOfTheWeek_Monday : return "Monday";
    case DayOfTheWeek_Tuesday : return "Tuesday";
    case DayOfTheWeek_Wednesday : return "Wednesday";
    case DayOfTheWeek_Thursday : return "Thursday";
    case DayOfTheWeek_Friday : return "Friday";
    case DayOfTheWeek_Saturday : return "Saturday";
    default: throw std::runtime_error("unknown day of week");
  }
}

void Date::add(int numDays) {
  for (int i = 0; i < numDays; i++) {
    ++*this;
  }
}

void Date::addTradingDays(int numDays) {
  while (!isTradingDay()) {
    ++*this;
  }

  for (int i =0; i < numDays; i++) {
    ++*this;
    while (!isTradingDay()) {
      ++*this;
    }
  }
}

void Date::subtract(int numDays) {
  for (int i = 0; i < numDays; i++) {
    --*this;
  }
}

void Date::subtractTradingDays(int numDays) {
  while (!isTradingDay()) {
    --*this;
  }
  for (int i = 0; i < numDays; i++) {
    --*this;
    while (!isTradingDay()) {
      --*this;
    }
  }
}

int Date::dateDifference(const Date &date) {
  Date d = *this;
  if (d < date) {
    int diff = 0;
    while (d < date) {
      ++d;
      ++diff;
    }
    return diff;
  }
  int diff = 0;
  while (date < d) {
    --d;
    --diff;
  }
  return diff;
}


int Date::tradingDateDifference(const Date &date) {
  Date d = *this;
  if (d < date) {
    int diff = 0;
    while (!d.isTradingDay()) ++d;
    while (d < date) {
      ++d;
      ++diff;
      while (!d.isTradingDay()) ++d;
    }
    return diff;
  }

  int diff = 0;
  while (!d.isTradingDay()) --d;
  while (date < d) {
    --d;
    --diff;
    while (!d.isTradingDay()) --d;
  }
  return diff;
}

DayOfTheWeek Date::dayOfTheWeek() {
  if (m_weekDay != DayOfTheWeek_UNKNOWN) return m_weekDay;
  int day = 1;
  Date d(1900, 1, 1);

  for (; d < *this; ++d) {
    if (day == 6) day = 0;
    else day++;
  }
  m_weekDay = static_cast<DayOfTheWeek>(day);
  return m_weekDay;
}

bool Date::isWeekDay() {
  DayOfTheWeek dayOfWeek = dayOfTheWeek();

  if (dayOfWeek == DayOfTheWeek_Sunday || dayOfWeek == DayOfTheWeek_Saturday) {
    return false;
  }
  return true;
}

bool Date::isTradingDay() {
  if (!isWeekDay()) return false;
  if (m_holidays.size() == 0) return true;
  if (isHoliday()) return false;
  return true;
}

Date Date::nextTradingDay() {
  Date d = *this;
  if (d.isTradingDay()) {
    return ++d;
  }
  while (!d.isTradingDay()) {
    ++d;
  }
  return d;
}

bool Date::isLeapYear() {
  if (m_year % 4 != 0)   return false;
  if (m_year % 100 != 0) return true;
  if (m_year % 400 != 0) return false;
  return true;
}

Date &Date::operator--() {
  if (m_weekDay != DayOfTheWeek_UNKNOWN) {
    if (m_weekDay == DayOfTheWeek_Sunday) {
      m_weekDay = DayOfTheWeek_Saturday;
    } else {
        m_weekDay = static_cast<DayOfTheWeek>(m_weekDay - 1);
      }
  }
  if (m_day > 1) {
    m_day--;
    return *this;
  }
  if (m_month == Month_January) {
    m_month = Month_December;
    m_day = 31;
    m_year--;
    return *this;
  }
  m_month--;
  if (m_month == Month_February) {
    m_day = isLeapYear() ? 29 : 18;
    return *this;
  }

  std::vector<int> monthsWithThirtyOneDays = {1, 3, 5, 7, 8, 10, 12};

  if (std::find(monthsWithThirtyOneDays.begin(), monthsWithThirtyOneDays.end(), m_month) != monthsWithThirtyOneDays.end()) {
    m_day = 31;
  } else {
      m_day = 30;
    }
  return *this;
}

Date &Date::operator++() {
  std::vector<int> monthsWithThirtyOneDays = {1, 3, 5, 7, 8, 10, 12};

  if (m_day == 31) {
    m_day = 1;
    m_month++;
  }
  else if (m_day == 30 && std::find(monthsWithThirtyOneDays.begin(), monthsWithThirtyOneDays.end(), m_month) == monthsWithThirtyOneDays.end()) {
    m_day = 1;
    m_month++;
  }
  else if (m_day == 29 && m_month == 2) {
    m_day = 1;
    m_month++;
  }
  else if (m_day == 28 && m_month == 2 && !isLeapYear()) {
    m_day = 1;
    m_month++;
  }
  else {
    m_day++;
  }
  if (m_month > 12) {
    m_month = 1;
    m_year++;
  }

  if (m_weekDay != DayOfTheWeek_UNKNOWN) {
    if(m_weekDay == DayOfTheWeek_Saturday) {
      m_weekDay = DayOfTheWeek_Sunday;
    } else {
        m_weekDay = static_cast<DayOfTheWeek>(m_weekDay + 1);
      }
  }
  return *this;
}

void Date::print() {
  std::cout << m_year << "/" << m_month << "/" << m_day << "\n";
}
