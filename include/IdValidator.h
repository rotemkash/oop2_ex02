#pragma once

#include "Validator.h"

class IdValidator : public Validator<uint32_t> {
 public:
  std::string PrintError() const override;

  bool validate(const uint32_t& fieldToValidate) const override;

 private:
  int uintLen(uint32_t num) const;
};