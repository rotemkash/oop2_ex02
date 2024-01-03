#include "Form.h"

/*
 * Adds the field to the fields vector
 */
void Form::addField(BaseField* field) { m_fields.push_back(field); }

/*
 * Asks user to fill the invalid fields only
 */
void Form::fillForm() {
  for (int i = 0; i < m_fields.size(); i++) {
    m_fields[i]->getUserInput();
  }
}

int Form::formSize() const { return m_fields.size(); }

/*
 * Prints the answers of the user with error messages if there's any
 */
void Form::printFields(std::ostream& os) const {
  for (int i = 0; i < m_fields.size(); i++) {
    os << "------------------------------------------------------------\n";
    m_fields[i]->print(os);
    os << "------------------------------------------------------------\n";
  }

  for (int i = 0; i < m_formValidator.size(); i++) {
    if (!m_formValidator[i]->ValidateFormPair()) {
      os << m_formValidator[i]->PrintError();
      os << endl;
      break;
    }
  }
}

/*
 * Adds validator to the validators vector
 */
void Form::addValidator(FormValidator* validator) {
  m_formValidator.push_back(validator);
}

/*
 * Goes over the form and checks for the validity of the fields
 */
bool Form::validateForm() {
  bool formIsValid = true;
  for (int i = 0; i < m_fields.size(); i++) {
    if (!m_fields[i]->ValidateField()) {
      formIsValid = false;
    }

    for (int i = 0; i < m_formValidator.size(); i++) {
      if (!m_formValidator[i]->ValidateFormPair()) {
        formIsValid = false;
      }
    }
  }
  return formIsValid;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  form.printFields(os);
  return os;
}
