#pragma once
#include <iostream>

class BaseField {
 public:
  virtual void getUserInput() = 0;

  virtual void print(std::ostream &os) = 0;

  virtual bool ValidateField() = 0;

  virtual void innvalidate() = 0;
};