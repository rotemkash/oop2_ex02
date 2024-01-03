#pragma once

#include <iostream>
#include <vector>

#include "BaseField.h"
#include "Field.h"
#include "FormValidator.h"

class Form {
 public:

  void addField(BaseField *field);

  void fillForm();

  int formSize() const;

  void printFields(std::ostream &os) const;

  void addValidator(FormValidator *validator);

  bool validateForm();

 private:
  std::vector<BaseField *> m_fields;

  std::vector<FormValidator *> m_formValidator;
};

std::ostream &operator<<(std::ostream &os, const Form &form);