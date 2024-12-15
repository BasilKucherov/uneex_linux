#include "../include/temperature.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
  char input[BUFFER_SIZE];
  double value;
  char unit;
  double celsius, kelvin, fahrenheit;

  while (1) {
    printf("Input temperature (e.g., 23.5C, 300K, 98.6F): ");

    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
      if (feof(stdin)) {
        printf("\nExiting...\n");
        break;
      }
      continue;
    }

    input[strcspn(input, "\n")] = 0;

    if (sscanf(input, "%lf%c", &value, &unit) != 2) {
      printf(
          "Invalid input format. Please use number followed by C, K, or F\n");
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
      printf("Invalid input: %c is unknown unit. Please use C, K, or F\n",
             unit);
      continue;
    }

    char *unit_name = unit_to_string(unit_enum);

    if (unit_enum != CELSIUS) {
      printf("%.2f %s is %.2f Celsius\n", value, unit_name, celsius);
    }
    if (unit_enum != KELVIN) {
      printf("%.2f %s is %.2f Kelvins\n", value, unit_name, kelvin);
    }
    if (unit_enum != FAHRENHEIT) {
      printf("%.2f %s is %.2f Fahrenheit\n", value, unit_name, fahrenheit);
    }

    printf("\n");
  }

  return 0;
}