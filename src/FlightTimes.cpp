#include "FlightTimes.h"

std::string FlightTimes::print() const { return m_str; }

/* returns the time matching the answer, if the asnwer was invalid it rteurns
 * the answer as a number */
std::string FlightTimes::GetTime() const {
  if (m_answer <= 0 || m_answer >= m_locations->size()) {
    return std::to_string(m_answer);
  }
  return m_locations[m_answer - 1];
}

std::ostream& operator<<(std::ostream& os, const FlightTimes& val2Name) {
  os << val2Name.GetTime();
  return os;
}

void FlightTimes::setAnswer(std::istream& is) { is >> m_answer; }

std::istream& operator>>(std::istream& is, FlightTimes& val2Name) {
  val2Name.setAnswer(is);
  return is;
}

int const& FlightTimes::getAnswer() const { return m_answer; }

bool operator<=(const FlightTimes& val1, int val2) {
  return val1.getAnswer() <= val2;
}

bool operator>=(const FlightTimes& val1, int val2) {
  return val1.getAnswer() >= val2;
}