#pragma once

#include <iostream>
#include <string>

template <class T>
class ValuesToNames {
 public:
  std::string valuesAndNames();

  void setAnswer(std::istream& is);

  void printAnswer(std::ostream& os) const;

  T const& getValue() const;

 private:
  T m_value;
};

/* returns the name of the value*/
template <class T>
std::string ValuesToNames<T>::valuesAndNames() {
  return m_value.print();
}

/* gets input from the user */
template <class T>
void ValuesToNames<T>::setAnswer(std::istream& is) {
  is >> m_value;
}

template <class T>
void ValuesToNames<T>::printAnswer(std::ostream& os) const {
  os << m_value;
}

template <class T>
T const& ValuesToNames<T>::getValue() const {
  return m_value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& val2Name) {
  val2Name.printAnswer(os);
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, ValuesToNames<T>& val2Name) {
  val2Name.setAnswer(is);
  return is;
}

/* <= operator */
template <class T>
bool operator<=(const ValuesToNames<T>& val1, int val2) {
  return val1.getValue() <= val2;
}

/* >= operator */
template <class T>
bool operator>=(const ValuesToNames<T>& val1, int val2) {
  return val1.getValue() >= val2;
}
