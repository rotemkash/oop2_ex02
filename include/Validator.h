#pragma once

#include <string>

template <class T>
class Validator {
 public:
  virtual std::string PrintError() const = 0;

  virtual bool validate(const T& fieldToValidate) const = 0;
};