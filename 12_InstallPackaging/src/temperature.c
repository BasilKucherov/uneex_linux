/**
 * @file temperature.c
 * @brief Implementation of temperature conversion functions
 * @author Basil Kucherov
 * @date 2024-12-15
 */

#include "../include/temperature.h"
#include "../include/constants.h"

#include <libintl.h>

#define _(STRING) gettext(STRING)

/**
 * @brief Converts a Unit enum to its localized string representation
 * @param unit The temperature unit to convert
 * @return Localized string representation of the temperature unit
 */
char *unit_to_string(enum Unit unit) {
  switch (unit) {
  case CELSIUS:
    return _("Celsius");
  case KELVIN:
    return _("Kelvin");
  case FAHRENHEIT:
    return _("Fahrenheit");
  default:
    return _("Unknown");
  }
}

/**
 * @brief Converts a character to its corresponding Unit enum
 * @param unit Character representing the temperature unit
 * @return Corresponding Unit enum value (UNKNOWN if invalid)
 */
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

/**
 * @brief Converts temperature from Celsius to Kelvin
 * @param celsius Temperature in Celsius
 * @return Temperature in Kelvin
 */
double celsius_to_kelvin(double celsius) {
  return celsius - ABSOLUTE_ZERO_CELSIUS;
}

/**
 * @brief Converts temperature from Kelvin to Celsius
 * @param kelvin Temperature in Kelvin
 * @return Temperature in Celsius
 */
double kelvin_to_celsius(double kelvin) {
  return kelvin + ABSOLUTE_ZERO_CELSIUS;
}

/**
 * @brief Converts temperature from Fahrenheit to Celsius
 * @param fahrenheit Temperature in Fahrenheit
 * @return Temperature in Celsius
 */
double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

/**
 * @brief Converts temperature from Celsius to Fahrenheit
 * @param celsius Temperature in Celsius
 * @return Temperature in Fahrenheit
 */
double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}
