#pragma once

#pragma once

#include "DestinationNames.h"
#include "Field.h"
#include "FormValidator.h"
#include "ValuesToNames.h"
#include "WifiBundle.h"

template <class T1, class T2>
class DestinationToWifiBundleValidator : public FormValidator {
 public:
  DestinationToWifiBundleValidator(T1* val1, T2* val2);

  std::string PrintError() const override;

  bool ValidateFormPair() const override;

 private:
  T1* m_flightDest;
  T2* m_wifi;
};

template <class T1, class T2>
DestinationToWifiBundleValidator<T1, T2>::DestinationToWifiBundleValidator(
    T1* flight, T2* wifi)
    : m_flightDest(flight), m_wifi(wifi) {}

template <class T1, class T2>
std::string DestinationToWifiBundleValidator<T1, T2>::PrintError() const {
  return "Destination and WIFI bundle don't match";
}

/* checks if the destination and wifi buncle match */
template <class T1, class T2>
bool DestinationToWifiBundleValidator<T1, T2>::ValidateFormPair() const {
  int dest = m_flightDest->getField().getValue().getAnswer();
  int wifi = m_wifi->getField().getValue().getAnswer();
  bool ret = true;

  if (dest == 3 && wifi == 2) {
    ret = false;
  }

  if ((dest == 4 || dest == 5) && wifi == 2) {
    ret = false;
  }

  if (!ret) {
    m_flightDest->innvalidate();
    m_wifi->innvalidate();
  }

  return ret;
}
