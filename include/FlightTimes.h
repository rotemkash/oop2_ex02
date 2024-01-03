#pragma once

#include <iostream>
#include <string>

class FlightTimes {
 public:
  std::string print() const;

  std::string GetTime() const;

  void setAnswer(std::istream& is);

  int const& getAnswer() const;

 private:
  std::string m_str = "(1 - Morning/Noon, 2 - After-Noon/Evening, 3 - Night)";

  std::string m_locations[5] = {"Morning/Noon", "After-Noon/Evening", "Night"};

  int m_answer;
};

std::ostream& operator<<(std::ostream& os, const FlightTimes& val2Name);

std::istream& operator>>(std::istream& is, FlightTimes& val2Name);

bool operator<=(const FlightTimes& val1, int val2);

bool operator>=(const FlightTimes& val1, int val2);