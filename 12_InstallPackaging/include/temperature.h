#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum Unit { UNKNOWN, CELSIUS, KELVIN, FAHRENHEIT };

char *unit_to_string(enum Unit unit);
enum Unit char_to_unit(char unit);
double celsius_to_kelvin(double celsius);
double kelvin_to_celsius(double kelvin);
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_fahrenheit(double celsius);

#endif
