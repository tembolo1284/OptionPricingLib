//
// DateCompact.cpp
//
#include "../include/DateCompact.hpp"
#include <cstring>
#include <iostream>

DateCompact::DateCompact(int year, int month, int day) {
  setYear(year);
  setMonth(month);
  setDay(day);
}

DateCompact::DateCompact(const DateCompact &src) {
  strcpy(m_date, src.m_date);
}

DateCompact::~DateCompact() {
  std::cout << "Deleted DateCompact...\n";
}

DateCompact &DateCompact::operator=(const DateCompact &src) {
  if (&src != this) {
    strcpy(m_date, src.m_date);
  }
  return *this;
}

bool DateCompact::operator==(const DateCompact &d) const {
  return strncmp(m_date, d.m_date, 8) == 0;
}

bool DateCompact::operator<(const DateCompact &d) const {
  return strncmp(m_date, d.m_date, 8) < 0;
}

int DateCompact::year() {
  return 1000 * (m_date[0] - '0') + 100 * (m_date[1] - '0') + 10 * (m_date[2] - '0') + (m_date[3] - '0');
}

int DateCompact::month() {
  return 10 * (m_date[4] - '0') + (m_date[5] - '0');
}

int DateCompact::day() {
  return 10 * (m_date[6] - '0') + (m_date[7] - '0');
}

void DateCompact::print() {
  char s[9];
  strncpy(s, m_date, 8);
  s[8] = '\0';
  std::cout << s << "\n";
}

void DateCompact::setYear(int year) {
  m_date[3] = '0' + static_cast<char>(year % 10);
  year /= 10;

  m_date[2] = '0' + static_cast<char>(year % 10);
  year /= 10;

  m_date[1] = '0' + static_cast<char>(year % 10);
  year /= 10;

  m_date[0] = '0' + static_cast<char>(year % 10);
}

void DateCompact::setMonth(int month) {
  m_date[5] = '0' + static_cast<char>(month % 10);
  month /= 10;
  
  m_date[4] = '0' + static_cast<char>(month % 10);
  month /= 10;
}

void DateCompact::setDay(int day) {
  m_date[7] = '0' + static_cast<char>(day % 10);
  day /= 10;
  
  m_date[6] = '0' + static_cast<char>(day % 10);
  day /= 10;
}

