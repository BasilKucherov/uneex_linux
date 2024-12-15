#include "../include/temperature.h"
#include "../include/constants.h"

char *unit_to_string(enum Unit unit) {
  switch (unit) {
  case CELSIUS:
    return "Celsius";
  case KELVIN:
    return "Kelvin";
  case FAHRENHEIT:
    return "Fahrenheit";
  default:
    return "Unknown";
  }
}

enum Unit char_to_unit(char unit) {
  switch (unit) {
  case 'C':
  case 'c':
    return CELSIUS;
  case 'K':
  case 'k':
    return KELVIN;
  case 'F':
  case 'f':
    return FAHRENHEIT;
  default:
    return UNKNOWN;
  }
}

double celsius_to_kelvin(double celsius) {
  return celsius - ABSOLUTE_ZERO_CELSIUS;
}

double kelvin_to_celsius(double kelvin) {
  return kelvin + ABSOLUTE_ZERO_CELSIUS;
}

double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}
