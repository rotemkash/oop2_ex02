#pragma once

#include <iostream>
#include <string>

class WifiBundle {
 public:
  std::string print() const;

  std::string GetBundle() const;

  void setAnswer(std::istream& is);

  int const& getAnswer() const;

 private:
  std::string m_str = "(1 - None, 2 - Basic, 3 - Extended)";

  std::string m_locations[5] = {"None", "Basic", "Extended"};

  int m_answer;
};

std::ostream& operator<<(std::ostream& os, const WifiBundle& val2Name);

std::istream& operator>>(std::istream& is, WifiBundle& val2Name);

bool operator<=(const WifiBundle& val1, int val2);

bool operator>=(const WifiBundle& val1, int val2);