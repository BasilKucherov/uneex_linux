#include "../include/temperature.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#include "config.h"

#define BUFFER_SIZE 100
#define _(STRING) gettext(STRING)

int main() {
	setlocale (LC_ALL, "");
	bindtextdomain (PACKAGE, LOCALE_PATH);
	textdomain (PACKAGE);

  char input[BUFFER_SIZE];
  double value;
  char unit;
  double celsius, kelvin, fahrenheit;

  while (1) {
    printf(_("Input temperature (e.g., 23.5C, 300K, 98.6F): "));

    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
      if (feof(stdin)) {
        printf(_("\nExiting...\n"));
        break;
      }
      continue;
    }

    input[strcspn(input, "\n")] = 0;

    if (sscanf(input, "%lf%c", &value, &unit) != 2) {
      printf(_("Invalid input format. Please use number followed by C, K, or F\n"));
      continue;
    }

    enum Unit unit_enum = char_to_unit(unit);

    switch (unit_enum) {
    case CELSIUS:
      celsius = value;
      kelvin = celsius_to_kelvin(celsius);
      fahrenheit = celsius_to_fahrenheit(celsius);
      break;
    case KELVIN:
      kelvin = value;
      celsius = kelvin_to_celsius(kelvin);
      fahrenheit = celsius_to_fahrenheit(celsius);
      break;
    case FAHRENHEIT:
      fahrenheit = value;
      celsius = fahrenheit_to_celsius(fahrenheit);
      kelvin = celsius_to_kelvin(celsius);
      break;
    default:
      printf(_("Invalid input: %c is unknown unit. Please use C, K, or F\n"),
             unit);
      continue;
    }

    char *unit_name = unit_to_string(unit_enum);

    if (unit_enum != CELSIUS) {
      printf(_("%.2f %s is %.2f Celsius\n"), value, unit_name, celsius);
    }
    if (unit_enum != KELVIN) {
      printf(_("%.2f %s is %.2f Kelvins\n"), value, unit_name, kelvin);
    }
    if (unit_enum != FAHRENHEIT) {
      printf(_("%.2f %s is %.2f Fahrenheit\n"), value, unit_name, fahrenheit);
    }
  }

  return 0;
}