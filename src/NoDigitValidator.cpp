#include "NoDigitValidator.h"

std::string NoDigitValidator::PrintError() const {
  return "Cannot contain digits!";
}

/* checks if the name entered is valid */
bool NoDigitValidator::validate(const std::string& fieldToValidate) const {
  for (int i = 0; i < fieldToValidate.size(); i++) {
    if (std::isdigit(fieldToValidate[i])) {
      return false;
    }
  }
  return true;
}
