#pragma once

#include <cctype>

#include "Validator.h"

class NoDigitValidator : public Validator<std::string> {
 public:
  std::string PrintError() const override;

  bool validate(const std::string& fieldToValidate) const override;
};