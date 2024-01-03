#pragma once

#include "Validator.h"

template <class T>
class RangeValidator : public Validator<T> {
 public:
  RangeValidator(int min, int max);

  std::string PrintError() const override;

  bool validate(const T& fieldToValidate) const override;

 private:
  int m_min, m_max;
};

template <class T>
RangeValidator<T>::RangeValidator(int min, int max) : m_min(min), m_max(max) {}

template <class T>
std::string RangeValidator<T>::PrintError() const {
  return "Out of range";
}

/* checks if the field is in the valid range */
template <class T>
bool RangeValidator<T>::validate(const T& fieldToValidate) const {
  return fieldToValidate >= m_min && fieldToValidate <= m_max;
}
