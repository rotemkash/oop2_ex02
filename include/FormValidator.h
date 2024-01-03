#pragma once

class FormValidator {
 public:
  virtual std::string PrintError() const = 0;

  virtual bool ValidateFormPair() const = 0;
};
