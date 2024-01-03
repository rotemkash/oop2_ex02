#pragma once

#include "DestinationNames.h"
#include "Field.h"
#include "FlightTimes.h"
#include "FormValidator.h"
#include "ValuesToNames.h"

template <class T1, class T2>
class DestinationToFlightTimeValidator : public FormValidator {
 public:
  DestinationToFlightTimeValidator(T1* val1, T2* val2);

  std::string PrintError() const override;

  bool ValidateFormPair() const override;

 private:
  T1* m_flightDest;
  T2* m_time;
};

template <class T1, class T2>
DestinationToFlightTimeValidator<T1, T2>::DestinationToFlightTimeValidator(
    T1* flight, T2* time)
    : m_flightDest(flight), m_time(time) {}

template <class T1, class T2>
std::string DestinationToFlightTimeValidator<T1, T2>::PrintError() const {
  return "Destination and flight time don't match";
}

/* checks if the destination and flight time match */
template <class T1, class T2>
bool DestinationToFlightTimeValidator<T1, T2>::ValidateFormPair() const {
  int dest = m_flightDest->getField().getValue().getAnswer();
  int time = m_time->getField().getValue().getAnswer();
  bool ret = true;
  if ((dest == 1 || dest == 2) && (time == 3)) {
    ret = false;
  }

  if ((dest == 4 || dest == 5) && time == 1) {
    ret = false;
  }

  if (!ret) {
    m_flightDest->innvalidate();
    m_time->innvalidate();
  }

  return ret;
}
