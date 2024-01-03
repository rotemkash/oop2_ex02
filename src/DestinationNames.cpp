#include "DestinationNames.h"

std::string DestinationNames::print() const { return m_str; }

/* returns the location matching the answer, if the answer is invalid it returns
 * the answer as a number */
std::string DestinationNames::getLocation() const {
  if (m_answer <= 0 || m_answer >= m_locations->size()) {
    return std::to_string(m_answer);
  }
  return m_locations[m_answer - 1];
}

std::ostream& operator<<(std::ostream& os, const DestinationNames& val2Name) {
  os << val2Name.getLocation();
  return os;
}

void DestinationNames::setAnswer(std::istream& is) { is >> m_answer; }

std::istream& operator>>(std::istream& is, DestinationNames& val2Name) {
  val2Name.setAnswer(is);
  return is;
}

bool operator<=(const DestinationNames& val1, int val2) {
  return val1.getAnswer() <= val2;
}

bool operator>=(const DestinationNames& val1, int val2) {
  return val1.getAnswer() >= val2;
}

int const& DestinationNames::getAnswer() const { return m_answer; }