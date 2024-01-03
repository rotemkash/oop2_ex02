#pragma once

#include <iostream>
#include <string>

class DestinationNames {
 public:
  std::string print() const;

  std::string getLocation() const;

  void setAnswer(std::istream& is);

  int const& getAnswer() const;

 private:
  std::string m_str =
      "(1 - Rome, 2 - Prague, 3 - New York, 4 - India, 5 - Thailand)";

  std::string m_locations[5] = {"Rome", "Prague", "New York", "India",
                                "Thailand"};
  int m_answer;
};

std::ostream& operator<<(std::ostream& os, const DestinationNames& val2Name);

std::istream& operator>>(std::istream& is, DestinationNames& val2Name);

bool operator<=(const DestinationNames& val1, int val2);

bool operator>=(const DestinationNames& val1, int val2);