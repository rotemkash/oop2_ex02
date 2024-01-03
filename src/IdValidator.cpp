#include "IdValidator.h"

std::string IdValidator::PrintError() const { return "Wrong control digit"; }

/* returns the length of the number */
int IdValidator::uintLen(uint32_t num) const {
  uint32_t tmp = num;
  int len = 0;

  while (tmp != 0) {
    tmp = tmp / 10;
    ++len;
  }
  return len;
}

/* validates that the id entered is valid */
bool IdValidator::validate(const uint32_t& fieldToValidate) const {
  int sum = 0, incNum;
  uint32_t numArr[9] = {0};
  uint32_t tmp = fieldToValidate;

  // check the length of the number
  if (uintLen(fieldToValidate) != 9) {
    return false;
  }

  // convert the number to an array for easy check later
  for (int i = 8; i >= 0; i--) {
    numArr[i] = tmp % 10;
    tmp = tmp / 10;
  }

  // validate the id number
  for (int i = 0; i < 9; i++) {
    incNum = numArr[i] * ((i % 2) + 1);
    sum += (incNum > 9) ? incNum - 9 : incNum;
  }

  return (sum % 10 == 0);
}
