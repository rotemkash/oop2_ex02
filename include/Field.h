#pragma once

#include <iostream>
#include <string>

#include "BaseField.h"
#include "Validator.h"

using std::cin;
using std::cout;
using std::endl;

template <class T>
class Field : public BaseField {
 public:
  void addValidator(Validator<T> *validator);

  Field(std::string str);

  void getUserInput() override;

  void print(std::ostream &os) override;

  bool ValidateField() override;

  T const &getField() const;

  void innvalidate() override;

 private:
  std::string m_txt;
  T m_field;
  Validator<T> *m_validator = nullptr;
  bool m_goValidated = false;
};

/* Constructor */
template <class T>
Field<T>::Field(std::string str) : m_txt(str) {}

/* Add validator for this field */
template <class T>
void Field<T>::addValidator(Validator<T> *validator) {
  m_validator = validator;
}

/* Gets the user input for this field, if the field is invalid */
template <class T>
void Field<T>::getUserInput() {
  if (!m_goValidated) {
    cout << m_txt << endl;
    cin >> m_field;
    m_goValidated = false;
  }
}

/* Prints the field and if there's was an error in it */
template <class T>
void Field<T>::print(std::ostream &os) {
  os << m_txt << " = " << m_field;

  if (!m_validator->validate(m_field)) {
    os << "    (" << m_validator->PrintError() << ")";
  } else {
    m_goValidated = true;
  }

  os << "\n";
}

/* checks if the field is valid and returns the result */
template <class T>
bool Field<T>::ValidateField() {
  m_goValidated = m_validator->validate(m_field);
  return m_goValidated;
}

/* returns the field */
template <class T>
T const &Field<T>::getField() const {
  return m_field;
}

/* makes the field invalid */
template <class T>
inline void Field<T>::innvalidate() {
  m_goValidated = false;
}